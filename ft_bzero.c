/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:52 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/29 17:57:35 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*u_s;

	if (s)
	{
		i = 0;
		u_s = (unsigned char *)s;
		while (i < n)
		{
			u_s[i] = 0;
			i++;
		}
	}
}
