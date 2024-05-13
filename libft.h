/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapdos-s <rapdos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:37:49 by rapdos-s          #+#    #+#             */
/*   Updated: 2024/05/13 18:25:54 by rapdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// System libraries ////////////////////////////////////////////////////////////

// functions: malloc()
# include <stdlib.h>

// functions:  write()
// types: size_t
# include <unistd.h>

// Macros //////////////////////////////////////////////////////////////////////

# ifndef FT_ISASCII_RETURN
#  define FT_ISASCII_RETURN 1
# endif // FT_ISASCII_RETURN

# ifndef FT_ISALNUM_RETURN
#  define FT_ISALNUM_RETURN 8
# endif // FT_ISALNUM_RETURN

# ifndef FT_ISALPHA_RETURN
#  define FT_ISALPHA_RETURN 10
# endif // FT_ISALPHA_RETURN

# ifndef FT_ISDIGIT_RETURN
#  define FT_ISDIGIT_RETURN 2048
# endif // FT_ISDIGIT_RETURN

# ifndef FT_ISPRINT_RETURN
#  define FT_ISPRINT_RETURN 16384
# endif // FT_ISPRINT_RETURN

// libft Functions ////////////////////////////////////////////////////////////

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif // LIBFT_H
