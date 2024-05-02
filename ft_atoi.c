/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:28:40 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/04/04 13:41:36 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_get_signal(const char **nptr);
static void	ft_atoi_get_number(const char *nptr, int *return_value);

int	ft_atoi(const char *nptr)
{
	int	return_value;
	int	negative_signal;

	if (nptr == NULL)
		return (0);
	return_value = 0;
	negative_signal = ft_atoi_get_signal(&nptr);
	ft_atoi_get_number(nptr, &return_value);
	if (negative_signal)
		return (-return_value);
	return (return_value);
}

static int	ft_atoi_get_signal(const char **nptr)
{
	while (**nptr == ' ' || \
		**nptr == '\t' || \
		**nptr == '\n' || \
		**nptr == '\v' || \
		**nptr == '\f' || \
		**nptr == '\r')
			(*nptr)++;
	if (**nptr == '-')
	{
		(*nptr)++;
		return (1);
	}
	if (**nptr == '+')
		(*nptr)++;
	return (0);
}

static void	ft_atoi_get_number(const char *nptr, int *nbr)
{
	int	i;

	*nbr = 0;
	i = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		*nbr = *nbr * 10 + nptr[i] - '0';
		i++;
	}
}
