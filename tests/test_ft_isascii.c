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

static int	ascii_chars_test(void)
{
	int		i;

	i = 0;
	while (i <= 127)
	{
		if (ft_isascii(i) != FT_ISASCII_RETURN)
		{
			printf(FAIL_ALERT "ft_isascii: Fail on ascii chars test\n");
			return (0);
		}
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
		{
			printf(FAIL_ALERT "ft_isascii: Fail on special chars test\n");
			return (0);
		}
		i++;
	}
	if (ft_isascii(0) != FT_ISASCII_RETURN)
	{
		printf(FAIL_ALERT "ft_isascii: Fail on special chars test\n");
		return (0);
	}
	return (1);
}

static int	non_ascii_chars_test(void)
{
	int		i;

	i = 128;
	while (i < 255)
	{
		if (ft_isascii(i) != 0)
		{
			printf(FAIL_ALERT "ft_isascii: Fail on non ascii chars test\n");
			return (0);
		}
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
		{
			printf(FAIL_ALERT "ft_isascii: Fail on negative chars test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += ascii_chars_test();
	result += special_chars_test();
	result += non_ascii_chars_test();
	result += negative_chars_test();
	print_result(result, "ft_isascii");
}
