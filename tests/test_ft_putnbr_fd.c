/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:38 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:38 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	positive_numbers_tests(void)
{
	char	buffer[13];
	int		buffer_fd[2];
	int		i;

	if (pipe(buffer_fd) == -1)
	{
		printf(ERROR_ALERT "ft_putnbr_fd: pipe failed, errno = %d\n", errno);
		return (0);
	}
	ft_putnbr_fd(42, buffer_fd[1]);
	ft_putnbr_fd(2147483647, buffer_fd[1]);
	close(buffer_fd[1]);
	read(buffer_fd[0], buffer, sizeof(buffer));
	i = 0;
	while ("422147483647"[i])
	{
		if (buffer[i] != "422147483647"[i])
		{
			printf(FAIL_ALERT "ft_putnbr_fd: Fail on positive numbers test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	negative_numbers_tests(void)
{
	char	buffer[15];
	int		buffer_fd[2];
	int		i;

	if (pipe(buffer_fd) == -1)
	{
		printf(ERROR_ALERT "ft_putnbr_fd: pipe failed, errno = %d\n", errno);
		return (0);
	}
	ft_putnbr_fd(-42, buffer_fd[1]);
	ft_putnbr_fd(-2147483648, buffer_fd[1]);
	close(buffer_fd[1]);
	read(buffer_fd[0], buffer, sizeof(buffer));
	i = 0;
	while ("-42-2147483648"[i])
	{
		if (buffer[i] != "-42-2147483648"[i])
		{
			printf(FAIL_ALERT "ft_putnbr_fd: Fail on negative numbers test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	number_zero_tests(void)
{
	char	buffer[1];
	int		buffer_fd[2];

	if (pipe(buffer_fd) == -1)
	{
		printf(ERROR_ALERT "ft_putnbr_fd: pipe failed, errno = %d\n", errno);
		return (0);
	}
	buffer[0] = '*';
	ft_putnbr_fd(0, buffer_fd[1]);
	close(buffer_fd[1]);
	read(buffer_fd[0], buffer, sizeof(buffer));
	if (buffer[0] != '0')
	{
		printf(FAIL_ALERT "ft_putnbr_fd: Fail on number zero test\n");
		return (0);
	}
	return (1);
}

static int	ten_multiple_tests(void)
{
	char	buffer[39];
	int		buffer_fd[2];
	int		i;

	if (pipe(buffer_fd) == -1)
	{
		printf(ERROR_ALERT "ft_putnbr_fd: pipe failed, errno = %d\n", errno);
		return (0);
	}
	ft_putnbr_fd(10, buffer_fd[1]);
	ft_putnbr_fd(1000000000, buffer_fd[1]);
	ft_putnbr_fd(-10, buffer_fd[1]);
	ft_putnbr_fd(-1000000000, buffer_fd[1]);
	close(buffer_fd[1]);
	read(buffer_fd[0], buffer, sizeof(buffer));
	i = -1;
	while ("101000000000-10-1000000000"[++i])
	{
		if (buffer[i] != "101000000000-10-1000000000"[i])
		{
			printf(FAIL_ALERT "ft_putnbr_fd: Fail on ten multiple test\n");
			return (0);
		}
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += positive_numbers_tests();
	result += negative_numbers_tests();
	result += number_zero_tests();
	result += ten_multiple_tests();
	print_result(result, "ft_putnbr_fd");
}
