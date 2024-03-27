#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*uc_s;

	uc_s = (unsigned char *) s;
	while (n--)
	{
		if (*uc_s == (unsigned char) c)
			return (uc_s);
		uc_s++;
	}
	return (NULL);
}
