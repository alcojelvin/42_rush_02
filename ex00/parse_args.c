/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneres-n <kneres-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:17:19 by kneres-n          #+#    #+#             */
/*   Updated: 2026/04/19 19:40:46 by kneres-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (&str[i]);
}
