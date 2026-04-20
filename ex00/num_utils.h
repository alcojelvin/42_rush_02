/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneres-n <kneres-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:17:13 by kneres-n          #+#    #+#             */
/*   Updated: 2026/04/19 17:36:57 by kneres-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_UTILS_H
# define NUM_UTILS_H

int		count_groups(char *num);
void	get_group(char *num, int group, char *buf);
void	get_group_bounds(int len, int group, int *start, int *end);

#endif
