/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:06 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/04/07 03:28:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (s == NULL || len == 0)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (start > i)
		return (NULL);
	if (start + len > i)
		i = i - start;
	else
		i = i - start + len;
	substr = (char *)malloc((i + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (s[start] && len--)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
