/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:50:35 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/20 18:51:08 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong.h"

void	map_valid_check(t_map **map_info, int line_cnt)
{
	if (map_components_check(map_info, line_cnt) == -1)
	{
		// 0, 1, C, E, P로만 구성되었는지, C, E, P가 최소 하나 이상 있는지
		printf("Error!\ndoesn't have necessary components.\n");
		exit(1);
	}
	else if (map_rectangle_check(map_info, line_cnt - 1) == -1)
	{
		printf("Error!\nisn't rectangle.\n");
		exit(1);
	}
	else if (map_wall_check(map_info, line_cnt - 1) == -1)
	{
		printf("Error!\nisn't surrounded.\n");
		exit(1);
	}
}

t_compo	*map_components_count(t_map **map_info, int line_cnt)
{
	int		x;
	int		y;

	(*map_info)->compos = (t_compo *)calloc(1, sizeof(t_compo));
	y = -1;
	while (++y < line_cnt)
	{
		x = -1;
		while ((*map_info)->map[y][++x])
		{
			if ((*map_info)->map[y][x] == '1')
				++((*map_info)->compos->cnt_1);
			else if ((*map_info)->map[y][x] == '0')
				++((*map_info)->compos->cnt_0);
			else if ((*map_info)->map[y][x] == 'C')
				++((*map_info)->compos->cnt_c);
			else if ((*map_info)->map[y][x] == 'E')
				++((*map_info)->compos->cnt_e);
			else
				++((*map_info)->compos->cnt_p);
		}
	}
	return ((*map_info)->compos);
}

int	map_components_check(t_map **map_info, int line_cnt)
{
	t_compo	*compo;

	compo = map_components_count(map_info, line_cnt);
	if (compo->cnt_1 && compo->cnt_c && compo->cnt_e && compo->cnt_p)
	{
		free((*map_info)->compos);
		(*map_info)->compos = 0;
		return (1);
	}
	else
		return (-1);
}

int	map_wall_check(t_map **map_info, int y)
{
	int	x;

	x = 0;
	while ((*map_info)->map[0][x])
	{
		if ((*map_info)->map[0][x] != '1')
			return (-1);
		++x;
	}
	x = 0;
	while ((*map_info)->map[y][x])
	{
		if ((*map_info)->map[y][x] != '1')
			return (-1);
		++x;
	}
	return (1);
}

int	map_rectangle_check(t_map **map_info, int y)
{
	int	x;
	int	x_cnt;
	int	cur_cnt;

	x = -1;
	x_cnt = 0;
	while ((*map_info)->map[y][++x])
		++x_cnt;
	--y;
	while (y >= 0)
	{
		cur_cnt = 0;
		x = 0;
		while ((*map_info)->map[y][x])
		{
			++cur_cnt;
			++x;
		}
		if (x_cnt != cur_cnt)
			return (-1);
		--y;
	}
	(*map_info)->x = x_cnt;
	return (1);
}
