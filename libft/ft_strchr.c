#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (s && *s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (s && *s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
