/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:11 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:11 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

jmp_buf			g_jmp_buffer;
static int		g_run_original_malloc = TRUE;
static size_t	g_alloc_size_request = 0;

void	print_result(int passed, const char *test_name)
{
	char	*color;

	if (passed < 0)
		passed = 0;
	if (passed == 4)
		color = FT_GREEN;
	else
		color = FT_YELLOW;
	if (passed > 4)
		printf ("%s[ %d / ? ]%s %s\n", color, passed, FT_RESET, test_name);
	else
		printf ("%s[ %d/4 ]%s %s\n", color, passed, FT_RESET, test_name);
}

void	sigsegv_handler(int signum)
{
	if (signum == SIGSEGV)
		printf(ERROR_ALERT FT_RED "Segmentation fault detected\n" FT_RESET);
	longjmp(g_jmp_buffer, 1);
}

void	set_g_run_original_malloc(int value)
{
	if (value == 0)
		g_run_original_malloc = FALSE;
	else
		g_run_original_malloc = TRUE;
}

void	reset_g_alloc_size_request(void)
{
	g_alloc_size_request = 0;
}

size_t	get_g_alloc_size_request(void)
{
	return (g_alloc_size_request);
}

void	*malloc(size_t size)
{
	void	*(*original_malloc)(size_t);

	g_alloc_size_request += size;
	original_malloc = (void *(*)(size_t))dlsym(RTLD_NEXT, "malloc");
	if (g_run_original_malloc == TRUE)
		return (original_malloc(size));
	return (NULL);
}

int	test_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return(1);
	return(0);
}
