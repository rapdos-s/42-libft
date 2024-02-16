/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 07:39:53 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/02/16 09:18:17 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <tests.h>

static void	test(const char c);

void	test_ft_isalpha(void)
{
	print_title ("ft_isalpha tests");
	test (0);
	test ('a');
	test ('z');
	test ('A');
	test ('Z');
	test ('1');
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
	ret = isalpha (c);
	ft_ret = ft_isalpha (c);
	if (ret == ft_ret)
		printf ("Test [%c]: %s\n", c, OK);
	else if (ft_ret && ret)
		printf ("Test [%c]: %s\n", c, PASS);
	else
	{
		printf ("Test [%c]: %s\n", c, KO);
		printf ("isalpha return___: [%d]\n", ret);
		printf ("ft_isalpha return: [%d]\n", ft_ret);
	}
}
