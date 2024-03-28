/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:31:07 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:31:07 by rapdos-s         ###   ########.fr       */
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
		if (ft_isalnum(uppercase_letters[i]) != FT_ISALPHA_RETURN)
		{
			printf(FAIL_ALERT "ft_isalnum: Fail on uppercase chars test\n");
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
		if (ft_isalnum(lowercase_letters[i]) != FT_ISALPHA_RETURN)
		{
			printf(FAIL_ALERT "ft_isalnum: Fail on lowercase chars test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	digits_test(void)
{
	char	*digits;
	int		i;

	i = 0;
	digits = "0123456789";
	while (digits[i])
	{
		if (ft_isalnum(digits[i]) != FT_ISALPHA_RETURN)
		{
			printf(FAIL_ALERT "ft_isalnum: Fail on digit chars test\n");
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
		if (ft_isalnum(special_chars[i]) != 0)
		{
			printf(FAIL_ALERT "ft_isalnum: Fail on special chars test\n");
			return (0);
		}
		i++;
	}
	if (ft_isalnum(0) != 0)
		return (0);
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += uppercase_test();
	result += lowercase_test();
	result += digits_test();
	result += special_char_test();
	print_result(result, "ft_isalnum");
}
