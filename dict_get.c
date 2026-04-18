#include "ft_str_utils.h"

int	key_match(char *a, char *b, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

char	*dict_get(char *key, char **k, char **v, int size)
{
	int	i;
	int	klen;

	klen = ft_strlen(key);
	i = 0;
	while (i < size)
	{
		if (k[i] && v[i] && ft_strlen(k[i]) == klen)
			if (key_match(k[i], key, klen))
				return (v[i]);
		i++;
	}
	return (0);
}
