/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:30 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:30 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	copy_tests(void)
{
	char	dest[10];
	char	src[10];
	size_t	i;

	i = 0;
	while (i < 9)
	{
		src[i] = 'A' + i;
		dest[i] = '0' + i;
		i++;
	}
	src[i] = '\0';
	dest[i] = '\0';
	ft_strlcpy(dest, src, 10);
	i = 0;
	while (i < 10)
	{
		if (dest[i] != src[i])
		{
			printf(FAIL_ALERT "ft_strlcpy: Fail on copy tests\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	empty_tests(void)
{
	char	dest[10];
	int		i;
	size_t	return_value;

	i = -1;
	while (++i < 10)
		dest[i] = 'A' + i;
	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
	{
		return_value = ft_strlcpy(dest, "", 10);
		if (return_value != 1 || dest[0] != '\0')
		{
			printf(FAIL_ALERT "ft_strlcpy: Fail on empty tests\n");
			return (0);
		}
	}
	else
	{
		printf(FAIL_ALERT "ft_strlcpy: Fail on empty tests\n");
		return (0);
	}
	return (1);
}

static int	return_tests(void)
{
	size_t	return_value[3];
	char	dest[42];

	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
	{
		return_value[0] = ft_strlcpy(dest, "42", 0);
		return_value[1] = ft_strlcpy(dest, "Hello, 42!", 42);
		return_value[2] = ft_strlcpy(dest, "Hello, 42!", 5);
		if (return_value[0] != 2 || \
			return_value[1] != 11 || return_value[2] != 11)
		{
			printf(FAIL_ALERT "ft_strlcpy: Fail on return value tests\n");
			return (0);
		}
	}
	else
	{
		printf(FAIL_ALERT "ft_strlcpy: Fail on return value tests\n");
		return (0);
	}
	return (1);
}

static int	null_pointer_tests(void)
{
	char	dest[42];

	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
		ft_strlcpy(NULL, NULL, 42);
	else
	{
		printf(FAIL_ALERT "ft_strlcpy: Fail on null pointer test\n");
		return (0);
	}
	dest[0] = 'A';
	ft_strlcpy(dest, NULL, 42);
	if (dest[0] != '\0')
	{
		printf(FAIL_ALERT "ft_strlcpy: Fail on null pointer test\n");
		return (0);
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += copy_tests();
	result += empty_tests();
	result += return_tests();
	result += null_pointer_tests();
	print_result(result, "ft_strlcpy");
	return (0);
}
