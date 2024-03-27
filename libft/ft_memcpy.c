/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:32 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:45:16 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*u_src;
	unsigned char	*u_dest;
	size_t			i;

	if (dest == NULL || src == NULL)
		return (NULL);
	u_src = (unsigned char *)src;
	u_dest = (unsigned char *)dest;
	if (u_dest > u_src)
	{
		i = n;
		while (--i > 0)
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
