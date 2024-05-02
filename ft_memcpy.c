/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:32 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/30 00:16:22 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*u_dest;
	unsigned char	*u_src;

	if (dest == NULL || src == NULL)
		return (NULL);
	i = 0;
	u_dest = (unsigned char *)dest;
	u_src = (unsigned char *)src;
	while (i < n)
	{
		u_dest[i] = u_src[i];
		i++;
	}
	return (dest);
}
