/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneres-n <kneres-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:16:51 by kneres-n          #+#    #+#             */
/*   Updated: 2026/04/19 17:36:49 by kneres-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_PARSE_H
# define DICT_PARSE_H

int		parse_dict(char *buf, char **k, char **v);
void	init_dict_arrays(char **k, char **v);

#endif