/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:31:03 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:31:03 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	printable_chars_test(void)
{
	char	*printable_chars;
	int		i;

	i = 0;
	printable_chars = "012789ABCXYZabcxyz./ ";
	while (printable_chars[i])
	{
		if (ft_isprint(printable_chars[i]) != FT_ISPRINT_RETURN)
			return (0);
		i++;
	}
	return (1);
}

static int	control_chars_test(void)
{
	char	*control_chars;
	int		i;

	i = 0;
	control_chars = "\t\n\r\v\f";
	while (control_chars[i])
	{
		if (ft_isprint(control_chars[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	non_printable_chars_test(void)
{
	int		i;

	i = 0;
	while (i < 32)
	{
		if (ft_isprint(i) != 0)
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
		if (ft_isprint(i) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += printable_chars_test();
	result += control_chars_test();
	result += non_printable_chars_test();
	result += negative_chars_test();
	result = 0;
	print_result(result, "ft_isprint");
}
