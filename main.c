#include <unistd.h>
#include <stdlib.h>

#include "ft_str_utils.h"
#include "parse_args.h"
#include "dict_io.h"
#include "dict_parse.h"
#include "dict_get.h"
#include "num_utils.h"
#include "convert.h"

// int	ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// void	putstr(char *s)
// {
// 	if (!s)
// 		return;
// 	write(1, s, ft_strlen(s));
// }

// int	is_valid_number(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str || str[0] == '\0')
// 		return (0);
// 	while (str[i])
// 	{
// 		if (str[i] < '0' || str[i] > '9')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// char	*trim_leading_zeros(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] == '0' && str[i + 1] != '\0')
// 		i++;
// 	return (&str[i]);	// Passando apenas o endereço dos números válidos sem modificar a string. Caso receba apenas zeros, retorna apenas 1 zero, que será escrito por extenso.
// }

// void	slice(char *src, int start, int len, char *dst) // dst aponta para um espaço que já foi alocado na memória.
// {
// 	int	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		dst[i] = src[start + i];
// 		i++;
// 	}
// 	dst[len] = '\0';
// }

// void	get_group_bounds(int len, int group, int *start, int *end)
// {
// 	*end = len - group * 3;
// 	*start = *end - 3;
// 	if (*start < 0)
// 		*start = 0;
// }

// void	get_group(char *num, int group, char *buf)
// {
// 	int	start;
// 	int	end;
// 	int	pad;
// 	int	i;

// 	get_group_bounds(ft_strlen(num), group, &start, &end);
// 	pad = 3 - (end - start);
// 	i = 0;
// 	while (i < pad)
// 	{
// 		buf[i] = '0';
// 		i++;
// 	}
// 	slice(num, start, end - start, &buf[pad]);
// }

// int	count_groups(char *num)
// {
// 	int	len;

// 	len = ft_strlen(num);
// 	if (len % 3 == 0)
// 		return (len / 3);
// 	return (len / 3 + 1);
// }

// char	*append_buffer(char *res, char *buf, int total, int bytes)
// {
// 	char	*new;
// 	int		i;

// 	new = malloc(total + bytes + 1);
// 	if (!new)
// 		return (0);
// 	i = 0;
// 	while (i < total)
// 	{
// 		new[i] = res[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < bytes)
// 	{
// 		new[total + i] = buf[i];
// 		i++;
// 	}
// 	new[total + bytes] = '\0';
// 	free(res);
// 	return (new);
// }

// char	*load_dict(char *filename)
// {
// 	int		fd;
// 	int		bytes;
// 	int		total;
// 	char	buffer[1024];
// 	char	*res;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	res = 0;
// 	total = 0;
// 	bytes = read(fd, buffer, 1024);
// 	while (bytes > 0)
// 	{
// 		res = append_buffer(res, buffer, total, bytes);
// 		if (!res)
// 			return (0);
// 		total = total + bytes;
// 		bytes = read(fd, buffer, 1024);
// 	}
// 	close(fd);
// 	return (res);
// }

// int	find_colon(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == ':')
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// char	*trim_copy(char *s, int start, int end)
// {
// 	char	*res;
// 	int		i;

// 	res = malloc(end - start + 1);
// 	if (!res)
// 		return (0);
// 	i = 0;
// 	while (start < end)
// 		res[i++] = s[start++];
// 	res[i] = '\0';
// 	return (res);
// }

// int	parse_dict(char *buf, char **k, char **v)
// {
// 	int	i;
// 	int	j;
// 	int	colon;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (buf[i])
// 	{
// 		while (buf[i] == '\n')
// 			i++;
// 		j = i;
// 		while (buf[j] && buf[j] != '\n')
// 			j++;
// 		colon = find_colon(&buf[i]);
// 		if (colon >= 0)
// 		{
// 			k[count] = trim_copy(&buf[i], 0, colon);
// 			v[count] = trim_copy(&buf[i], colon + 1, j - i);
// 			if (k[count] && v[count])
// 				count++;
// 		}
// 		i = j + 1;
// 	}
// 	return (count);
// }

// int	key_match(char *a, char *b, int len)
// {
// 	int	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		if (a[i] != b[i])
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// char	*dict_get(char *key, char **k, char **v, int size)
// {
// 	int	i;
// 	int	klen;

// 	klen = ft_strlen(key);
// 	i = 0;
// 	while (i < size)
// 	{
// 		if (k[i] && v[i] && ft_strlen(k[i]) == klen)
// 			if (key_match(k[i], key, klen))
// 				return (v[i]);
// 		i++;
// 	}
// 	return (0);
// }

