/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:35 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:35 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	const_tests(void)
{
	if (ft_strchr("Hello, 42!", 'l') == NULL || \
		ft_strchr("Hello, 42!", 'l')[0] != 'l' || \
		ft_strchr("Hello, 42!", 'l')[2] != 'o' || \
		ft_strchr("Hello, 42!", '\0') == NULL || \
		ft_strchr("Hello, 42!", '\0')[0] != '\0')
	{
		printf(FAIL_ALERT "ft_strchr: Fail on const tests\n");
		return (0);
	}
	return (1);
}

static int	not_found_tests(void)
{
	if (ft_strchr("Hello, 42!", 'Z') != NULL)
	{
		printf(FAIL_ALERT "ft_strchr: Fail on not found tests\n");
		return (0);
	}
	return (1);
}

static int	empty_string_tests(void)
{
	if (ft_strchr("", '*') != NULL)
	{
		printf(FAIL_ALERT "ft_strchr: Fail on empty string tests\n");
		return (0);
	}
	return (1);
}

static int	null_pointer_tests(void)
{
	if (ft_strchr(NULL, '*'))
	{
		printf(FAIL_ALERT "ft_strchr: Fail on null pointer tests\n");
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
		result += const_tests();
		result += not_found_tests();
		result += empty_string_tests();
		result += null_pointer_tests();
	}
	else
		printf(FAIL_ALERT "ft_strchr: Memory error during test\n");
	print_result(result, "ft_strchr");
}
