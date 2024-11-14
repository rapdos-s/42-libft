/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:49 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/11/14 12:55:35 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (FT_ISALNUM_RETURN);
	if (c >= 'a' && c <= 'z')
		return (FT_ISALNUM_RETURN);
	if (c >= '0' && c <= '9')
		return (FT_ISALNUM_RETURN);
	return (0);
}
