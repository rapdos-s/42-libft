/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:32 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:32 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	common_cases_tests(void)
{
	char	*return_value;

	return_value = ft_strjoin("12", "34");
	if (return_value == NULL || \
		return_value[0] != '1' || \
		return_value[1] != '2' || \
		return_value[2] != '3' || \
		return_value[3] != '4' || \
		return_value[4] != '\0')
	{
		printf(FAIL_ALERT "ft_strjoin: Fail on common cases tests\n");
		free(return_value);
		return (0);
	}
	free(return_value);
	return (1);
}

static int	empty_strings_tests(void)
{
	char	*return_value[3];

	return_value[0] = ft_strjoin("", "34");
	return_value[1] = ft_strjoin("12", "");
	return_value[2] = ft_strjoin("", "");
	if (return_value[0] == NULL || \
		return_value[1] == NULL || \
		return_value[2] != NULL || \
		return_value[0][0] != '3' || \
		return_value[0][1] != '4' || \
		return_value[0][2] != '\0' || \
		return_value[1][0] != '1' || \
		return_value[1][1] != '2' || \
		return_value[1][2] != '\0')
	{
		printf(FAIL_ALERT "ft_strjoin: Fail on empty strings tests\n");
		free(return_value[0]);
		free(return_value[1]);
		free(return_value[2]);
		return (0);
	}
	free(return_value[0]);
	free(return_value[1]);
	free(return_value[2]);
	return (1);
}

static int	allocation_fail_tests(void)
{
	void	*ptr;

	set_g_run_original_malloc(FALSE);
	ptr = ft_strjoin("21", "42");
	set_g_run_original_malloc(TRUE);
	if (ptr != NULL)
	{
		printf(FAIL_ALERT "ft_strjoin: Fail on allocation fail tests\n");
		return (0);
	}
	return (1);
}

static int	null_pointer_tests(void)
{
	char	*return_value[3];

	return_value[0] = ft_strjoin(NULL, "34");
	return_value[1] = ft_strjoin("12", NULL);
	return_value[2] = ft_strjoin(NULL, NULL);
	if (return_value[0] == NULL || \
		return_value[1] == NULL || \
		return_value[2] != NULL || \
		return_value[0][0] != '3' || \
		return_value[0][1] != '4' || \
		return_value[0][2] != '\0' || \
		return_value[1][0] != '1' || \
		return_value[1][1] != '2' || \
		return_value[1][2] != '\0')
	{
		printf(FAIL_ALERT "ft_strjoin: Fail on null pointer tests\n");
		free(return_value[0]);
		free(return_value[1]);
		free(return_value[2]);
		return (0);
	}
	free(return_value[0]);
	free(return_value[1]);
	free(return_value[2]);
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
		result += empty_strings_tests();
		result += allocation_fail_tests();
		result += null_pointer_tests();
	}
	else
		printf(FAIL_ALERT "ft_strjoin: Memory error during test\n");
	print_result(result, "ft_strjoin");
}
