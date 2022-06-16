#include "header/solong.h"

int	map_line_count(int fd)
{
	int	checker;
	int	line_cnt;

	checker = 0;
	line_cnt = 0;
	while (checker == 0)
	{
		if (get_next_line(fd) != 0)
			++line_cnt;
		else
			checker = -1;
	}
	return (line_cnt);
}

void	map_read(int line_cnt, char ***map, int fd)
{
	int		y;

	y = 0;
	*map = (char **)malloc(sizeof(char *) * line_cnt);
	while (y < line_cnt)
	{
		(*map)[y] = get_next_line(fd);
		if ((*map)[y] == NULL)
		{
			printf("gnl func error.\n");
			exit(1);
		}
		++y;
	}
	close(fd);
}

int	map_load(char *mapfile, char ***map)
{
	int	fd;
	int	line_cnt;

	fd = open_map(mapfile);
	line_cnt = map_line_count(fd);
	close(fd);
	fd = open_map(mapfile);
	map_read(line_cnt, map, fd);
	close(fd);
	return (line_cnt);
}
