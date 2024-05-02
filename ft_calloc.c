/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:51 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/04/06 08:30:13 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			alloc_size;
	size_t			i;
	unsigned char	*uc_ptr;
	void			*ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	alloc_size = nmemb * size;
	ptr = malloc(alloc_size);
	if (ptr != NULL)
	{
		uc_ptr = (unsigned char *)ptr;
		i = 0;
		while (i < nmemb)
		{
			uc_ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}
