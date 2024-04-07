/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:23 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:23 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	common_cases_tests(void)
{
	char	*return_value;

	return_value = ft_substr("1234567890", 4, 2);
	if (return_value == NULL || \
		return_value[0] != '5' || \
		return_value[1] != '6' || \
		return_value[2] != '\0')
	{
		printf(FAIL_ALERT "ft_substr: Fail on common cases tests\n");
		free(return_value);
		return (0);
	}
	free(return_value);
	return (1);
}

static int	small_values_tests(void)
{
	char	*return_value[2];

	return_value[0] = ft_substr("1234567890", 5, 0);
	return_value[1] = ft_substr("1234567890", 0, 2);
	if (return_value[0] != NULL || \
		return_value[1] == NULL || \
		return_value[1][0] != '1' || \
		return_value[1][1] != '2' || \
		return_value[1][2] != '\0')
	{
		printf(FAIL_ALERT "ft_substr: Fail on small values tests\n");
		free(return_value[0]);
		free(return_value[1]);
		return (0);
	}
	free(return_value[0]);
	free(return_value[1]);
	return (1);
}

static int	big_values_tests(void)
{
	char	*return_value[2];

	return_value[0] = ft_substr("1234567890", 42, 0);
	return_value[1] = ft_substr("12", 0, 42);
	if (return_value[0] != NULL || \
		return_value[1] == NULL || \
		return_value[1][0] != '1' || \
		return_value[1][1] != '2' || \
		return_value[1][2] != '\0')
	{
		printf(FAIL_ALERT "ft_substr: Fail on big values tests\n");
		free(return_value[0]);
		free(return_value[1]);
		return (0);
	}
	free(return_value[0]);
	free(return_value[1]);
	return (1);
}

static int	null_pointer_tests(void)
{
	char	*return_value;

	return_value = ft_substr(NULL, 4, 2);
	if (return_value != NULL)
	{
		printf(FAIL_ALERT "ft_substr: Fail on null pointer tests\n");
		free(return_value);
		return (0);
	}
	free(return_value);
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
		result += small_values_tests();
		result += big_values_tests();
		result += null_pointer_tests();
	}
	else
		printf(FAIL_ALERT "ft_substr: Memory error during test\n");
	print_result(result, "ft_substr");
}
