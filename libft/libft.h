/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 07:21:46 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/02/16 16:12:03 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LIBFT_H
# define LIBFT_H

/**
 * @brief checks for an alphabetic character (A - Z, a - z).
 *
 * @param c The character to be checked.
 * @return int: 1024 if the 'c' character is an alphabetic character;
 * 0 otherwise.
 */
int	ft_isalpha(int c);

/**
 * @brief checks for an numerical character (0 - 9).
 * 
 * @param c 
 * @return int 
 */
int	ft_isdigit(int c);

#endif // LIBFT_H
