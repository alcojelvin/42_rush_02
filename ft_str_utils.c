#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	putstr(char *s)
{
	if (!s)
		return;
	write(1, s, ft_strlen(s));
}
