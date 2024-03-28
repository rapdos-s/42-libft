/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:29 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:29 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	empty_string_test(void)
{
	char	*empty_string;

	empty_string = "";
	if (ft_strlen(empty_string) != 0)
	{
		printf(FAIL_ALERT "ft_strlen: Fail on empty strings test\n");
		return (0);
	}
	return (1);
}

static int	simple_strings_tests(void)
{
	char	*str1;
	char	*str2;
	size_t	len1;
	size_t	len2;

	str1 = "Hello, World!";
	str2 = "Hello, 42!";
	len1 = 13;
	len2 = 10;
	if (ft_strlen(str1) != len1)
	{
		printf(FAIL_ALERT "ft_strlen: Fail on simple strings test\n");
		return (0);
	}
	if (ft_strlen(str2) != len2)
	{
		printf(FAIL_ALERT "ft_strlen: Fail on simple strings test\n");
		return (0);
	}
	return (1);
}

static int	special_chars_test(void)
{
	char	*str;
	size_t	len;

	str = "\t\n\v\f\r\0\0\0\0\0\t\n\v\f\r";
	len = 5;
	if (ft_strlen(str) != len)
	{
		printf(FAIL_ALERT "ft_strlen: Fail on special chars test\n");
		return (0);
	}
	return (1);
}

static int	null_strings_tests(void)
{
	size_t	result;

	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
		result = ft_strlen(NULL);
	else
	{
		printf(FAIL_ALERT "ft_strlen: Fail on null strings test\n");
		return (0);
	}
	if (result == 0)
		return (1);
	printf(FAIL_ALERT "ft_strlen: Fail on null strings test\n");
	return (0);
}

int	main(void)
{
	int	result;

	result = 0;
	result += empty_string_test();
	result += simple_strings_tests();
	result += special_chars_test();
	result += null_strings_tests();
	print_result(result, "ft_strlen");
}
