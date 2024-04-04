/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:50 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:50 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	common_cases_tests(void)
{
	if (ft_memcmp("ABC", "ABC", 3) != 0 || \
		ft_memcmp("ABC", "123", 3) != 1 || \
		ft_memcmp("123", "ABC", 3) != -1)
	{
		printf(FAIL_ALERT "ft_memcmp: Fail on common cases tests\n");
		return (0);
	}
	return (1);
}

static int	short_size_tests(void)
{
	if (ft_memcmp("ABC", "AB", 2) != 0 || \
		ft_memcmp("AB", "ABC", 2) != 0 || \
		ft_memcmp("ABC", "AB", 0) != 0 || \
		ft_memcmp("AB", "ABC", 0) != 0)
	{
		printf(FAIL_ALERT "ft_memcmp: Fail on short size tests\n");
		printf("ft_memcmp(\"ABC\", \"AB\", 2) == %d\n", ft_memcmp("ABC", "AB", 2));
		printf("ft_memcmp(\"AB\", \"ABC\", 2) == %d\n", ft_memcmp("AB", "ABC", 2));
		printf("ft_memcmp(\"ABC\", \"AB\", 0) == %d\n", ft_memcmp("ABC", "AB", 0));
		printf("ft_memcmp(\"AB\", \"ABC\", 0) == %d\n", ft_memcmp("AB", "ABC", 0));
		return (0);
	}
	return (1);
}

static int	empty_string_tests(void)
{
	if (ft_memcmp("", "", 1) != 0 || \
		ft_memcmp("", "ABC", 3) != -65 || \
		ft_memcmp("ABC", "", 3) != 65)
	{
		printf(FAIL_ALERT "ft_memcmp: Fail on empty string tests\n");
		return (0);
	}
	return (1);
}

static int	null_tests(void)
{
	if (ft_memcmp(NULL, "ABC", 10) != -65 || \
		ft_memcmp("ABC", NULL, 10) != 65 || \
		ft_memcmp(NULL, NULL, 10) != 0)
	{
		printf(FAIL_ALERT "ft_memcmp: Fail on NULL tests\n");
		return (0);
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += common_cases_tests();
	result += short_size_tests();
	result += empty_string_tests();
	result += null_tests();
	print_result(result, "ft_memcmp");
}
