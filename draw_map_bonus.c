/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:02:11 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/23 16:44:47 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong_bonus.h"

int	draw_map(t_game *game)
{
	draw_tiles(game, game->map);
	draw_step(game);
	return (0);
}

void	draw_tiles(t_game *g, t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.y)
	{
		j = 0;
		while (j < map.x)
		{
			put_tile(g, map.map[i][j], i, j);
			++j;
		}
		++i;
	}
}

void	put_tile(t_game *g, char compo, int i, int j)
{
	if (compo == '1')
		mlx_put_image_to_window(g->mlx, g->win,
			g->tile.t_1.img, j * 32, i * 32);
	else if (compo == '0')
		mlx_put_image_to_window(g->mlx, g->win,
			g->tile.t_0.img, j * 32, i * 32);
	else if (compo == 'C')
		mlx_put_image_to_window(g->mlx, g->win,
			g->tile.t_c.img, j * 32, i * 32);
	else if (compo == 'E')
		mlx_put_image_to_window(g->mlx, g->win,
			g->tile.t_e.img, j * 32, i * 32);
	else if (compo == 'P')
		mlx_put_image_to_window(g->mlx, g->win,
			g->tile.t_p.img, j * 32, i * 32);
	else
		enemy_sprite(g, i, j);
}

void	enemy_sprite(t_game *g, int i, int j)
{
	static int	cnt = -1;

	if (cnt++ < 20)
		mlx_put_image_to_window(g->mlx, g->win,
			g->tile.t_x[0].img, j * 32, i * 32);
	else if (40 < cnt)
		cnt = -1;
	else
		mlx_put_image_to_window(g->mlx, g->win,
			g->tile.t_x[1].img, j * 32, i * 32);
}

void	draw_step(t_game *g)
{
	char	*step;
	int		x;

	step = ft_itoa(g->p.step);
	g->tile.back.img = mlx_xpm_file_to_image(g->mlx, "./assets/back.xpm",
			&g->tile.back.img_width, &g->tile.back.img_height);
	x = -1;
	while (++x < g->map.x)
	{
		mlx_put_image_to_window(g->mlx, g->win,
			g->tile.back.img, x * 32, g->map.y * 32);
	}
	mlx_string_put(g->mlx, g->win, 16, g->map.y * 32 + 16, 0xffffff, "step");
	mlx_string_put(g->mlx, g->win, 50, g->map.y * 32 + 16, 0xffffff, step);
	free(step);
}
