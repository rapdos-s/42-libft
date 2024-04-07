/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:07 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/04/07 05:54:16 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtrim_strchr(const char *s, int c);
static char	*ft_strtrim_substr(char const *s, unsigned int start, size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*return_value;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_strtrim_strchr(set, s1[start]))
		start++;
	len = start;
	while (s1[len] != '\0')
		len++;
	len--;
	while (len > start && ft_strtrim_strchr(set, s1[len]))
		len--;
	return_value = ft_strtrim_substr(s1, start, len - start + 1);
	return (return_value);
}

static char	*ft_strtrim_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

static char	*ft_strtrim_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

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
