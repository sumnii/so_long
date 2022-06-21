/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:50:20 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/21 15:32:56 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

//	if (argc != 2)
//	{
//		printf("type => \"./so_long <map file>\"\n");
//		exit(1);
//	}
	(void)argc;
	(void)argv[1];
	// 빠른 컴파일을 위해 임시로 맵파일명 설정해둠
	char	*map_target = "./map/test2.ber";

	game = (t_game *)malloc(sizeof(t_game));
	map_load(map_target, &(game->map));

	/* print map */
	int y = 0;
	printf("x : %d, y : %d\n", game->map.x, game->map.y);
	printf("   [0123456789012]\n");
	while (y < game->map.y)
	{
		printf("%d : %s\n", y, game->map.map[y]);
		++y;
	}

	make_window(&game);
}

int	open_map(char *map_target)
{
	int	fd;

	fd = open(map_target, O_RDONLY);
	if (fd == -1)
	{
		printf("Error!\nmap open error. check the map file's name.\n");
		exit(1);
	}
	return (fd);
}
