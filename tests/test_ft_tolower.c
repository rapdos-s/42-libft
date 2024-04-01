/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:22 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:22 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	uppercase_tests(void)
{
	char	*lowercase_characters;
	char	*uppercase_characters;
	int		i;

	lowercase_characters = "abcdefghijklmnopqrstuvwxyz";
	uppercase_characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i = 0;
	while (lowercase_characters[i])
	{
		if (ft_tolower(uppercase_characters[i]) != lowercase_characters[i])
		{
			printf(FAIL_ALERT "ft_tolower: Fail on uppercase test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	lowercase_tests(void)
{
	char	*lowercase_characters;
	int		i;

	lowercase_characters = "abcdefghijklmnopqrstuvwxyz";
	i = 0;
	while (lowercase_characters[i])
	{
		if (ft_tolower(lowercase_characters[i]) != lowercase_characters[i])
		{
			printf(FAIL_ALERT "ft_tolower: Fail on lowercase test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	special_char_tests(void)
{
	char	*especial_characters;
	int		i;

	especial_characters = "0123456789!@#$%¨&*()_+-={}[]:;.,<>?/|\\\"'`^~°ºª";
	i = 0;
	while (especial_characters[i])
	{
		if (ft_tolower(especial_characters[i]) != especial_characters[i])
		{
			printf(FAIL_ALERT "ft_tolower: Fail on special char test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	zero_tests(void)
{
	if (ft_tolower(0) != 0)
	{
		printf(FAIL_ALERT "ft_tolower: Fail on zero test\n");
		return (0);
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += uppercase_tests();
	result += lowercase_tests();
	result += special_char_tests();
	result += zero_tests();
	print_result(result, "ft_tolower");
}
