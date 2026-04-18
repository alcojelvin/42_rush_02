#include <stdlib.h>

int	find_colon(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ':')
			return (i);
		i++;
	}
	return (-1);
}

char	*trim_copy(char *s, int start, int end)
{
	char	*res;
	int		i;

	res = malloc(end - start + 1);
	if (!res)
		return (0);
	i = 0;
	while (start < end)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

int	parse_dict(char *buf, char **k, char **v)
{
	int	i;
	int	j;
	int	colon;
	int	count;

	i = 0;
	count = 0;
	while (buf[i])
	{
		while (buf[i] == '\n')
			i++;
		j = i;
		while (buf[j] && buf[j] != '\n')
			j++;
		colon = find_colon(&buf[i]);
		if (colon >= 0)
		{
			k[count] = trim_copy(&buf[i], 0, colon);
			v[count] = trim_copy(&buf[i], colon + 1, j - i);
			if (k[count] && v[count])
				count++;
		}
		i = j + 1;
	}
	return (count);
}

void	init_dict_arrays(char **k, char **v)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		k[i] = 0;
		v[i] = 0;
		i++;
	}
}
