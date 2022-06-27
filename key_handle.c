/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:32:33 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/27 16:15:12 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong.h"

int	handle_key(int key_code, t_game **g)
{
	if (key_code == KEY_ESC)
		close_window(g);
	else if (key_code == KEY_W)
		press_key_up(g);
	else if (key_code == KEY_S)
		press_key_down(g);
	else if (key_code == KEY_A)
		press_key_left(g);
	else if (key_code == KEY_D)
		press_key_right(g);
	else
		printf("It's invalid key. You can press only W, A, S, D and ESC.\n");
	return (0);
}

void	press_key_up(t_game **g)
{
	int	x;
	int	y;

	x = (*g)->p.cur_x;
	y = (*g)->p.cur_y;
	if ((*g)->map.map[y - 1][x] == '0' || (*g)->map.map[y - 1][x] == 'C')
	{
		if ((*g)->map.map[y - 1][x] == 'C')
			(*g)->map.compos.cnt_c -= 1;
		(*g)->p.cur_y -= 1;
		(*g)->p.step += 1;
		(*g)->map.map[y][x] = '0';
		(*g)->map.map[y - 1][x] = 'P';
		printf("step : %d.. %d left.\n", (*g)->p.step, (*g)->map.compos.cnt_c);
	}
	else if ((*g)->map.map[y - 1][x] == 'E')
	{
		if ((*g)->map.compos.cnt_c == 0)
		{
			printf("Success in %d steps!\n", (*g)->p.step + 1);
			close_window(g);
		}
		printf("You need to collect more firewood.\n");
	}
}

void	press_key_down(t_game **g)
{
	int	x;
	int	y;

	x = (*g)->p.cur_x;
	y = (*g)->p.cur_y;
	if ((*g)->map.map[y + 1][x] == '0' || (*g)->map.map[y + 1][x] == 'C')
	{
		if ((*g)->map.map[y + 1][x] == 'C')
			(*g)->map.compos.cnt_c -= 1;
		(*g)->p.cur_y += 1;
		(*g)->p.step += 1;
		(*g)->map.map[y][x] = '0';
		(*g)->map.map[y + 1][x] = 'P';
		printf("step : %d.. %d left.\n", (*g)->p.step, (*g)->map.compos.cnt_c);
	}
	else if ((*g)->map.map[y + 1][x] == 'E')
	{
		if ((*g)->map.compos.cnt_c == 0)
		{
			printf("Success in %d steps!\n", (*g)->p.step + 1);
			close_window(g);
		}
		printf("You need to collect more firewood.\n");
	}
}

void	press_key_left(t_game **g)
{
	int	x;
	int	y;

	x = (*g)->p.cur_x;
	y = (*g)->p.cur_y;
	if ((*g)->map.map[y][x - 1] == '0' || (*g)->map.map[y][x - 1] == 'C')
	{
		if ((*g)->map.map[y][x - 1] == 'C')
			(*g)->map.compos.cnt_c -= 1;
		(*g)->p.cur_x -= 1;
		(*g)->p.step += 1;
		(*g)->map.map[y][x] = '0';
		(*g)->map.map[y][x - 1] = 'P';
		printf("step : %d.. %d left.\n", (*g)->p.step, (*g)->map.compos.cnt_c);
	}
	else if ((*g)->map.map[y][x - 1] == 'E')
	{
		if ((*g)->map.compos.cnt_c == 0)
		{
			printf("Success in %d steps!\n", (*g)->p.step + 1);
			close_window(g);
		}
		printf("You need to collect more firewood.\n");
	}
}

void	press_key_right(t_game **g)
{
	int	x;
	int	y;

	x = (*g)->p.cur_x;
	y = (*g)->p.cur_y;
	if ((*g)->map.map[y][x + 1] == '0' || (*g)->map.map[y][x + 1] == 'C')
	{
		if ((*g)->map.map[y][x + 1] == 'C')
			(*g)->map.compos.cnt_c -= 1;
		(*g)->p.cur_x += 1;
		(*g)->p.step += 1;
		(*g)->map.map[y][x] = '0';
		(*g)->map.map[y][x + 1] = 'P';
		printf("step : %d.. %d left.\n", (*g)->p.step, (*g)->map.compos.cnt_c);
	}
	else if ((*g)->map.map[y][x + 1] == 'E')
	{
		if ((*g)->map.compos.cnt_c == 0)
		{
			printf("Success in %d steps!\n", (*g)->p.step + 1);
			close_window(g);
		}
		printf("You need to collect more firewood.\n");
	}
}
