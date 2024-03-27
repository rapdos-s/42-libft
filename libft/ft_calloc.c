#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*alloc;
	size_t		alloc_size;

	alloc_size = nmemb * size;
	if (alloc_size / size != nmemb && size)
		return (NULL);
	alloc = malloc(alloc_size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, alloc_size);
	return (alloc);
}
