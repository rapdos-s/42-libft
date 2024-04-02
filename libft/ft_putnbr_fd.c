/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:26 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/04/01 21:14:21 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[11];
	int		i;
	long	ln;

	if (n == 0)
		write(fd, "0", 1);
	else
	{
		i = 11;
		ln = n;
		if (ln < 0)
		{
			write(fd, "-", 1);
			ln = -ln;
		}
		while (ln != 0)
		{
			i--;
			buffer[i] = ln % 10 + '0';
			ln = ln / 10;
		}
	}
	write(fd, buffer + i, 11 - i);
}
