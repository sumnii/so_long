#ifndef MAP_H
# define MAP_H

typedef struct s_map {
	int	cnt_1;
	int	cnt_0;
	int	cnt_c;
	int	cnt_e;
	int	cnt_p;
}				t_map;

int		map_line_count(int fd);
void	map_read(int line_cnt, char ***map, int fd);
int		map_load(char *mapfile, char ***map);

void	map_valid_check(char *mapfile);
t_map	*map_components_count(char **map, int line_cnt);
int		map_components_check(char **map, int line_cnt);
int		map_wall_check(char **map, int y);
int		map_rectangle_check(char **map, int y);

#endif