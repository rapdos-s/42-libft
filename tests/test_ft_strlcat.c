/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:31 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:31 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	common_cases_tests(void)
{
	char	dest[42];

	dest[0] = 0;
	if (ft_strlcat(dest, "Hello, 42!", 42) != 10 || \
		dest[0] != 'H' || \
		dest[1] != 'e' || \
		dest[2] != 'l' || \
		dest[3] != 'l' || \
		dest[4] != 'o' || \
		dest[5] != ',' || \
		dest[6] != ' ' || \
		dest[7] != '4' || \
		dest[8] != '2' || \
		dest[9] != '!' || \
		dest[10] != '\0')
	{
		printf(FAIL_ALERT "ft_strlcat: Fail on common case test\n");
		return (0);
	}
	return (1);
}

static int	short_size_tests(void)
{
	char	dest[42];

	dest[0] = 0;
	if (ft_strlcat(dest, "Hello, 42!", 6) != 10 || \
		dest[0] != 'H' || \
		dest[1] != 'e' || \
		dest[2] != 'l' || \
		dest[3] != 'l' || \
		dest[4] != 'o' || \
		dest[5] != '\0')
	{
		printf(FAIL_ALERT "ft_strlcat: Fail on short size test\n");
		return (0);
	}
	return (1);
}

static int	empty_src_string_tests(void)
{
	char	dest[42];

	dest[0] = 0;
	if (ft_strlcat(dest, "", 6) != 0 || dest[0] != '\0')
	{
		printf(FAIL_ALERT "ft_strlcat: Fail on empty source string test\n");
		return (0);
	}
	return (1);
}

static int	null_pointer_tests(void)
{
	char	dest[42];

	if (ft_strlcat(NULL, "Hello, 42!", 42) != 0 || \
		ft_strlcat(dest, NULL, 42) != 0 || \
		ft_strlcat(NULL, NULL, 42) != 0)
	{
		printf(FAIL_ALERT "ft_strlcat: Fail on null pointer test\n");
		return (0);
	}
	return (1);
}

int	main(void)
{
	int	result;

	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(g_jmp_buffer) == 0)
	{
		result = 0;
		result += common_cases_tests();
		result += short_size_tests();
		result += empty_src_string_tests();
		result += null_pointer_tests();
	}
	else
		printf(FAIL_ALERT "ft_strlcat: Memory error during test\n");
	print_result(result, "ft_strlcat");
}
