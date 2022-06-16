#include "header/solong.h"

void make_window(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "test");
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &handle_key, &game);
	mlx_hook(game.win, X_EVENT_CLOSE, 0, &close_window, &game);
	mlx_loop(game.mlx);
}

int handle_key(int key_code, t_game *game)
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
