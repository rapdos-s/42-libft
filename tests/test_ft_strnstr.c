/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:26 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:26 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	common_cases_tests(void)
{
	char	*big;

	big = "Hello, 42!";
	if (ft_strnstr(big, "42", 21) != big + 7 || \
		ft_strnstr(big, "43", 21) != NULL || \
		ft_strnstr(big, "42", 2) != NULL)
	{
		printf(FAIL_ALERT "ft_strnstr: Fail on common cases tests\n");
		return (0);
	}
	return (1);
}

static int	empty_strings_tests(void)
{
	char	*big;

	big = "Hello, 42!";
	if (ft_strnstr(big, "", 42) != big || \
		ft_strnstr("", "42", 42) != NULL)
	{
		printf(FAIL_ALERT "ft_strnstr: Fail on empty strings tests\n");
		return (0);
	}
	return (1);
}

static int	terminator_character_tests(void)
{
	char	big[3];
	char	little[3];

	big[0] = '4';
	big[1] = '\0';
	big[2] = '2';
	little[0] = '4';
	little[1] = '\0';
	little[2] = '3';
	if (ft_strnstr(big, big + 2, 1) != NULL || \
		ft_strnstr(big, little, 42) != big)
	{
		printf(FAIL_ALERT "ft_strnstr: Fail on terminator character tests\n");
		return (0);
	}
	return (1);
}

static int	null_tests(void)
{
	if (ft_strnstr(NULL, "42", 42) != NULL || \
		ft_strnstr("Hello, 42!", NULL, 42) != NULL || \
		ft_strnstr(NULL, NULL, 42) != NULL)
	{
		printf(FAIL_ALERT "ft_strnstr: Fail on NULL tests\n");
		return (0);
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
	{
		result += common_cases_tests();
		result += empty_strings_tests();
		result += terminator_character_tests();
		result += null_tests();
	}
	else
		printf(FAIL_ALERT "ft_strnstr: Memory error during test\n");
	print_result(result, "ft_strnstr");
}
