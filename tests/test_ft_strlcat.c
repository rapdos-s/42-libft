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
		result += null_pointer_tests();
	}
	else
		printf(FAIL_ALERT "ft_strlcat: Memory error during test\n");
	print_result(result, "ft_strlcat");
}
