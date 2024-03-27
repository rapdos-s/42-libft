#include "libft.h"

int	ft_tolower(int c)
{
	return (c | (ft_isalpha(c) >> 5));
}
