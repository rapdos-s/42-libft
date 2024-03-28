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
	int		i;

	i = 32;
	while (i <= 126)
	{
		if (ft_isprint(i) != FT_ISPRINT_RETURN)
		{
			printf(FAIL_ALERT "ft_isprint: Fail on printable chars test\n");
			return (0);
		}
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
		{
			printf(FAIL_ALERT "ft_isprint: Fail on control chars test\n");
			return (0);
		}
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
		{
			printf(FAIL_ALERT "ft_isprint: Fail on non printable chars test\n");
			return (0);
		}
		i++;
	}
	i = 127;
	while (i < 256)
	{
		if (ft_isprint(i) != 0)
		{
			printf(FAIL_ALERT "ft_isprint: Fail on non printable chars test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	negative_chars_test(void)
{
	int		i;

	i = -128;
	while (i < 0)
	{
		if (ft_isprint(i) != 0)
		{
			printf(FAIL_ALERT "ft_isprint: Fail on negative chars test\n");
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
	result += printable_chars_test();
	result += control_chars_test();
	result += non_printable_chars_test();
	result += negative_chars_test();
	print_result(result, "ft_isprint");
}
