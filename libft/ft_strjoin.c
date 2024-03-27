#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	i;

	i = 0;
	s1_len = ft_strlen(s1);
	str = (char *) ft_calloc(s1_len + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		str[s1_len + i] = s2[i];
		i++;
	}
	return (str);
}
