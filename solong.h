#ifndef SOLONG_H
# define SOLONG_H

#include "get_next_line.h"
#include <stdio.h>

int		map_line_count(void);
void	map_read(int line_cnt, char ***map);
void	map_valid_check(void);

#endif