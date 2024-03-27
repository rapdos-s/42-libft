# include <tests.h>


static int	uppercase_test(void)
{
	char	uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int		i;

	i = 0;
	while (uppercase_letters[i])
	{
		if (ft_isalnum(uppercase_letters[i]) != FT_ISALPHA_RETURN)
			return (0);
		i++;
	}
	return (1);
}

static int	lowercase_test(void)
{
	char	lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
	int		i;

	i = 0;
	while (lowercase_letters[i])
	{
		if (ft_isalnum(lowercase_letters[i]) != FT_ISALPHA_RETURN)
			return (0);
		i++;
	}
	return (1);
}

static int	digits_test(void)
{
	char	digits[] = "0123456789";
	int		i;

	i = 0;
	while (digits[i])
	{
		if (ft_isalnum(digits[i]) != FT_ISALPHA_RETURN)
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
		if (ft_isalnum(special_chars[i]) != 0)
			return (0);
		i++;
	}
	if (ft_isalnum(0) != 0)
		return (0);
	return (1);
}

int	main(void)
{
	int	result;

	result = 0;
	result += uppercase_test();
	result += lowercase_test();
	result += digits_test();
	result += special_char_test();
	print_result(result, "ft_isalnum");
}
