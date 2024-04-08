/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:36 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:36 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	common_cases_tests(void)
{
	char	**return_value;
	size_t	i;

	return_value = ft_split(" Sir Quackington von  Featherpants XLII ", ' ');
	if (return_value == NULL || \
		test_strcmp(return_value[0], "Sir") == 0 || \
		test_strcmp(return_value[1], "Quackington") == 0 || \
		test_strcmp(return_value[2], "von") == 0 || \
		test_strcmp(return_value[3], "Featherpants") == 0 || \
		test_strcmp(return_value[4], "XLII") == 0 || \
		return_value[5] != NULL)
	{
		printf(FAIL_ALERT "ft_split: Fail on common case tests\n");
		return (0);
	}
	i = 0;
	if (return_value != NULL)
		while(return_value[i])
			free(return_value[i++]);
	free(return_value);
	return (1);
}

static int	empty_strings_and_no_delimiter_tests(void)
{
	char	**return_value[2];
	size_t	i;

	return_value[0] = ft_split("", ' ');
	return_value[1] = ft_split("Hello, 42!", '.');
	if (return_value[0] == NULL || \
		return_value[1] == NULL || \
		test_strcmp(return_value[0][0], "") == 0 || \
		return_value[0][1] != NULL || \
		test_strcmp(return_value[1][0], "Hello, 42!") == 0 || \
		return_value[1][1] != NULL)
	{

		printf("return_value[0] = %p\n", (void*)return_value[0]);
		printf("return_value[1] = %p\n", (void*)return_value[1]);


		printf(FAIL_ALERT \
			"ft_split: Fail on empty strings and no delimiter tests\n");
		return (0);
	}
	i = 0;
	if (return_value[0] != NULL)
		while(return_value[0][i])
			free(return_value[0][i++]);
	free(return_value[0]);
	i = 0;
	if (return_value[1] != NULL)
		while(return_value[1][i])
			free(return_value[1][i++]);
	free(return_value[1]);
	return (1);
}

static int	allocation_fail_tests(void)
{
	void	*ptr;

	set_g_run_original_malloc(FALSE);
	ptr = ft_split(" Sir Quackington von  Featherpants XLII ", ' ');
	set_g_run_original_malloc(TRUE);
	if (ptr != NULL)
	{
		printf(FAIL_ALERT "ft_split: Fail on allocation fail tests\n");
		return (0);
	}
	return (1);
}

static int	null_pointer_tests(void)
{
	char	**return_value;

	return_value = ft_split(NULL, ' ');
	if (return_value != NULL)
	{
		printf(FAIL_ALERT "ft_split: Fail on null pointer tests\n");
		free(return_value);
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
		result += empty_strings_and_no_delimiter_tests();
		result += allocation_fail_tests();
		result += null_pointer_tests();
	}
	else
		printf(FAIL_ALERT "ft_split: Memory error during test\n");
	print_result(result, "ft_split");
}
