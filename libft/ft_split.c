/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:22 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/04/08 06:38:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_counter(char const *s, char c);
static void		str_splitter(char ***m, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	str_count;
	char	**m;

	if (s == NULL)
		return (NULL);
	str_count = str_counter(s, c);
	m = (char **)malloc((str_count + 1) * sizeof(char *));
	if (m == NULL)
		return (NULL);
	i = 0;
	while (i <= str_count)
		m[i++] = NULL;
	str_splitter(&m, s, c);
	i = 0;
	while (i < str_count)
	{
		if (m[i] == NULL)
		{
			while (i-- > 0)
				free(m[i]);
			free(m);
			return (NULL);
		}
		i++;
	}
	return (m);
}

static size_t	str_counter(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[0] == '\0')
		count++;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (s[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static void	str_splitter(char ***m, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	start;

	start = 0;
	i = 0;
	if (s[0] == '\0')
	{
		(*m)[0] = (char *)malloc(sizeof(char));
		if ((*m)[0] == NULL)
			return;
		(*m)[0][0] = '\0';
	}
	while (s[start] != '\0')
	{
		while (s[start] != '\0' && s[start] == c)
			start++;
		len = 0;
		while (s[start + len] != '\0' && s[start + len] != c)
			len++;
		if (s[start] != '\0')
		{
			(*m)[i] = (char *)malloc((len + 1) * sizeof(char));
			if ((*m)[i] == NULL)
				return;
			j = 0;
			while (j < len)
			{
				(*m)[i][j] = s[start];
				start++;
				j++;
			}
			(*m)[i][j] = '\0';
		}
		i++;
	}
}
