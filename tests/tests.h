#ifndef TESTS_H
# define TESTS_H

// setjmp() longjmp() jmp_buf
# include <setjmp.h>

// printf()
# include <stdio.h>

// wait()
# include <sys/wait.h>

// execl() fork()
# include <unistd.h>

// ft_isalnum()
# include <libft.h>

// signal() SIGSEGV
# include <signal.h>

extern jmp_buf jmp_buffer;

# ifndef FT_RETURN_VALUES
#  define FT_ISASCII_RETURN 1 << 0
#  define FT_ISALNUM_RETURN 1 << 3
#  define FT_ISALPHA_RETURN 1 << 10
#  define FT_ISDIGIT_RETURN 1 << 11
#  define FT_ISPRINT_RETURN 1 << 14
# endif // FT_RETURN_VALUES

# ifndef FT_COLORS
#  define FT_GREEN "\033[0;32m"
#  define FT_YELLOW "\033[0;33m"
#  define FT_RESET "\033[0m"
# endif // FT_COLORS

# ifndef FT_PATTERNS
#  define FAIL_ALERT "[ ! ] "
# endif // FT_PATTERNS

void	print_result(int passed, const char *test_name);
void	sigsegv_handler(int signum);

#endif // TESTS_H
