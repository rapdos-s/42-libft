/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:31:09 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:31:09 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	half_fill_tests(void)
{
	char	str[42];
	int		i;

	i = 0;
	while(i < 42)
	{
		str[i] = '*';
		i++;
	}
	ft_bzero(str, 21);
	while (i < 21)
	{
		if (str[i] != 0 || str[i + 21] != '*')
		{
			printf(FAIL_ALERT "ft_bzero: Fail on half_fill tests\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	full_fill_tests(void)
{
	char	str[42];
	int		i;

	i = 0;
	ft_bzero(str, 42);
	while (i < 42)
	{
		if (str[i] != 0)
		{
			printf(FAIL_ALERT "ft_bzero: Fail on full_fill tests\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	struct_fill_tests(void)
{
	t_bzero_test	test;

	test.a = 42;
	test.b = '*';
	ft_bzero(&test, sizeof(t_bzero_test));
	if (test.a != 0 || test.b != 0)
	{
		printf(FAIL_ALERT "ft_bzero: Fail on struct_fill tests\n");
		return (0);
	}
	return (1);
}

static int	null_pointer_tests(void)
{
	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
		ft_bzero(NULL, 42);
	else
	{
		printf(FAIL_ALERT "ft_bzero: Fail on null pointer tests\n");
		return (0);
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += half_fill_tests();
	result += full_fill_tests();
	result += struct_fill_tests();
	result += null_pointer_tests();
	print_result(result, "ft_bzero");
}
