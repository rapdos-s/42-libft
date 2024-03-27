/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:29:49 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:29:50 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (FT_ISALPHA_RETURN);
	if (c >= 'a' && c <= 'z')
		return (FT_ISALPHA_RETURN);
	if (c >= '0' && c <= '9')
		return (FT_ISALPHA_RETURN);
	return (0);
}
