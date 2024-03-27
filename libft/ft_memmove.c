/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:30 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:29:32 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*u_dest;
	unsigned char	*u_src;
	size_t			i;

	if (!dest || !src)
		return (NULL);
	u_dest = (unsigned char *)dest;
	u_src = (unsigned char *)src;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			u_dest[i] = u_src[i];
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (u_dest);
}
