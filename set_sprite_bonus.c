/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:56:12 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/22 20:59:51 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong_bonus.h"

void	set_player_sprite(t_game *g)
{
	set_sprite_w(g);
	set_sprite_s(g);
	set_sprite_a(g);
	set_sprite_d(g);
}

void	set_sprite_w(t_game *g)
{
	g->tile.spr.p_w[0].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_w1.xpm",
			&g->tile.spr.p_w[0].img_width, &g->tile.spr.p_w[0].img_height);
	g->tile.spr.p_w[1].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_w2.xpm",
			&g->tile.spr.p_w[1].img_width, &g->tile.spr.p_w[1].img_height);
	g->tile.spr.p_w[2].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_w1.xpm",
			&g->tile.spr.p_w[2].img_width, &g->tile.spr.p_w[2].img_height);
	g->tile.spr.p_w[3].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_w3.xpm",
			&g->tile.spr.p_w[3].img_width, &g->tile.spr.p_w[3].img_height);
}

void	set_sprite_s(t_game *g)
{
	g->tile.spr.p_s[0].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_s1.xpm",
			&g->tile.spr.p_s[0].img_width, &g->tile.spr.p_s[0].img_height);
	g->tile.spr.p_s[1].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_s2.xpm",
			&g->tile.spr.p_s[1].img_width, &g->tile.spr.p_s[1].img_height);
	g->tile.spr.p_s[2].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_s1.xpm",
			&g->tile.spr.p_s[2].img_width, &g->tile.spr.p_s[2].img_height);
	g->tile.spr.p_s[3].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_s3.xpm",
			&g->tile.spr.p_s[3].img_width, &g->tile.spr.p_s[3].img_height);
}

void	set_sprite_a(t_game *g)
{
	g->tile.spr.p_a[0].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_a1.xpm",
			&g->tile.spr.p_a[0].img_width, &g->tile.spr.p_a[0].img_height);
	g->tile.spr.p_a[1].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_a2.xpm",
			&g->tile.spr.p_a[1].img_width, &g->tile.spr.p_a[1].img_height);
	g->tile.spr.p_a[2].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_a1.xpm",
			&g->tile.spr.p_a[2].img_width, &g->tile.spr.p_a[2].img_height);
	g->tile.spr.p_a[3].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_a3.xpm",
			&g->tile.spr.p_a[3].img_width, &g->tile.spr.p_a[3].img_height);
}

void	set_sprite_d(t_game *g)
{
	g->tile.spr.p_d[0].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_d1.xpm",
			&g->tile.spr.p_d[0].img_width, &g->tile.spr.p_d[0].img_height);
	g->tile.spr.p_d[1].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_d2.xpm",
			&g->tile.spr.p_d[1].img_width, &g->tile.spr.p_d[1].img_height);
	g->tile.spr.p_d[2].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_d1.xpm",
			&g->tile.spr.p_d[2].img_width, &g->tile.spr.p_d[2].img_height);
	g->tile.spr.p_d[3].img = mlx_xpm_file_to_image(g->mlx, "./assets/p_d3.xpm",
			&g->tile.spr.p_d[3].img_width, &g->tile.spr.p_d[3].img_height);
}
