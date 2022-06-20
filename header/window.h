/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:47:00 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/20 18:49:22 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "solong.h"

# define WIDTH 400
# define HEIGHT 400

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
}				t_tile;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	t_tile	tile;
}				t_game;

void	make_window(t_map *map_info);
int		handle_key(int key_code, t_game *game);
int		close_window(t_game *game);
void	set_tiles(t_game *game);

#endif