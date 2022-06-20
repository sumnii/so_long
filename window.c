/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:42:56 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/20 18:49:11 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong.h"

void	make_window(t_map *map)
{
	t_game	g;
	int		i;
	int		j;

	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, map->x * 32, map->y * 32, "test");
	set_tiles(&g);
	j = 0;
	while (j <= map->y * 32)
	{
		i = 0;
		while (i <= map->x * 32)
		{
			mlx_put_image_to_window(g.mlx, g.win, g.tile.t_0.img, i, j);
			i += 32;
		}
		j += 32;
	}
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
	game->tile.t_0.img = mlx_png_file_to_image(game->mlx, "./assets/tile.png",
			&game->tile.t_0.img_width, &game->tile.t_0.img_height);
	game->tile.t_1.img = mlx_png_file_to_image(game->mlx, "./assets/tile.png",
			&game->tile.t_1.img_width, &game->tile.t_1.img_height);
	game->tile.t_c.img = mlx_png_file_to_image(game->mlx, "./assets/tile.png",
			&game->tile.t_c.img_width, &game->tile.t_c.img_height);
	game->tile.t_e.img = mlx_png_file_to_image(game->mlx, "./assets/tile.png",
			&game->tile.t_e.img_width, &game->tile.t_e.img_height);
	game->tile.t_p.img = mlx_png_file_to_image(game->mlx, "./assets/tile.png",
			&game->tile.t_p.img_width, &game->tile.t_p.img_height);
}
