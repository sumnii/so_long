#ifndef WINDOW_H
# define WINDOW_H

#include "solong.h"

#define WIDTH 400
#define HEIGHT 400

typedef struct	s_img
{
	void	*img;
	int 	img_width;
	int 	img_height;
}				t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_game;

void	make_window(void);
int 	handle_key(int key_code, t_game *game);
int		close_window(t_game *game);

#endif