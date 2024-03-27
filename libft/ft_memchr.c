/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:34 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:47:15 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*uc_s;

	uc_s = (unsigned char *) s;
	while (n--)
	{
		if (*uc_s == (unsigned char) c)
			return (uc_s);
		uc_s++;
	}
	return (NULL);
}
