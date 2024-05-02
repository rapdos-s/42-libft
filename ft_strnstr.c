/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:10 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/04/05 22:13:21 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (big == NULL || little == NULL)
		return (NULL);
	if (little[0] == '\0')
		return ((char *) big);
	i = 0;
	while (big[i] && len--)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] && little[j] && big[i + j] == little[j])
				j++;
			if (little[j] == '\0')
				return ((char *) big + i);
		}
		i++;
	}
	return (NULL);
}
