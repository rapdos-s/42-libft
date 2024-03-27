# include <tests.h>

static int	n_zero_tests(void)
{
	char	str[42];
	int		i;

	i = 0;
	while(i < 42)
		str[i++] = 'A';
	ft_bzero(str, 0);
	i = 0;
	while (i < 42)
	{
		if (str[i] != 'A')
		{
			printf(FAIL_ALERT "ft_bzero: Fail on n zero tests\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	half_tests(void)
{
	char	str[42];
	int		i;

	i = 0;
	while(i < 42)
		str[i++] = 'A';
	ft_bzero(str, 21);
	i = 0;
	while (i < 21)
	{
		if (str[i] != 0)
			return (0);
		i++;
	}
	while (i < 42)
	{
		if (str[i] != 'A')
			return (0);
		i++;
	}
	return (1);
}

static int	fullfill_tests(void)
{
	char	str[42];
	int		i;

	i = 0;
	ft_bzero(str, 42);
	while (i < 42)
	{
		if (str[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	null_strings_tests(void)
{
	signal(SIGSEGV, sigsegv_handler);
	if (setjmp(jmp_buffer) == 0)
		ft_bzero(NULL, 42);
	else
		return(0);
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += n_zero_tests();
	result += half_tests();
	result += fullfill_tests();
	result += null_strings_tests();
	print_result(result, "ft_bzero");
}
