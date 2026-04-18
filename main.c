#include <unistd.h>

char	*trim_leading_zeros(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		return ("0");
	return (&str[i]);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	
}

int	main(int argc, char **argv)
{
	char	*num;

	if (argc != 2)
		return (0);
	if (!is_valid_number(argv[1]))
	{
		write(1, "INVALID\n", 8);
		return (0);
	}
	num = trim_leading_zeros(argv[1]);
	ft_putstr(num);
	write(1, "\n", 1);
	return (0);
}
