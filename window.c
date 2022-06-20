/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:42:56 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/20 22:42:47 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong.h"

void	make_window(t_map *map)
{
	t_game	g;

	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, (map->x) * 64, (map->y) * 64, "test");
	set_tiles(&g);
	draw_tiles(&g, *map);
	mlx_hook(g.win, X_EVENT_KEY_PRESS, 0, &handle_key, &g);
	mlx_hook(g.win, X_EVENT_CLOSE, 0, &close_window, &g);
	mlx_loop(g.mlx);
}

int	handle_key(int key_code, t_game *game)
{
	(void)game;
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

int	close_window(t_game *game)
{
	(void)game;
	exit(0);
}

void	set_tiles(t_game *game)
{
	game->tile.t_0.img = mlx_png_file_to_image(game->mlx, "./assets/0.png",
			&game->tile.t_0.img_width, &game->tile.t_0.img_height);
	game->tile.t_1.img = mlx_png_file_to_image(game->mlx, "./assets/1.png",
			&game->tile.t_1.img_width, &game->tile.t_1.img_height);
	game->tile.t_c.img = mlx_png_file_to_image(game->mlx, "./assets/c.png",
			&game->tile.t_c.img_width, &game->tile.t_c.img_height);
	game->tile.t_e.img = mlx_png_file_to_image(game->mlx, "./assets/e.png",
			&game->tile.t_e.img_width, &game->tile.t_e.img_height);
	game->tile.t_p.img = mlx_png_file_to_image(game->mlx, "./assets/p.png",
			&game->tile.t_p.img_width, &game->tile.t_p.img_height);
}

void	draw_tiles(t_game *game, t_map map)
{
	static int	i = -1;
	static int	j = -1;

	while (++i < map.y)
	{
		j = -1;
		while (++j < map.x)
		{
			if (map.map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->tile.t_1.img, j * 64, i * 64);
			else if (map.map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->tile.t_0.img, j * 64, i * 64);
			else if (map.map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->tile.t_c.img, j * 64, i * 64);
			else if (map.map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->tile.t_e.img, j * 64, i * 64);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->tile.t_p.img, j * 64, i * 64);
		}
	}
}
