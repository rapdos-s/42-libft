/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:27 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/04/01 20:26:54 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	length;

	if (s == NULL)
		return ;
	length = 0;
	while (s[length] != '\0')
		length++;
	write(fd, s, length);
	write(fd, "\n", 1);
}
