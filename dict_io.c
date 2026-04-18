#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*append_buffer(char *res, char *buf, int total, int bytes)
{
	char	*new;
	int		i;

	new = malloc(total + bytes + 1);
	if (!new)
		return (0);
	i = 0;
	while (i < total)
	{
		new[i] = res[i];
		i++;
	}
	i = 0;
	while (i < bytes)
	{
		new[total + i] = buf[i];
		i++;
	}
	new[total + bytes] = '\0';
	free(res);
	return (new);
}

char	*load_dict(char *filename)
{
	int		fd;
	int		bytes;
	int		total;
	char	buffer[1024];
	char	*res;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	res = 0;
	total = 0;
	bytes = read(fd, buffer, 1024);
	while (bytes > 0)
	{
		res = append_buffer(res, buffer, total, bytes);
		if (!res)
			return (0);
		total = total + bytes;
		bytes = read(fd, buffer, 1024);
	}
	close(fd);
	return (res);
}
