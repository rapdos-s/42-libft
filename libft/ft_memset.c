/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:29 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/29 12:35:31 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	u_c;
	unsigned char	*u_s;

	if (!s)
		return (NULL);
	i = 0;
	u_c = (unsigned char)c;
	u_s = (unsigned char *)s;
	while (i < n)
	{
		u_s[i] = u_c;
		i++;
	}
	return (s);
}
