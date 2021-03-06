/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:42:56 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/28 22:37:43 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong_bonus.h"

void	make_window(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, (g->map.x) * 32,
			(g->map.y) * 32 + 32, "so_long");
	set_tiles(g);
	set_player_sprite(g);
	set_player(g);
	draw_map(g);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &handle_key, &g);
	mlx_hook(g->win, X_EVENT_CLOSE, 0, &close_window, &g);
	mlx_loop_hook(g->mlx, &draw_map, g);
	mlx_loop(g->mlx);
}

void	set_tiles(t_game *game)
{
	game->tile.t_0.img = mlx_xpm_file_to_image(game->mlx, "./assets/0.xpm",
			&game->tile.t_0.img_width, &game->tile.t_0.img_height);
	game->tile.t_1.img = mlx_xpm_file_to_image(game->mlx, "./assets/1.xpm",
			&game->tile.t_1.img_width, &game->tile.t_1.img_height);
	game->tile.t_c.img = mlx_xpm_file_to_image(game->mlx, "./assets/c.xpm",
			&game->tile.t_c.img_width, &game->tile.t_c.img_height);
	game->tile.t_e.img = mlx_xpm_file_to_image(game->mlx, "./assets/e.xpm",
			&game->tile.t_e.img_width, &game->tile.t_e.img_height);
	game->tile.t_p.img = mlx_xpm_file_to_image(game->mlx, "./assets/p.xpm",
			&game->tile.t_p.img_width, &game->tile.t_p.img_height);
	game->tile.t_x[0].img = mlx_xpm_file_to_image(game->mlx, "./assets/x1.xpm",
			&game->tile.t_x[0].img_width, &game->tile.t_x[0].img_height);
	game->tile.t_x[1].img = mlx_xpm_file_to_image(game->mlx, "./assets/x2.xpm",
			&game->tile.t_x[1].img_width, &game->tile.t_x[1].img_height);
}

int	set_player(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->map.y)
	{
		j = -1;
		while (++j < g->map.x)
		{
			if (g->map.map[i][j] == 'P')
			{
				g->p.cur_x = j;
				g->p.cur_y = i;
				g->p.step = 0;
				break ;
			}
		}
	}
	return (0);
}

int	close_window(t_game **game)
{
	int	y;

	y = (*game)->map.y;
	while (--y >= 0)
		free((*game)->map.map[y]);
	free((*game)->map.map);
	free(*game);
	exit(0);
}
