/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:30 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/30 00:13:21 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*u_dest;
	unsigned char	*u_src;

	if (dest == NULL || src == NULL)
		return (NULL);
	u_dest = (unsigned char *)dest;
	u_src = (unsigned char *)src;
	if (u_dest > u_src)
	{
		i = n;
		while (i-- > 0)
			u_dest[i] = u_src[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			u_dest[i] = u_src[i];
			i++;
		}
	}
	return (dest);
}
