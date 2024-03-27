/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:31:05 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:31:05 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	common_chars_test(void)
{
	char	*common_chars;
	int		i;

	i = 0;
	common_chars = "012789ABCXYZabcxyz";
	while (common_chars[i])
	{
		if (ft_isascii(common_chars[i]) != FT_ISASCII_RETURN)
			return (0);
		i++;
	}
	return (1);
}

static int	special_chars_test(void)
{
	char	*special_chars;
	int		i;

	i = 0;
	special_chars = " \t\n\r\v\f";
	while (special_chars[i])
	{
		if (ft_isascii(special_chars[i]) != FT_ISASCII_RETURN)
			return (0);
		i++;
	}
	return (1);
}

static int	low_ascii_test(void)
{
	int		i;

	i = 0;
	while (i < 32)
	{
		if (ft_isascii(i) != FT_ISASCII_RETURN)
			return (0);
		i++;
	}
	return (1);
}

static int	negative_chars_test(void)
{
	int		i;

	i = -100;
	while (i < 0)
	{
		if (ft_isascii(i) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += common_chars_test();
	result += special_chars_test();
	result += low_ascii_test();
	result += negative_chars_test();
	result = 0;
	print_result(result, "ft_isascii");
}
