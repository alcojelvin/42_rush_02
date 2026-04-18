#ifndef NUM_UTILS_H
#define NUM_UTILS_H

int		count_groups(char *num);
void	get_group(char *num, int group, char *buf);
void	get_group_bounds(int len, int group, int *start, int *end);

#endif
