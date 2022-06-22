/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:50:35 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/23 00:13:32 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong.h"

void	map_valid_check(t_map *map_info, int line_cnt)
{
	if (map_rectangle_check(map_info, line_cnt - 1) == -1)
	{
		printf("Error!\nisn't rectangle.\n");
		exit(1);
	}
	else if (map_components_check(map_info, line_cnt) == -1)
	{
		printf("Error!\nincorrect components.\n");
		exit(1);
	}
	else if (map_wall_check(map_info) == -1)
	{
		printf("Error!\nisn't surrounded.\n");
		exit(1);
	}
}

int	map_rectangle_check(t_map *map_info, int y)
{
	int	x;
	int	x_cnt;
	int	cur_cnt;

	x = -1;
	x_cnt = 0;
	while (map_info->map[y][++x])
		++x_cnt;
	--y;
	while (y >= 0)
	{
		cur_cnt = 0;
		x = 0;
		while (map_info->map[y][x])
		{
			++cur_cnt;
			++x;
		}
		if (x_cnt != cur_cnt)
			return (-1);
		--y;
	}
	map_info->x = x_cnt;
	return (1);
}

int	map_components_check(t_map *map_info, int line_cnt)
{
	t_compo	*compo;

	compo = map_components_count(map_info, line_cnt);
	if (compo == NULL)
		return (-1);
	else if (compo->cnt_p > 1)
		return (-1);
	else if (compo->cnt_c && compo->cnt_e && compo->cnt_p)
		return (1);
	else
		return (-1);
}

t_compo	*map_components_count(t_map *map_info, int line_cnt)
{
	int	x;
	int	y;

	y = -1;
	while (++y < line_cnt)
	{
		x = -1;
		while (map_info->map[y][++x])
		{
			if (map_info->map[y][x] == 'C')
				++(map_info->compos.cnt_c);
			else if (map_info->map[y][x] == 'E')
				++(map_info->compos.cnt_e);
			else if (map_info->map[y][x] == 'P')
				++(map_info->compos.cnt_p);
			else if (map_info->map[y][x] != '0' && map_info->map[y][x] != '1')
				return (NULL);
		}
	}
	return (&(map_info->compos));
}

int	map_wall_check(t_map *map_info)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_info->y)
	{
		x = 0;
		while (x < map_info->x)
		{
			if (x == 0 || x == map_info->x - 1 || y == 0
				|| y == map_info->y - 1)
				if (map_info->map[y][x] != '1')
					return (-1);
			++x;
		}
		++y;
	}
	return (1);
}
