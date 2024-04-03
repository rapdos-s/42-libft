/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:51 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:51 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	common_tests(void)
{
	char	*ptr;

	ptr = "Hello, 42!";
	if (ft_memchr(ptr, '4', 10) != ptr + 7)
	{
		printf(FAIL_ALERT "ft_memchr: Fail on common tests\n");
		return (0);
	}
	return (1);
}

static int	not_found_tests(void)
{
	char	*ptr;

	ptr = "Hello, 42!";
	if (ft_memchr(ptr, 'Z', 10) != NULL)
	{
		printf(FAIL_ALERT "ft_memchr: Fail on not found tests\n");
		return (0);
	}
	return (1);
}

static int	zero_n_tests(void)
{
	char	*ptr;

	ptr = "Hello, 42!";
	if (ft_memchr(ptr, 'H', 0) != NULL)
	{
		printf(FAIL_ALERT "ft_memchr: Fail on zero n tests\n");
		return (0);
	}
	return (1);
}

static int	null_tests(void)
{
	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
	{
		if (ft_memchr(NULL, 'A', 42) != NULL)
		{
			printf(FAIL_ALERT "ft_memchr: Fail on null tests\n");
			return (0);
		}
	}
	else
	{
		printf(FAIL_ALERT "Fail on null tests\n");
		return (0);
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += common_tests();
	result += not_found_tests();
	result += zero_n_tests();
	result += null_tests();
	print_result(result, "ft_memchr");
}
