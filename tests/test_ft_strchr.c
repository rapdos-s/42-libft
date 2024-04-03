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
	char	*return_pointer[2];

	return_pointer[0] = NULL;
	return_pointer[1] = NULL;
	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
	{
		return_pointer[0] = ft_strchr("Hello, 42!", '4');
		return_pointer[1] = ft_strchr("Hello, 42!", '\0');
	}
	else
	{
		printf(FAIL_ALERT "ft_strchr: Fail on const tests\n");
		return (0);
	}
	if (return_pointer[0][0] != '4' || return_pointer[0][1] != '2')
	{
		printf(FAIL_ALERT "ft_strchr: Fail on const tests\n");
		return (0);
	}
	if (return_pointer[1] != NULL)
	{
		printf(FAIL_ALERT "ft_strchr: Fail on const tests\n");
		return (0);
	}
	return (1);
}

static int	not_found_tests(void)
{
	char	*return_pointer;

	return_pointer = "ABC";
	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
		return_pointer = ft_strchr("Hello, 42!", 'Z');
	else
	{
		printf(FAIL_ALERT "ft_strchr: Fail on not found tests\n");
		return (0);
	}
	if (return_pointer != NULL)
	{
		printf(FAIL_ALERT "ft_strchr: Fail on not found tests\n");
		return (0);
	}
	return (1);
}

static int	empty_string_tests(void)
{
	char	*return_pointer;

	return_pointer = "ABC";
	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
		return_pointer = ft_strchr("", '*');
	else
	{
		printf(FAIL_ALERT "ft_strchr: Fail on empty string tests\n");
		return (0);
	}
	if (return_pointer != NULL)
	{
		printf(FAIL_ALERT "ft_strchr: Fail on empty string tests\n");
		return (0);
	}
	return (1);
}

static int	null_pointer_tests(void)
{
	char	*return_pointer;

	return_pointer = "ABC";
	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
		return_pointer = ft_strchr(NULL, '*');
	else
	{
		printf(FAIL_ALERT "ft_strchr: Fail on null pointer tests\n");
		return (0);
	}
	if (return_pointer != NULL)
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
	result += const_tests();
	result += not_found_tests();
	result += empty_string_tests();
	result += null_pointer_tests();
	print_result(result, "ft_strchr");
}
