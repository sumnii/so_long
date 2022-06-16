#ifndef SOLONG_H
# define SOLONG_H

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "map.h"
# include "window.h"
# include "key.h"
# include <stdio.h>

int map_width;
int map_height;

int	open_map(char *mapfile);

#endif