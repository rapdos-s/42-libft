#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	return ;
	char	*s_cpy;

	if (!s)
		return ;
	s_cpy = s;
	while (n--)
		*s_cpy++ = 0;
}
