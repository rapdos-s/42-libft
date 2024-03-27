# include <tests.h>

static int	printable_chars_test(void)
{
	char	printable_chars[] = "012789ABCXYZabcxyz./ ";
	int		i;

	i = 0;
	while (printable_chars[i])
	{
		if (ft_isprint(printable_chars[i]) != FT_ISPRINT_RETURN)
			return (0);
		i++;
	}
	return (1);
}

static int	control_chars_test(void)
{
	char	control_chars[] = "\t\n\r\v\f";
	int		i;

	i = 0;
	while (control_chars[i])
	{
		if (ft_isprint(control_chars[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	non_printable_chars_test(void)
{
	int		i;

	i = 0;
	while (i < 32)
	{
		if (ft_isprint(i) != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	negative_chars_test(void)
{
	int		i;

	i = -100;
	while (i < 0)
	{
		if (ft_isprint(i) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += printable_chars_test();
	result += control_chars_test();
	result += non_printable_chars_test();
	result += negative_chars_test();
	print_result(result, "ft_isprint");
}
