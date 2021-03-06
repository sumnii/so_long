/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:51:17 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/28 22:40:00 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong.h"

void	map_load(char *map_target, t_map *map_info)
{
	int	fd;
	int	line_cnt;

	fd = open_map(map_target);
	line_cnt = map_line_count(fd);
	map_info->y = line_cnt;
	close(fd);
	fd = open_map(map_target);
	map_read(line_cnt, &(map_info->map), fd);
	close(fd);
	map_valid_check(map_info, line_cnt);
}

int	open_map(char *map_target)
{
	int	fd;

	fd = open(map_target, O_RDONLY);
	if (fd == -1)
	{
		printf("Error!\nmap open error. check the map file's name.\n");
		exit(1);
	}
	return (fd);
}

int	map_line_count(int fd)
{
	int		line_cnt;
	char	*line;

	line_cnt = 0;
	line = NULL;
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			++line_cnt;
		else
			break ;
	}
	return (line_cnt);
}

void	map_read(int line_cnt, char ***map, int fd)
{
	int		y;

	y = 0;
	*map = (char **)malloc(sizeof(char *) * line_cnt);
	if (!(*map))
		exit(1);
	while (y < line_cnt)
	{
		(*map)[y] = get_next_line(fd);
		if ((*map)[y] == NULL)
		{
			printf("gnl func error.\n");
			while (0 <= --y)
				free((*map)[y]);
			free(*map);
			exit(1);
		}
		++y;
	}
	close(fd);
}