// static char	*g_suffix_keys[] = {
// 	"1000",
// 	"1000000",
// 	"1000000000",
// 	"1000000000000",
// 	"1000000000000000",
// 	"1000000000000000000",
// 	"1000000000000000000000",
// 	"1000000000000000000000000",
// 	"1000000000000000000000000000",
// 	"1000000000000000000000000000000",
// 	"1000000000000000000000000000000000",
// 	"1000000000000000000000000000000000000",
// 	0
// };

// char	*get_suffix(int group, char **k, char **v, int size)
// {
// 	if (group == 0)
// 		return (0);
// 	return (dict_get(g_suffix_keys[group - 1], k, v, size));
// }

// void	convert_units(char c, char **k, char **v, int size)
// {
// 	char	key[2];

// 	if (c == '0')
// 		return ;
// 	key[0] = c;
// 	key[1] = '\0';
// 	putstr(dict_get(key, k, v, size));
// }

// void	convert_tens(char *n, char **k, char **v, int size)
// {
// 	char	key[3];

// 	if (n[0] == '1')
// 	{
// 		key[0] = n[0];
// 		key[1] = n[1];
// 		key[2] = '\0';
// 		putstr(dict_get(key, k, v, size));
// 		return ;
// 	}
// 	if (n[0] != '0')
// 	{
// 		key[0] = n[0];
// 		key[1] = '0';
// 		key[2] = '\0';
// 		putstr(dict_get(key, k, v, size));
// 		if (n[1] != '0')
// 			write(1, " ", 1);
// 	}
// 	convert_units(n[1], k, v, size);
// }

// int	group_nonzero(char *g)
// {
// 	return (g[0] != '0' || g[1] != '0' || g[2] != '0');
// }

// void	convert_hundreds_hi(char *n, char **k, char **v, int size)
// {
// 	char	key[2];

// 	key[0] = n[0];
// 	key[1] = '\0';
// 	putstr(dict_get(key, k, v, size));
// 	write(1, " ", 1);
// 	putstr(dict_get("100", k, v, size));
// 	if (n[1] != '0' || n[2] != '0')
// 		write(1, " ", 1);
// }

// int	convert_hundreds(char *n, char **k, char **v, int size)
// {
// 	if (!group_nonzero(n))
// 		return (0);
// 	if (n[0] != '0')
// 		convert_hundreds_hi(n, k, v, size);
// 	convert_tens(&n[1], k, v, size);
// 	return (1);
// }

// void	convert_group(char *buf, int g, char **k, char **v, int size)
// {
// 	char	*suffix;

// 	convert_hundreds(buf, k, v, size);
// 	suffix = get_suffix(g, k, v, size);
// 	if (suffix)
// 	{
// 		write(1, " ", 1);
// 		putstr(suffix);
// 	}
// }

// void	convert(char *num, char **k, char **v, int size)
// {
// 	int		groups;
// 	int		g;
// 	char	buf[4];
// 	int		printed;

// 	if (num[0] == '0' && num[1] == '\0')
// 	{
// 		putstr(dict_get("0", k, v, size));
// 		return ;
// 	}
// 	groups = count_groups(num);
// 	printed = 0;
// 	g = groups - 1;
// 	while (g >= 0)
// 	{
// 		get_group(num, g, buf);
// 		if (group_nonzero(buf))
// 		{
// 			if (printed)
// 				write(1, " ", 1);
// 			convert_group(buf, g, k, v, size);
// 			printed = 1;
// 		}
// 		g--;
// 	}
// }

// void	init_dict_arrays(char **k, char **v)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 1000)
// 	{
// 		k[i] = 0;
// 		v[i] = 0;
// 		i++;
// 	}
// }

int	main(int argc, char **argv)
{
	char	*num;
	char	*dict;
	char	*k[1000];
	char	*v[1000];
	int		size;

	if (argc != 2 && argc != 3)
		return (0);
	if (!is_valid_number(argv[argc - 1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	num = trim_leading_zeros(argv[argc - 1]);
	if (argc == 3)
		dict = load_dict(argv[1]);
	else
		dict = load_dict("numbers.dict");
	if (!dict)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	init_dict_arrays(k, v);
	size = parse_dict(dict, k, v);
	convert(num, k, v, size);
	write(1, "\n", 1);
	free(dict);
	return (0);
}
