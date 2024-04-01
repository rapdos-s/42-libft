/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:10 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:10 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

int	main(int argc, char *argv[])
{
	int	i;

	signal(SIGSEGV, sigsegv_handler);
	i = 1;
	while (i < argc)
	{
		if (fork() == 0)
			execl(argv[i], argv[i], NULL);
		else
			wait(NULL);
		i++;
	}
}
