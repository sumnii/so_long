/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:02:11 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/22 02:13:09 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong.h"

int	draw_map(t_game *game)
{
	draw_tiles(game, game->map);
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
	else
		mlx_put_image_to_window(g->mlx, g->win,
			g->tile.t_p.img, j * 32, i * 32);
}
