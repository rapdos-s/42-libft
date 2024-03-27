#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_n;

	if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		u_n = -n;
	}
	else
		u_n = n;
	if (u_n >= 10)
		ft_putnbr_fd (u_n / 10, fd);
	ft_putchar_fd (u_n % 10 + '0', fd);
}
