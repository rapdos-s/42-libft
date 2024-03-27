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

static int	fill_test(void)
{
	char	str[42];
	int		i;

	i = 0;
	ft_memset(str, 'A', 42);
	str[41] = 0;
	while (str[i])
	{
		if (str[i] != 'A')
			return (0);
		i++;
	}
	return (1);
}

static int	bzero_test(void)
{
	char	str[42];
	int		i;

	i = 0;
	ft_memset(str, 0, 42);
	while (i < 42)
	{
		if (str[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	return_test(void)
{
	char	str1[1];
	char	str2[2];
	char	str3[3];
	char	str4[4];
	char	str5[5];

	if (ft_memset(str1, 'Q', 1) != str1)
		return (0);
	if (ft_memset(str2, 'U', 1) != str2)
		return (0);
	if (ft_memset(str3, 'A', 0) != str3)
		return (0);
	if (ft_memset(str4, 'C', 4) != str4)
		return (0);
	if (ft_memset(str5, 'K', 2) != str5)
		return (0);
	return (1);
}

static int	null_pointer_tests(void)
{
	void	*return_value;

	return_value = &return_value;
	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
		return_value = ft_memset(NULL, '*', 42);
	else
		return (0);
	if (return_value == NULL)
		return (1);
	return (0);
}

int	main(void)
{
	int	result;

	result = 0;
	result += fill_test();
	result += bzero_test();
	result += return_test();
	result += null_pointer_tests();
	result = 0;
	print_result(result, "ft_memset");
}
