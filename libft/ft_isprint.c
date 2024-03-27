#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (FT_ISPRINT_RETURN);
	return (0);
}
