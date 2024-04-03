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

jmp_buf	g_jmp_buffer;

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
	(void) signum;
	printf(ERROR_ALERT FT_RED "Segmentation fault detected\n" FT_RESET);
	longjmp(g_jmp_buffer, 1);
}
