#include <unistd.h>

#include "convert.h"
#include "dict_get.h"
#include "ft_str_utils.h"
#include "num_utils.h"
#include "dict_io.h"

static char	*g_suffix_keys[] = {
	"1000",
	"1000000",
	"1000000000",
	"1000000000000",
	"1000000000000000",
	"1000000000000000000",
	"1000000000000000000000",
	"1000000000000000000000000",
	"1000000000000000000000000000",
	"1000000000000000000000000000000",
	"1000000000000000000000000000000000",
	"1000000000000000000000000000000000000",
	0
};

char	*get_suffix(int group, char **k, char **v, int size)
{
	if (group == 0)
		return (0);
	return (dict_get(g_suffix_keys[group - 1], k, v, size));
}

void	convert_units(char c, char **k, char **v, int size)
{
	char	key[2];

	if (c == '0')
		return ;
	key[0] = c;
	key[1] = '\0';
	putstr(dict_get(key, k, v, size));
}

void	convert_tens(char *n, char **k, char **v, int size)
{
	char	key[3];

	if (n[0] == '1')
	{
		key[0] = n[0];
		key[1] = n[1];
		key[2] = '\0';
		putstr(dict_get(key, k, v, size));
		return ;
	}
	if (n[0] != '0')
	{
		key[0] = n[0];
		key[1] = '0';
		key[2] = '\0';
		putstr(dict_get(key, k, v, size));
		if (n[1] != '0')
			write(1, " ", 1);
	}
	convert_units(n[1], k, v, size);
}

int	group_nonzero(char *g)
{
	return (g[0] != '0' || g[1] != '0' || g[2] != '0');
}

void	convert_hundreds_hi(char *n, char **k, char **v, int size)
{
	char	key[2];

	key[0] = n[0];
	key[1] = '\0';
	putstr(dict_get(key, k, v, size));
	write(1, " ", 1);
	putstr(dict_get("100", k, v, size));
	if (n[1] != '0' || n[2] != '0')
		write(1, " ", 1);
}

int	convert_hundreds(char *n, char **k, char **v, int size)
{
	if (!group_nonzero(n))
		return (0);
	if (n[0] != '0')
		convert_hundreds_hi(n, k, v, size);
	convert_tens(&n[1], k, v, size);
	return (1);
}

void	convert_group(char *buf, int g, char **k, char **v, int size)
{
	char	*suffix;

	convert_hundreds(buf, k, v, size);
	suffix = get_suffix(g, k, v, size);
	if (suffix)
	{
		write(1, " ", 1);
		putstr(suffix);
	}
}

void	convert(char *num, char **k, char **v, int size)
{
	int		groups;
	int		g;
	char	buf[4];
	int		printed;

	if (num[0] == '0' && num[1] == '\0')
	{
		putstr(dict_get("0", k, v, size));
		return ;
	}
	groups = count_groups(num);
	printed = 0;
	g = groups - 1;
	while (g >= 0)
	{
		get_group(num, g, buf);
		if (group_nonzero(buf))
		{
			if (printed)
				write(1, " ", 1);
			convert_group(buf, g, k, v, size);
			printed = 1;
		}
		g--;
	}
}
