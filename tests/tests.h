/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 07:41:34 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/02/16 09:17:44 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#ifndef TESTS_H
# define TESTS_H

// isalpha()
# include <ctype.h>

// printf()
# include <stdio.h>

// strlen()
# include <string.h>

// libft
# include <libft.h>

#define DEFAULT_COLOR	"\x1b[0m"
#define RED_COLOR		"\x1b[31m"
#define GREEN_COLOR		"\x1b[32m"
#define YELLOW_COLOR	"\x1b[33m"

#define OK		GREEN_COLOR "OK" DEFAULT_COLOR
#define PASS	YELLOW_COLOR "PASS" DEFAULT_COLOR
#define KO		RED_COLOR "KO" DEFAULT_COLOR

// Tests
void	test_ft_isalpha(void);

// Utils
void	print_title(const char *title);
void	print_footer(void);

#endif // TESTS_H

