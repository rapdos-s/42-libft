/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:31:08 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:31:08 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	common_cases_tests(void)
{
	char	*str;
	int		nmemb;

	nmemb = 10;
	str = ft_calloc(nmemb, sizeof(char));
	while (nmemb >= 0)
	{
		nmemb--;
		if (str == NULL || str[nmemb] != 0)
		{
			printf(FAIL_ALERT "ft_calloc: Fail on common cases tests\n");
			free(str);
			return (0);
		}
	}
	free(str);
	return (1);
}

static int	struct_tests(void)
{
	t_omnitype	*omnivar;
	int			nmemb;

	nmemb = 42;
	omnivar = ft_calloc(nmemb, sizeof(t_omnitype));
	while (nmemb >= 0)
	{
		nmemb--;
		if (omnivar == NULL || \
			omnivar[1].c != '\0' || \
			omnivar[1].ptr != NULL || \
			omnivar[1].arr_i[21] != 0)
		{
			printf(FAIL_ALERT "ft_calloc: Fail on common cases tests\n");
			free(omnivar);
			return (0);
		}
	}
	free(omnivar);
	return (1);
}

static int	zero_values_tests(void)
{
	void	*ptr[3];

	ptr[0] = NULL;
	ptr[1] = NULL;
	ptr[2] = NULL;
	ptr[0] = ft_calloc(0, 42);
	ptr[1] = ft_calloc(42, 0);
	ptr[2] = ft_calloc(0, 0);
	if (ft_calloc(0, 42) != NULL || \
		ft_calloc(42, 0) != NULL || \
		ft_calloc(0, 0) != NULL)
	{
		printf(FAIL_ALERT "ft_calloc: Fail on zero values tests\n");
		return (0);
	}
	free (ptr[0]);
	free (ptr[1]);
	free (ptr[2]);
	return (1);
}

static int	allocation_fail_tests(void)
{
	void	*ptr;

	set_run_original_malloc(FALSE);
	ptr = ft_calloc(21, 42);
	set_run_original_malloc(TRUE);
	if (ptr != NULL)
	{
		printf(FAIL_ALERT "ft_calloc: Fail on allocation fail tests\n");
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
		result += struct_tests();
		result += zero_values_tests();
		result += allocation_fail_tests();
	}
	else
		printf(FAIL_ALERT "ft_calloc: Memory error during test\n");
	print_result(result, "ft_calloc");
}
