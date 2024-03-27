/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:28:40 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:28:41 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		n;
	char	signal;

	if (!nptr)
		return (0);
	n = 0;
	signal = 1;
	while (nptr && *nptr >= 9 && *nptr <= 32 && *nptr != 27)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal *= -signal;
		nptr++;
	}
	while (ft_isdigit(*nptr))
		n = n * 10 + (*nptr++ - 48);
	return (n * signal);
}
