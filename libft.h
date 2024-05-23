/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:37:49 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/05/23 22:46:42 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

// System libraries ////////////////////////////////////////////////////////////

// functions: malloc()
#include <stdlib.h>

// functions: write()
// types: size_t
#include <unistd.h>

// Macros //////////////////////////////////////////////////////////////////////

#ifndef FT_ISASCII_RETURN_LEFT_SHIFT
#define FT_ISASCII_RETURN_LEFT_SHIFT 0
#endif	// FT_ISASCII_RETURN_LEFT_SHIFT

#ifndef FT_ISALNUM_RETURN_LEFT_SHIFT
#define FT_ISALNUM_RETURN_LEFT_SHIFT 3
#endif	// FT_ISALNUM_RETURN_LEFT_SHIFT

#ifndef FT_ISALPHA_RETURN_LEFT_SHIFT
#define FT_ISALPHA_RETURN_LEFT_SHIFT 10
#endif	// FT_ISALPHA_RETURN_LEFT_SHIFT

#ifndef FT_ISDIGIT_RETURN_LEFT_SHIFT
#define FT_ISDIGIT_RETURN_LEFT_SHIFT 11
#endif	// FT_ISDIGIT_RETURN_LEFT_SHIFT

#ifndef FT_ISPRINT_RETURN_LEFT_SHIFT
#define FT_ISPRINT_RETURN_LEFT_SHIFT 14
#endif	// FT_ISPRINT_RETURN_LEFT_SHIFT

// libft Functions ////////////////////////////////////////////////////////////

/**
 * @brief Check if the character is an alphabetic character. The return value
 * does not overlap with the bit of return value of ft_isdigit, ft_isalnum,
 * ft_isascii and ft_isprint.
 *
 * @param c The character to be checked.
 * @return int 1024 if the character is an alphabetic character, 0 otherwise.
 */
int ft_isalpha(int c);

/**
 * @brief Check if the character is a digit. The return value does not overlap
 * with the bit of return value of ft_isalpha, ft_isalnum, ft_isascii and
 * ft_isprint.
 *
 * @param c The character to be checked.
 * @return int 2048 if the character is a digit, 0 otherwise.
 */
int ft_isdigit(int c);

/**
 * @brief Check if the character is an alphanumeric character. The return value
 * does not overlap with the bit of return value of ft_isalpha, ft_isdigit,
 * ft_isascii and ft_isprint.
 *
 * @param c The character to be checked.
 * @return int 8 if the character is an alphanumeric character, 0 otherwise.
 */
int ft_isalnum(int c);

/**
 * @brief Check if the character is an ASCII character. The return value does
 * not overlap with the bit of return value of ft_isalpha, ft_isdigit,
 * ft_isalnum and ft_isprint.
 *
 * @param c The character to be checked.
 * @return int 1 if the character is an ASCII character, 0 otherwise.
 */
int ft_isascii(int c);

/**
 * @brief Check if the character is a printable character. The return value does
 * not overlap with the bit of return value of ft_isalpha, ft_isdigit,
 * ft_isalnum and ft_isascii.
 *
 * @param c The character to be checked.
 * @return int 16384 if the character is a printable character, 0 otherwise.
 */
int ft_isprint(int c);

size_t ft_strlen(char const *s);
void	 *ft_memset(void *s, int c, size_t n);
void   ft_bzero(void *s, size_t n);
void	 *ft_memcpy(void *dest, void const *src, size_t n);
void	 *ft_memmove(void *dest, void const *src, size_t n);
size_t ft_strlcpy(char *dest, char const *src, size_t size);
size_t ft_strlcat(char *dest, char const *src, size_t size);
int	   ft_toupper(int c);
int	   ft_tolower(int c);
char	 *ft_strchr(char const *s, int c);
char	 *ft_strrchr(char const *s, int c);
int	   ft_strncmp(char const *s1, char const *s2, size_t n);
void	 *ft_memchr(void const *s, int c, size_t n);
int	   ft_memcmp(void const *s1, void const *s2, size_t n);
char	 *ft_strnstr(char const *big, char const *little, size_t len);
int	   ft_atoi(char const *nptr);
void	 *ft_calloc(size_t nmemb, size_t size);
char	 *ft_strdup(char const *s);
char	 *ft_substr(char const *s, unsigned int start, size_t len);
char	 *ft_strjoin(char const *s1, char const *s2);
char	 *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
char	 *ft_itoa(int n);
char	 *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void   ft_striteri(char *s, void (*f)(unsigned int, char *));
void   ft_putchar_fd(char c, int fd);
void   ft_putstr_fd(char *s, int fd);
void   ft_putendl_fd(char *s, int fd);
void   ft_putnbr_fd(int n, int fd);

#endif	// LIBFT_H
