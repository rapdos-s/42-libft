/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:20 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/05/13 17:51:32 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	duplicate = (char *)malloc(sizeof(char) * (s_len + 1));
	if (duplicate == NULL)
		return (NULL);
	duplicate[s_len] = '\0';
	while (s_len--)
		duplicate[s_len] = s[s_len];
	return (duplicate);
}
