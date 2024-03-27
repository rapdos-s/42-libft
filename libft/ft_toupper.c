#include "libft.h"

int	ft_toupper(int c)
{
	return (c & ~(ft_isalpha(c) >> 5));
}
