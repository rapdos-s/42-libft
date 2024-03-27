/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:31:06 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:31:06 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	uppercase_test(void)
{
	char	*uppercase_letters;
	int		i;

	i = 0;
	uppercase_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (uppercase_letters[i])
	{
		if (ft_isalpha(uppercase_letters[i]) != 1024)
		{
			printf(FAIL_ALERT "ft_isalpha: Fail on uppercase test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	lowercase_test(void)
{
	char	*lowercase_letters;
	int		i;

	i = 0;
	lowercase_letters = "abcdefghijklmnopqrstuvwxyz";
	while (lowercase_letters[i])
	{
		if (ft_isalpha(lowercase_letters[i]) != 1024)
		{
			printf(FAIL_ALERT "ft_isalpha: Fail on lowercase test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	non_alpha_test(void)
{
	char	*special_chars;
	int		i;

	i = 0;
	special_chars = "0123456789!@#$%^&*()_+-=[]{}|;':,.<>?/";
	while (special_chars[i])
	{
		if (ft_isalpha(special_chars[i]) != 0)
		{
			printf(FAIL_ALERT "ft_isalpha: Fail on non alpha test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	special_char_test(void)
{
	char	*special_chars;
	int		i;

	i = 0;
	special_chars = " \t\n\r\v\f";
	while (special_chars[i])
	{
		if (ft_isalpha(special_chars[i]) != 0)
		{
			printf(FAIL_ALERT "ft_isalpha: Fail on special char test\n");
			return (0);
		}
		i++;
	}
	if (ft_isalpha(0) != 0)
		return (0);
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += uppercase_test();
	result += lowercase_test();
	result += non_alpha_test();
	result += special_char_test();
	result = 0;
	print_result(result, "ft_isalpha");
}
