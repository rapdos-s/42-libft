/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:18 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/04/07 04:50:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	len_s1 = 0;
	if (s1 != NULL)
		while (s1[len_s1] != '\0')
			len_s1++;
	len_s2 = 0;
	if (s2 != NULL)
		while (s2[len_s2] != '\0')
			len_s2++;
	if (len_s1 + len_s2 == 0)
		return (NULL);
	str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len_s1 + len_s2] = '\0';
	while(len_s2--)
		str[len_s1 + len_s2] = s2[len_s2];
	while(len_s1--)
		str[len_s1] = s1[len_s1];
	return (str);
}
