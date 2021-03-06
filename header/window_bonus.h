/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:47:00 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/27 16:02:01 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_BONUS_H
# define WINDOW_BONUS_H

typedef struct s_player
{
	int		step;
	int		cur_x;
	int		cur_y;
}				t_player;

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_sprite
{
	t_img	p_w[4];
	t_img	p_a[4];
	t_img	p_s[4];
	t_img	p_d[4];
}				t_sprite;

typedef struct s_tile
{
	t_img		t_1;
	t_img		t_0;
	t_img		t_c;
	t_img		t_e;
	t_img		t_p;
	t_img		t_x[2];
	t_img		back;
	t_sprite	spr;
}				t_tile;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	p;
	t_tile		tile;
}				t_game;

void	make_window(t_game *g);
void	set_tiles(t_game *game);
int		set_player(t_game *g);
int		close_window(t_game **game);

void	set_player_sprite(t_game *g);
void	set_sprite_w(t_game *g);
void	set_sprite_s(t_game *g);
void	set_sprite_a(t_game *g);
void	set_sprite_d(t_game *g);

int		draw_map(t_game *game);
void	draw_tiles(t_game *game, t_map map);
void	enemy_sprite(t_game *g, int i, int j);
void	put_tile(t_game *g, int i, int j, int flag);
void	draw_step(t_game *g);

#endif