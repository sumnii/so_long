/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:47:00 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/22 18:22:27 by sumsong          ###   ########.fr       */
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

typedef struct s_tile
{
	t_img	t_1;
	t_img	t_0;
	t_img	t_c;
	t_img	t_e;
	t_img	t_p;
	t_img	t_x;
	t_img	back;
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

int		draw_map(t_game *game);
void	draw_step(t_game *g);
void	draw_tiles(t_game *game, t_map map);
void	put_tile(t_game *g, char compo, int i, int j);

#endif