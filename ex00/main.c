/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneres-n <kneres-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 20:12:16 by kneres-n          #+#    #+#             */
/*   Updated: 2026/04/19 20:12:40 by kneres-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_str_utils.h"
#include "parse_args.h"
#include "dict_io.h"
#include "dict_parse.h"
#include "dict_get.h"
#include "num_utils.h"
#include "convert.h"

int	validate_and_load(int argc, char **argv, char **num, char **dict)
{
	char	*path;

	if (argc != 2 && argc != 3)
		return (0);
	*num = trim_leading_zeros(argv[argc - 1]);
	if (!is_valid_number(*num))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 3)
		path = argv[1];
	else
		path = "numbers.dict";
	*dict = load_dict(path);
	if (!*dict)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}

void	convert_and_print(char *num, char *dict)
{
	char	*keys[1000];
	char	*values[1000];
	int		size;

	init_dict_arrays(keys, values);
	size = parse_dict(dict, keys, values);
	convert(num, keys, values, size);
	write(1, "\n", 1);
}

void	cleanup(char *dict)
{
	free(dict);
}

int	main(int argc, char **argv)
{
	char	*num;
	char	*dict;

	if (!validate_and_load(argc, argv, &num, &dict))
		return (0);
	convert_and_print(num, dict);
	cleanup(dict);
	return (0);
}
