/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:32:33 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/21 02:08:37 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong.h"

int	handle_key(int key_code, t_game **g)
{
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_W)
	{
		press_key_up(g);
		printf("(%d, %d) step : %d\n", (*g)->p.cur_x, (*g)->p.cur_y, (*g)->p.step);
	}
	return (0);
}

int	close_window(t_game *game)
{
	(void)game;
	exit(0);
}

void	press_key_up(t_game **g)
{
	int	x;
	int	y;

	x = (*g)->p.cur_x;
	y = (*g)->p.cur_y;
	if ((*g)->map.map[y - 1][x] == '0' || (*g)->map.map[y - 1][x] == 'C')
	{
		(*g)->p.cur_y -= 1;
		(*g)->p.step += 1;
		(*g)->map.map[y][x] = '0';
		(*g)->map.map[y - 1][x] = 'P';
		if ((*g)->map.map[y - 1][x] == 'C')
			(*g)->map.compos.cnt_c -= 1;
	}
	else if ((*g)->map.map[y - 1][x] == 'E')
	{
		if ((*g)->map.compos.cnt_c == 0)
			exit(0);
	}
}
