/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:37 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:37 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int	basic_string_tests(void)
{
	char	buffer[10];
	int		buffer_fd[2];
	int		i;

	if (pipe(buffer_fd) == -1)
	{
		printf(ERROR_ALERT "ft_putstr_fd: pipe failed, errno = %d\n", errno);
		return (0);
	}
	ft_putstr_fd("Hello, 42!", buffer_fd[1]);
	close(buffer_fd[1]);
	read(buffer_fd[0], buffer, sizeof(buffer));
	i = 0;
	while ("Hello, 42!"[i])
	{
		if (buffer[i] != "Hello, 42!"[i])
		{
			printf(FAIL_ALERT "ft_putstr_fd: Fail on basic string test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	empty_string_tests(void)
{
	char	buffer[1];
	int		buffer_fd[2];
	ssize_t	nbytes;

	if (pipe(buffer_fd) == -1)
	{
		printf(ERROR_ALERT "ft_putstr_fd: pipe failed, errno = %d\n", errno);
		return (0);
	}
	buffer[0] = '*';
	ft_putstr_fd("", buffer_fd[1]);
	close(buffer_fd[1]);
	nbytes = read(buffer_fd[0], buffer, sizeof(buffer));
	if (nbytes == -1)
	{
		printf(ERROR_ALERT "ft_putstr_fd: read failed, errno = %d\n", errno);
		return (0);
	}
	if (buffer[0] != '*')
	{
		printf(FAIL_ALERT "ft_putstr_fd: Fail on empty string test\n");
		return (0);
	}
	return (1);
}

static int	special_char_tests(void)
{
	char	buffer[41];
	int		buffer_fd[2];
	int		i;

	if (pipe(buffer_fd) == -1)
	{
		printf(ERROR_ALERT "ft_putstr_fd: pipe failed, errno = %d\n", errno);
		return (0);
	}
	ft_putstr_fd("!@#$%¨&*()_+-={}[]:;.,<>?/|\\\"'`^~°ºª", buffer_fd[1]);
	close(buffer_fd[1]);
	read(buffer_fd[0], buffer, sizeof(buffer));
	i = 0;
	while ("!@#$%¨&*()_+-={}[]:;.,<>?/|\\\"'`^~°ºª"[i])
	{
		if (buffer[i] != "!@#$%¨&*()_+-={}[]:;.,<>?/|\\\"'`^~°ºª"[i])
		{
			printf(FAIL_ALERT "ft_putstr_fd: Fail on special char test\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	null_pointer_tests(void)
{
	char	buffer[1];
	int		buffer_fd[2];
	ssize_t	nbytes;

	if (pipe(buffer_fd) == -1)
	{
		printf(ERROR_ALERT "ft_putstr_fd: pipe failed, errno = %d\n", errno);
		return (0);
	}
	buffer[0] = '*';
	ft_putstr_fd(NULL, buffer_fd[1]);
	close(buffer_fd[1]);
	nbytes = read(buffer_fd[0], buffer, sizeof(buffer));
	if (nbytes == -1)
	{
		printf(ERROR_ALERT "ft_putstr_fd: read failed, errno = %d\n", errno);
		return (0);
	}
	if (buffer[0] != '*')
	{
		printf(FAIL_ALERT "ft_putstr_fd: Fail on null pointer test\n");
		return (0);
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += basic_string_tests();
	result += empty_string_tests();
	result += special_char_tests();
	result += null_pointer_tests();
	print_result(result, "ft_putstr_fd");
}
