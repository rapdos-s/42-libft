#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return(FT_ISASCII_RETURN);
	return (0);
}
