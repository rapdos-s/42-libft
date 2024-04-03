/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:16:17 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 20:16:17 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	alphabet_chars_tests(void)
{
	char	*alphabet;
	char	buffer[52];
	int		buffer_fd[2];
	int		i;

	alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (pipe(buffer_fd) == -1)
	{
		printf(ERROR_ALERT "ft_putchar_fd: pipe failed, errno = %d\n", errno);
		return (0);
	}
	i = -1;
	while (alphabet[++i])
		ft_putchar_fd(alphabet[i], buffer_fd[1]);
	read(buffer_fd[0], buffer, sizeof(buffer));
	i = -1;
	while (alphabet[++i])
	{
		if (alphabet[i] != buffer[i])
		{
			printf(FAIL_ALERT "ft_putchar_fd: Fail on alphabet test\n");
			return (0);
		}
	}
	return (1);
}

static int	numbers_chars_tests(void)
{
	char	*numbers;
	char	buffer[10];
	int		buffer_fd[2];
	int		i;

	numbers = "0123456789";
	if (pipe(buffer_fd) == -1)
	{
		printf(ERROR_ALERT "ft_putchar_fd: pipe failed, errno = %d\n", errno);
		return (0);
	}
	i = -1;
	while (numbers[++i])
		ft_putchar_fd(numbers[i], buffer_fd[1]);
	read(buffer_fd[0], buffer, sizeof(buffer));
	i = -1;
	while (numbers[++i])
	{
		if (numbers[i] != buffer[i])
		{
			printf(FAIL_ALERT "ft_putchar_fd: Fail on numbers test\n");
			return (0);
		}
	}
	return (1);
}

static int	special_chars_tests(void)
{
	char	*special_chars;
	char	buffer[45];
	int		buffer_fd[2];
	int		i;

	special_chars = "!@#$%¨&*()_+-={}[]:;.,<>?/|\\\"'`^~°ºª\t\n\v\f\r";
	if (pipe(buffer_fd) == -1)
	{
		printf(ERROR_ALERT "ft_putchar_fd: pipe failed, errno = %d\n", errno);
		return (0);
	}
	i = -1;
	while (special_chars[++i])
		ft_putchar_fd(special_chars[i], buffer_fd[1]);
	read(buffer_fd[0], buffer, sizeof(buffer));
	i = -1;
	while (special_chars[++i])
	{
		if (special_chars[i] != buffer[i])
		{
			printf(FAIL_ALERT "ft_putchar_fd: Fail on special chars test\n");
			return (0);
		}
	}
	return (1);
}

static int	terminate_char_tests(void)
{
	char	buffer[1];
	int		buffer_fd[2];
	ssize_t	nbytes;

	if (pipe(buffer_fd) == -1)
	{
		printf(ERROR_ALERT "ft_putchar_fd: pipe failed, errno = %d\n", errno);
		return (0);
	}
	ft_putchar_fd('\0', buffer_fd[1]);
	nbytes = read(buffer_fd[0], buffer, sizeof(buffer));
	if (nbytes == -1)
	{
		printf(ERROR_ALERT "ft_putchar_fd: read failed, errno = %d\n", errno);
		return (0);
	}
	if (buffer[0] != '\0')
	{
		printf(FAIL_ALERT "ft_putchar_fd: Fail on terminate char test\n");
		return (0);
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += alphabet_chars_tests();
	result += numbers_chars_tests();
	result += special_chars_tests();
	result += terminate_char_tests();
	print_result(result, "ft_putchar_fd");
}
