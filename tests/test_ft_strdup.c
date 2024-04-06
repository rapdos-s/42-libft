/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:34 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:34 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	common_cases_tests(void)
{
	char	*str;
	char	*str_source;
	size_t	i;

	str_source = "Hello, 42!";
	str = ft_strdup(str_source);
	i = 0;
	while (str != NULL && str[i] && str_source[i])
	{
		if (str[i] != str_source[i])
		{
			printf(FAIL_ALERT "ft_strdup: Fail on common cases tests\n");
			free(str);
			return (0);
		}
		i++;
	}
	if (str == NULL || str[i] != str_source[i])
	{
		printf(FAIL_ALERT "ft_strdup: Fail on common cases tests\n");
		free(str);
		return (0);
	}
	free(str);
	return (1);
}

static int	empty_string_tests(void)
{
	char	*str;

	str = ft_strdup("");
	if (str == NULL || str[0] != '\0')
	{
		printf(FAIL_ALERT "ft_strdup: Fail on empty strings tests\n");
		return (0);
	}
	free(str);
	return (1);
}

static int	allocation_fail_tests(void)
{
	char	*str;

	set_g_run_original_malloc(FALSE);
	str = ft_strdup("Hello, 42!");
	set_g_run_original_malloc(TRUE);
	if (str != NULL)
	{
		printf(FAIL_ALERT "ft_strdup: Fail on allocation fail tests\n");
		return (0);
	}
	return (1);
}

static int	null_pointer_tests(void)
{
	if (ft_strdup(NULL) != NULL)
	{
		printf(FAIL_ALERT "ft_strdup: Fail on null pointer tests\n");
		return (0);
	}
	return (1);
}

int	main(void)
{
	int	result;

	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
	{
		result = 0;
		result += common_cases_tests();
		result += empty_string_tests();
		result += allocation_fail_tests();
		result += null_pointer_tests();
	}
	else
		printf(FAIL_ALERT "ft_strdup: Memory error during test\n");
	print_result(result, "ft_strdup");
}
