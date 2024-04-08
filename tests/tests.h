/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:30:15 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/03/27 19:30:15 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# ifndef _GNU_SOURCE
#  define _GNU_SOURCE
# endif // _GNU_SOURCE

// dlsym RTLD_NEXT
# include <dlfcn.h>

// errno
# include <errno.h>

// setjmp() longjmp() jmp_buf
# include <setjmp.h>

// free()
# include <stdlib.h>

// printf()
# include <stdio.h>

// wait()
# include <sys/wait.h>

// execl() fork() pipe() read() size_t ssize_t
# include <unistd.h>

// ft_isalnum()
# include <libft.h>

// signal() SIGSEGV
# include <signal.h>

extern jmp_buf		g_jmp_buffer;

# ifndef FT_RETURN_VALUES
#  define FT_ISASCII_RETURN 1
#  define FT_ISALNUM_RETURN 8
#  define FT_ISALPHA_RETURN 1024
#  define FT_ISDIGIT_RETURN 2048
#  define FT_ISPRINT_RETURN 16384
# endif // FT_RETURN_VALUES

# ifndef FT_COLORS
#  define FT_GREEN "\033[0;32m"
#  define FT_RED "\033[0;31m"
#  define FT_YELLOW "\033[0;33m"
#  define FT_RESET "\033[0m"
# endif // FT_COLORS

# ifndef FT_PATTERNS
#  define FAIL_ALERT "[ ! ] "
#  define ERROR_ALERT "[ X ] "
# endif // FT_PATTERNS

# define FALSE 0
# define TRUE 1

typedef struct s_bzero_test
{
	int		a;
	char	b;
}			t_bzero_test;

typedef struct s_omnitype {
	char			c;
	short			s;
	int				i;
	long			l;
	ssize_t			ssize;
	unsigned char	uc;
	unsigned short	us;
	unsigned int	ui;
	unsigned long	ul;
	size_t			size;
	void			*ptr;
	char			*str;
	short			*short_ptr;
	int				*int_ptr;
	long			*long_ptr;
	ssize_t			*ssize_ptr;
	char			arr_c[42];
	short			arr_s[42];
	int				arr_i[42];
	long			arr_l[42];
	ssize_t			arr_ssize[42];
	unsigned char	arr_uc[42];
	unsigned short	arr_us[42];
	unsigned int	arr_ui[42];
	unsigned long	arr_ul[42];
	size_t			arr_size[42];
	void			*ptr_arr[21][42][84];
}	t_omnitype;

void	print_result(int passed, const char *test_name);
void	sigsegv_handler(int signum);
void	set_g_run_original_malloc(int value);
void	reset_g_alloc_size_request(void);
size_t	get_g_alloc_size_request(void);
void	*malloc(size_t size);
int	test_strcmp(const char *s1, const char *s2);

#endif // TESTS_H
