#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*u_src;
	unsigned char	*u_dest;
	size_t			i;

	if (dest == NULL || src == NULL)
		return (NULL);
	u_src = (unsigned char *)src;
	u_dest = (unsigned char *)dest;
	if (u_dest > u_src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			u_dest[i] = u_src[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			u_dest[i] = u_src[i];
			i++;
		}
	}
	return (dest);
}
