#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

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

char	*append_buffer(char *res, char *buf, int total, int bytes)
{
	char	*new;
	int		i;

	new = (char *)malloc(total + bytes + 1);
	if (!new)
		return (0);
	i = 0;
	while (i < total)
	{
		new[i] = res[i];
		i++;
	}
	i = 0;
	while (i < bytes)
	{
		new[total + i] = buf[i];
		i++;
	}
	new[total + bytes] = '\0';
	free(res);
	return (new);
}

char	*load_dict(char *filename)
{
	int		fd;
	int		bytes;
	int		total;
	char	buffer[1024];
	char	*res;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	res = 0;
	total = 0;
	bytes = read(fd, buffer, 1024);
	while (bytes > 0)
	{
		res = append_buffer(res, buffer, total, bytes);
		if (!res)
			return (0);
		total += bytes;
		bytes = read(fd, buffer, 1024);
	}
	close(fd);
	if (bytes < 0)
		return (0);
	return (res);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	main(int argc, char **argv)
{
	char	*num;
	char	*dict;
	char	*filename;

	if (argc != 2 && argc != 3)
		return (0);
	if (!is_valid_number(argv[argc - 1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	num = trim_leading_zeros(argv[argc - 1]);
	if (argc == 3)
		filename = argv[1];
	else
		filename = "numbers.dict";
	dict = load_dict(filename);
	if (!dict)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	ft_putstr(num);
	write(1, "\n", 1);
	free(dict);
	return (0);
}
