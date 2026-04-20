/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneres-n <kneres-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 20:38:06 by kneres-n          #+#    #+#             */
/*   Updated: 2026/04/19 20:38:08 by kneres-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "convert.h"
#include "convert_utils.h"
#include "dict_get.h"
#include "num_utils.h"

static char	*get_suffix_key(int group)
{
	static char	*suffixes[] = {"1000", "1000000", "1000000000", 0};

	if (group == 0 || group > 3)
		return (0);
	return (suffixes[group - 1]);
}

static void	convert_tens_units(char *n, char **k, char **v, int size)
{
	char	key[3];

	if (n[0] == '1')
	{
		key[0] = n[0];
		key[1] = n[1];
		key[2] = '\0';
		ft_putstr(dict_get(key, k, v, size));
		return ;
	}
	if (n[0] != '0')
	{
		key[0] = n[0];
		key[1] = '0';
		key[2] = '\0';
		ft_putstr(dict_get(key, k, v, size));
		if (n[1] != '0')
			write(1, " ", 1);
	}
	if (n[1] != '0')
	{
		key[0] = n[1];
		key[1] = '\0';
		ft_putstr(dict_get(key, k, v, size));
	}
}

static int	convert_hundreds(char *n, char **k, char **v, int size)
{
	char	key[2];

	if (n[0] == '0' && n[1] == '0' && n[2] == '0')
		return (0);
	if (n[0] != '0')
	{
		key[0] = n[0];
		key[1] = '\0';
		ft_putstr(dict_get(key, k, v, size));
		write(1, " ", 1);
		ft_putstr(dict_get("100", k, v, size));
		if (n[1] != '0' || n[2] != '0')
			write(1, " ", 1);
	}
	convert_tens_units(&n[1], k, v, size);
	return (1);
}

static void	convert_group(char *buf, int g, char **k, char **v, int size)
{
	char	*suffix_key;
	char	*suffix;

	if (!convert_hundreds(buf, k, v, size))
		return ;
	suffix_key = get_suffix_key(g);
	if (suffix_key)
	{
		suffix = dict_get(suffix_key, k, v, size);
		if (suffix)
		{
			write(1, " ", 1);
			ft_putstr(suffix);
		}
	}
}

void    convert(char *num, char **k, char **v, int size)
{
    int     groups;
    int     g;
    int     first;
    char    buf[4];

    if (num[0] == '0' && num[1] == '\0')
    {
        ft_putstr(dict_get("0", k, v, size));
        return ;
    }

    groups = count_groups(num);
    first = 1;
    g = groups - 1;

    while (g >= 0)
    {
        get_group(num, g, buf);

        if (group_nonzero(buf))
        {
            if (!first)
                write(1, " ", 1);

            convert_group(buf, g, k, v, size);
            first = 0;
        }
        g--;
    }
}
