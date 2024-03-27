/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:29 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:29:30 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*u_s;

	if (!s)
		return (NULL);
	u_s = (unsigned char *) s;
	while (n--)
		u_s[n] = (unsigned char) c;
	return (u_s);
}
