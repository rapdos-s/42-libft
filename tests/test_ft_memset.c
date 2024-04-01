/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:42 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:42 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	zero_fill_tests(void)
{
	char	buffer[10];
	int		i;

	i = 0;
	ft_memset(buffer, 0, 10);
	while (i < 10)
	{
		if (buffer[i] != 0)
		{
			printf(FAIL_ALERT "ft_memset: Fail on zero fill tests\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	mix_fill_tests(void)
{
	char	buffer[10];
	char	c1;
	char	c2;
	int		i;

	c1 = '4';
	c2 = '2';
	i = 0;
	ft_memset(buffer, c1, 5);
	ft_memset(buffer + 5, c2, 5);
	while (i < 5)
	{
		if (buffer[i] != c1)
		{
			printf(FAIL_ALERT "ft_memset: Fail on mix fill tests\n");
			return (0);
		}
		if (buffer[i + 5] != c2)
		{
			printf(FAIL_ALERT "ft_memset: Fail on zero fill tests\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	return_tests(void)
{
	char	buffer[10];
	char	*ret;

	ret = ft_memset(buffer, 0, 10);
	if (ret != buffer)
	{
		printf(FAIL_ALERT "ft_memset: Fail on return tests\n");
		return (0);
	}
	return (1);
}

static int	null_pointer_tests(void)
{
	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
		ft_memset(NULL, 42, 21);
	else
	{
		printf(FAIL_ALERT "ft_memset: Fail on null pointer tests\n");
		return (0);
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += zero_fill_tests();
	result += mix_fill_tests();
	result += return_tests();
	result += null_pointer_tests();
	print_result(result, "ft_memset");
}
