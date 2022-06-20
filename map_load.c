/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:51:17 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/20 18:51:36 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	map_load(char *map_target, t_map **map_info)
{
	int	fd;
	int	line_cnt;

	fd = open_map(map_target);
	line_cnt = map_line_count(fd);
	close(fd);
	fd = open_map(map_target);
	map_read(line_cnt, &((*map_info)->map), fd);
	close(fd);
	map_valid_check(map_info, line_cnt);
	(*map_info)->y = line_cnt;
}
