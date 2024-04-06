/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:20 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/04/06 13:31:09 by coder            ###   ########.fr       */
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
