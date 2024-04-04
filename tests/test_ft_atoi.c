/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:31:10 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:31:10 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	common_numbers_test(void)
{
	if (ft_atoi("123") != 123 || \
		ft_atoi("123abc") != 123 || \
		ft_atoi("abc123") != 0 || \
		ft_atoi("1a2b3c") != 1 || \
		ft_atoi("9999999999") != 1410065407 || \
		ft_atoi("4294967296") != 0 || \
		ft_atoi("-123") != -123 || \
		ft_atoi("-123abc") != -123 || \
		ft_atoi("-abc123") != 0 || \
		ft_atoi("-1a2b3c") != -1 || \
		ft_atoi("- 123") != 0 || \
		ft_atoi("- 123abc") != 0 || \
		ft_atoi("- abc123") != 0 || \
		ft_atoi("- 1a2b3c") != 0 || \
		ft_atoi("- 9999999999") != 0 || \
		ft_atoi("- 4294967296") != 0)
	{
		printf(FAIL_ALERT "ft_atoi: Fail on positive numbers tests\n");
		return (0);
	}
	return (1);
}

static int	zero_numbers_tests(void)
{
	if (ft_atoi("0") != 0 || \
		ft_atoi("-0") != 0 || \
		ft_atoi("- 0") != 0 || \
		ft_atoi("- 0abc") != 0 || \
		ft_atoi("- 0 abc") != 0 || \
		ft_atoi("- abc000") != 0)
	{
		printf(FAIL_ALERT "ft_atoi: Fail on zero tests\n");
		return (0);
	}
	return (1);
}

static int	strange_cases(void)
{
	if (ft_atoi("    00000123456789") != 123456789 || \
		ft_atoi("00000     123456789") != 0 || \
		ft_atoi("123-123") != 123 || \
		ft_atoi("-123-123") != -123 || \
		ft_atoi("--123") != 0 || \
		ft_atoi("++123") != 0 || \
		ft_atoi("-+-123") != 0)
	{
		printf(FAIL_ALERT "ft_atoi: Fail on strange cases tests\n");
		return (0);
	}
	return (1);
}

static int	null_tests(void)
{
	if (ft_atoi(NULL) != 0)
	{
		printf(FAIL_ALERT "ft_atoi: Fail on NULL tests\n");
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
		result += common_numbers_test();
		result += zero_numbers_tests();
		result += strange_cases();
		result += null_tests();
	}
	else
		printf(FAIL_ALERT "ft_atoi: Memory error during test\n");
	print_result(result, "ft_atoi");
}
