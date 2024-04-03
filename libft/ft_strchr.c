/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:21 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/04/03 13:29:10 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	u_c;

	u_c = (char)c;
	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == u_c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
