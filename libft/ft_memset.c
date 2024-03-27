#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*u_s;

	if (!s)
		return (NULL);
	u_s = (unsigned char *) s;
	while (n--)
		u_s[n] = (unsigned char) c;
	return (u_s);
}
