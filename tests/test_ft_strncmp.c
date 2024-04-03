/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:27 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:27 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	common_cases_tests(void)
{
	if (ft_strncmp("ABC", "ABC", 3) != 0 || \
		ft_strncmp("CBC", "ABC", 3) != 2 || \
		ft_strncmp("ABC", "CBC", 3) != -2 || \
		ft_strncmp("A", "ABC", 3) != -66 || \
		ft_strncmp("ABC", "A", 3) != 66)
	{
		printf(FAIL_ALERT "ft_strncmp: Fail on common cases tests\n");
		return (0);
	}
	return (1);
}

static int	empty_tests(void)
{
	if (ft_strncmp("", "ABC", 3) != -65 || \
		ft_strncmp("ABC", "", 3) != 65)
	{
		printf(FAIL_ALERT "ft_strncmp: Fail on empty tests\n");
		return (0);
	}
	return (1);
}

static int	special_tests(void)
{
	if (ft_strncmp("!@#", "ABC", 3) != -32 || \
		ft_strncmp("ABC", "!@#", 3) != 32)
	{
		printf(FAIL_ALERT "ft_strncmp: Fail on special tests\n");
		return (0);
	}
	return (1);
}

static int	null_tests(void)
{
	if (ft_strncmp(NULL, "ABC", 3) != -65 || \
		ft_strncmp("ABC", NULL, 3) != 65 || \
		ft_strncmp(NULL, NULL, 3) != 0)
	{
		printf(FAIL_ALERT "ft_strncmp: Fail on null tests\n");
		return (0);
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += common_cases_tests();
	result += empty_tests();
	result += special_tests();
	result += null_tests();
	print_result(result, "ft_strncmp");
}
