/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 07:44:43 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/02/16 07:45:06 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <tests.h>

#define SPACER "#"
#define LINE_SIZE 80
#define TITLE "# %s "

void	print_title(const char *title)
{
	int	num_spacers;

	if (title)
	{
		num_spacers = LINE_SIZE - (int)(strlen(title) + strlen(TITLE) - 2);
		printf(TITLE, title);
		while (num_spacers--)
			printf(SPACER);
		printf("\n");
	}
	else
		print_footer();
}

void	print_footer(void)
{
	printf("########################################");
	printf("########################################\n");
}
