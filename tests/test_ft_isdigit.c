# include <tests.h>

static int	digits_test(void)
{
	char	digits[] = "0123456789";
	int		i;

	i = 0;
	while (digits[i])
	{
		if (ft_isdigit(digits[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	letters_test(void)
{
	char	letters[] = "ABCXYZabcxyz";
	int		i;

	i = 0;
	while (letters[i])
	{
		if (ft_isdigit(letters[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	low_ascii_test(void)
{
	int		i;

	i = 0;
	while (i < 32)
	{
		if (ft_isdigit(i) != 0)
			return (0);
		i++;
	}
	return (1);
}

static int	special_char_test(void)
{
	char	special_chars[] = " \t\n\r\v\f";
	int		i;

	i = 0;
	while (special_chars[i])
	{
		if (ft_isdigit(special_chars[i]) != 0)
			return (0);
		i++;
	}
	if (ft_isdigit(0) != 0)
		return (0);
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += digits_test();
	result += letters_test();
	result += low_ascii_test();
	result += special_char_test();
	print_result(result, "ft_isdigit");
}
