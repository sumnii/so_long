#include "solong.h"

int	map_line_count(void)
{
	int	fd;
	int checker;
	int	line_cnt;

	fd = open("../map/test.ber", O_RDONLY);
	if (fd == -1)
	{
		printf("map open error.\n");
		exit(1);
	}
	checker = 0;
	line_cnt = 0;
	while (checker == 0)
	{
		if (get_next_line(fd) != 0)
			++line_cnt;
		else
			checker = -1;
	}
	return(line_cnt);
}

void	map_read(int line_cnt, char ***map)
{
	int 	fd;
	int		y;

	fd = open("../map/test.ber", O_RDONLY);
	if (fd == -1)
	{
		printf("map open error.\n");
		exit(1);
	}
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

void	map_valid_check(void)
{
	char	**map;
	int 	line_cnt;
	int 	y = 0;

	line_cnt = map_line_count();
	map_read(line_cnt, &map);
	/* print map */
	while (y < line_cnt)
	{
		printf("%d : %s", y, map[y]);
		++y;
	}
}