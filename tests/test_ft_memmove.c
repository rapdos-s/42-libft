/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:46 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:46 by rapdos-s         ###   ########.fr       */
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
	return_value = ft_memmove(dest, src, 42);
	if (return_value != dest)
	{
		printf(FAIL_ALERT "ft_memmove: Fail on return value tests\n");
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
	ft_memmove(ptr + 1, ptr, 25);
	ft_memmove(ptr, ptr + 1, 25);
	i = 0;
	while (i < 24)
	{
		if (ptr[i] != 'A' + i)
		{
			printf(FAIL_ALERT "ft_memmove: Fail on overlap tests\n");
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
	int		i;

	src = "Hello, World!";
	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
		ft_memmove(dest, src, 14);
	else
	{
		printf(FAIL_ALERT "ft_memmove: Fail on constant tests\n");
		return (0);
	}
	i = 0;
	while (dest[i])
	{
		if (dest[i] != src[i])
		{
			printf(FAIL_ALERT "ft_memmove: Fail on constant tests\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	null_pointer_tests(void)
{
	char	dest[42];
	char	src[42];
	void	*return_value;

	return_value = &return_value;
	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
		return_value = ft_memmove(NULL, NULL, 42);
	else
	{
		printf(FAIL_ALERT "ft_memmove: Fail on null pointer tests\n");
		return (0);
	}
	if (return_value != NULL)
	{
		printf(FAIL_ALERT "ft_memmove: Fail on null pointer tests\n");
		return (0);
	}
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
	print_result(result, "ft_memmove");
}
