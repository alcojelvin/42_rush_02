#include "ft_str_utils.h"

void	slice(char *src, int start, int len, char *dst) // dst aponta para um espaço que já foi alocado na memória.
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[start + i];
		i++;
	}
	dst[len] = '\0';
}

void	get_group_bounds(int len, int group, int *start, int *end)
{
	*end = len - group * 3;
	*start = *end - 3;
	if (*start < 0)
		*start = 0;
}

void	get_group(char *num, int group, char *buf)
{
	int	start;
	int	end;
	int	pad;
	int	i;

	get_group_bounds(ft_strlen(num), group, &start, &end);
	pad = 3 - (end - start);
	i = 0;
	while (i < pad)
	{
		buf[i] = '0';
		i++;
	}
	slice(num, start, end - start, &buf[pad]);
}

int	count_groups(char *num)
{
	int	len;

	len = ft_strlen(num);
	if (len % 3 == 0)
		return (len / 3);
	return (len / 3 + 1);
}
