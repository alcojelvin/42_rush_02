int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

char	*trim_leading_zeros(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0' && str[i + 1] != '\0')
		i++;
	return (&str[i]);	// Passando apenas o endereço dos números válidos sem modificar a string. Caso receba apenas zeros, retorna apenas 1 zero, que será escrito por extenso.
}
