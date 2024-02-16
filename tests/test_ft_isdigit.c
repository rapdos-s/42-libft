/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 07:39:53 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/02/16 16:45:00 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <tests.h>

static void	test(const char c);

void	test_ft_isdigit(void)
{
	print_title ("ft_isdigit tests");
	test (0);
	test (5);
	test (9);
	test ('0');
	test ('5');
	test ('9');
	test ('A');
	test ('Z');
	test ('@');
	test (' ');
	test ('\t');
	print_footer ();
}

static void	test(const char c)
{
	int		ret;
	int		ft_ret;

	ret = 0;
	ft_ret = 0;
	ret = isdigit (c);
	ft_ret = ft_isdigit (c);
	if (ret == ft_ret)
		printf ("%s: [%c]\n", OK, c);
	else if (ft_ret && ret)
	{
		printf ("%s: [%c] | ", PASS, c);
		printf ("isdigit return: [%d] | ", ret);
		printf ("ft_isdigit return: [%d]\n", ft_ret);
	}
	else
	{
		printf ("%s: [%c] | ", KO, c);
		printf ("isdigit return: [%d] | ", ret);
		printf ("ft_isdigit return: [%d]\n", ft_ret);
	}
}
