#include "header/solong.h"

void	map_valid_check(char *mapfile)
{
	char	**map;
	int		line_cnt;
	int		y;

	line_cnt = map_load(mapfile, &map);
	if (map_components_check(map, line_cnt) == -1)
	{
		// 0, 1, C, E, P로만 구성되었는지, C, E, P가 최소 하나 이상 있는지
		printf("Error!\ndoesn't have necessary components.\n");
		exit(1);
	}
	else if (map_rectangle_check(map, line_cnt - 1) == -1)
	{
		printf("Error!\nisn't rectangle.\n");
		exit(1);
	}
	else if (map_wall_check(map, line_cnt - 1) == -1)
	{
		printf("Error!\nisn't surrounded.\n");
		exit(1);
	}
	/* print map */
	y = 0;
	printf("   [0123456789012]\n");
	while (y < line_cnt)
	{
		printf("%d : %s\n", y, map[y]);
		++y;
	}
}

t_map	*map_components_count(char **map, int line_cnt)
{
	int		x;
	int		y;
	t_map	*compo;

	compo = (t_map *)calloc(1, sizeof(t_map));
	y = -1;
	while (++y < line_cnt)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				++(compo->cnt_1);
			else if (map[y][x] == '0')
				++(compo->cnt_0);
			else if (map[y][x] == 'C')
				++(compo->cnt_c);
			else if (map[y][x] == 'E')
				++(compo->cnt_e);
			else
				++(compo->cnt_p);
		}
	}
	return (compo);
}

int	map_components_check(char **map, int line_cnt)
{
	t_map	*compo;

	compo = map_components_count(map, line_cnt);
	if (compo->cnt_1 && compo->cnt_c && compo->cnt_e && compo->cnt_p)
	{
		free(compo);
		return (1);
	}
	else
	{
		free(compo);
		return (-1);
	}
}

int	map_wall_check(char **map, int y)
{
	int	x;

	x = 0;
	while (map[0][x])
	{
		if (map[0][x] != '1')
			return (-1);
		++x;
	}
	x = 0;
	while (map[y][x])
	{
		if (map[y][x] != '1')
			return (-1);
		++x;
	}
	return (1);
}

int	map_rectangle_check(char **map, int y)
{
	int	x;
	int	x_cnt;
	int	cur_cnt;

	x = -1;
	x_cnt = 0;
	while (map[y][++x])
		++x_cnt;
	--y;
	while (y >= 0)
	{
		cur_cnt = 0;
		x = 0;
		while (map[y][x])
		{
			++cur_cnt;
			++x;
		}
		if (x_cnt != cur_cnt)
			return (-1);
		--y;
	}
	return (1);
}
