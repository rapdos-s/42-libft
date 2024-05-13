/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:33 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/05/13 17:51:57 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*uc_s1;
	const unsigned char	*uc_s2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	uc_s2 = (const unsigned char *)s2;
	if (s1 == NULL)
		return (-(int)(uc_s2[0]));
	uc_s1 = (const unsigned char *)s1;
	if (s2 == NULL)
		return ((int)(uc_s1[0]));
	i = 0;
	while (i < n && uc_s1[i] == uc_s2[i])
		i++;
	if (i == n)
		return (0);
	if (uc_s1[0] == '\0' || uc_s2[0] == '\0')
		return (uc_s1[i] - uc_s2[i]);
	else if (uc_s1[i] > uc_s2[i])
		return (1);
	else
		return (-1);
}
