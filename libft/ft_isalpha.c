#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (FT_ISALPHA_RETURN);
	if (c >= 'a' && c <= 'z')
		return (FT_ISALPHA_RETURN);
	return (0);
}
