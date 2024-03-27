/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:31:04 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:31:04 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	digits_test(void)
{
	char	*digits;
	int		i;

	i = 0;
	digits = "0123456789";
	while (digits[i])
	{
		if (ft_isdigit(digits[i]) == 0)
		{
			printf(FAIL_ALERT "ft_isdigit: Fail on digits test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	letters_test(void)
{
	char	*letters;
	int		i;

	i = 0;
	letters = "ABCXYZabcxyz";
	while (letters[i])
	{
		if (ft_isdigit(letters[i]) != 0)
		{
			printf(FAIL_ALERT "ft_isdigit: Fail on letters test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	low_ascii_chars_test(void)
{
	int	i;

	i = 0;
	while (i <= 10)
	{
		if (ft_isdigit(i) != 0)
		{
			printf(FAIL_ALERT "ft_isdigit: Fail on low ascii chars test\n");
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
		if (ft_isdigit(special_chars[i]) != 0)
		{
			printf(FAIL_ALERT "ft_isdigit: Fail on special chars test\n");
			return (0);
		}
		i++;
	}
	if (ft_isdigit(0) != 0)
	{
		printf(FAIL_ALERT "ft_isdigit: Fail on special chars test\n");
		return (0);
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += digits_test();
	result += letters_test();
	result += low_ascii_chars_test();
	result += special_char_test();
	result = 0;
	print_result(result, "ft_isdigit");
}
