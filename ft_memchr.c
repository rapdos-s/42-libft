/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:34 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/04/03 16:42:15 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	u_c;
	unsigned char	*uc_s;

	if (s == NULL)
		return (NULL);
	u_c = (unsigned char)c;
	uc_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (uc_s[i] == u_c)
			return ((void *)&uc_s[i]);
		i++;
	}
	return (NULL);
}
