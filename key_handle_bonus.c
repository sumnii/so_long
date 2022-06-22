/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:32:33 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/22 18:35:52 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong_bonus.h"

int	handle_key(int key_code, t_game **g)
{
	if (key_code == KEY_ESC)
		close_window(g);
	if (key_code == KEY_W || key_code == KEY_S || key_code == KEY_A
		|| key_code == KEY_D)
	{
		if (key_code == KEY_W)
			press_key_up(g);
		else if (key_code == KEY_S)
			press_key_down(g);
		else if (key_code == KEY_A)
			press_key_left(g);
		else
			press_key_right(g);
	}
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
	}
	else if ((*g)->map.map[y - 1][x] == 'E' && (*g)->map.compos.cnt_c != 0)
		printf("You need to collect more firewood.\n");
	else if ((*g)->map.map[y - 1][x] == 'E' || (*g)->map.map[y - 1][x] == 'X')
	{
		if ((*g)->map.map[y - 1][x] == 'X')
			printf("You lose! Don't contact the ice spike!\n");
		else if ((*g)->map.compos.cnt_c == 0)
			printf("Success in %d steps!\n", (*g)->p.step + 1);
		close_window(g);
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
	}
	else if ((*g)->map.map[y + 1][x] == 'E' && (*g)->map.compos.cnt_c != 0)
		printf("You need to collect more firewood.\n");
	else if ((*g)->map.map[y + 1][x] == 'E' || (*g)->map.map[y + 1][x] == 'X')
	{
		if ((*g)->map.map[y + 1][x] == 'X')
			printf("You lose! Don't contact the ice spike!\n");
		else if ((*g)->map.compos.cnt_c == 0)
			printf("Success in %d steps!\n", (*g)->p.step + 1);
		close_window(g);
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
	}
	else if ((*g)->map.map[y][x - 1] == 'E' && (*g)->map.compos.cnt_c != 0)
		printf("You need to collect more firewood.\n");
	else if ((*g)->map.map[y][x - 1] == 'E' || (*g)->map.map[y][x - 1] == 'X')
	{
		if ((*g)->map.map[y][x - 1] == 'X')
			printf("You lose! Don't contact the ice spike!\n");
		else if ((*g)->map.compos.cnt_c == 0)
			printf("Success in %d steps!\n", (*g)->p.step + 1);
		close_window(g);
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
	}
	else if ((*g)->map.map[y][x + 1] == 'E' && (*g)->map.compos.cnt_c != 0)
		printf("You need to collect more firewood.\n");
	else if ((*g)->map.map[y][x + 1] == 'E' || (*g)->map.map[y][x + 1] == 'X')
	{
		if ((*g)->map.map[y][x + 1] == 'X')
			printf("You lose! Don't contact the ice spike!\n");
		else if ((*g)->map.compos.cnt_c == 0)
			printf("Success in %d steps!\n", (*g)->p.step + 1);
		close_window(g);
	}
}
