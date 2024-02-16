/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:08:48 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/02/16 16:45:43 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int	ft_isdigit(int c)
{
	int	ret;

	ret = 0;
	if ((c >= '0' && c <= '9'))
		ret = 1 << 11;
	return (ret);
}
