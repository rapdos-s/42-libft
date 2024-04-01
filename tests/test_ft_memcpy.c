/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:48 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:48 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	return_tests(void)
{
	char	src[42];
	char	dest[42];
	void	*return_value;
	int		i;

	return_value = NULL;
	i = 0;
	while (i < 42)
	{
		src[i] = i;
		i++;
	}
	return_value = ft_memcpy(dest, src, 42);
	if (return_value != dest)
	{
		printf(FAIL_ALERT "ft_memcpy: Fail on return value tests\n");
		return (0);
	}
	return (1);
}

static int	overlap_tests(void)
{
	char	ptr[26];
	int		i;

	i = 0;
	while (i < 26)
	{
		ptr[i] = 'A' + i;
		i++;
	}
	ft_memcpy(ptr, ptr + 1, 25);
	i = 0;
	while (i < 24)
	{
		if (ptr[i] != 'A' + i + 1)
		{
			printf(FAIL_ALERT "ft_memcpy: Fail on overlap tests\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	constant_tests(void)
{
	char	dest[42];
	char	*src;
	void	*return_value;
	int		i;

	src = "Hello, World!";
	return_value = NULL;
	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
		return_value = ft_memcpy(dest, src, 14);
	else
		return (0);
	if (return_value != dest)
		return (0);
	i = 0;
	while (dest[i])
	{
		if (dest[i] != src[i])
			return (0);
		i++;
	}
	return (1);
}

static int	null_pointer_tests(void)
{
	char	dest[42];
	char	src[42];
	void	*return_value;

	signal(SIGSEGV, sigsegv_handler);
	return_value = &return_value;
	if (setjmp(g_jmp_buffer) == 0)
		return_value = ft_memcpy(NULL, src, 42);
	else
		return (0);
	if (return_value != NULL)
		return (0);
	return_value = &return_value;
	if (setjmp(g_jmp_buffer) == 0)
		return_value = ft_memcpy(dest, NULL, 42);
	else
		return (0);
	if (return_value != NULL)
		return (0);
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += return_tests();
	result += overlap_tests();
	result += constant_tests();
	result += null_pointer_tests();
	print_result(result, "ft_memcpy");
}
