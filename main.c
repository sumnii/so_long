/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:50:20 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/20 21:37:24 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong.h"

int	main(int argc, char *argv[])
{
	t_map	*map_info;

//	if (argc != 2)
//	{
//		printf("type => \"./so_long <map file>\"\n");
//		exit(1);
//	}
	(void)argc;
	(void)argv[1];
	// 빠른 컴파일을 위해 임시로 맵파일명 설정해둠
	char	*map_target = "./map/test.ber";

	map_info = (t_map *)malloc(sizeof(map_info));
	map_load(map_target, &map_info);

	/* print map */
	int y = 0;
	printf("x : %d, y : %d\n", map_info->x, map_info->y);
	printf("   [0123456789012]\n");
	while (y < map_info->y)
	{
		printf("%d : %s\n", y, map_info->map[y]);
		++y;
	}

	make_window(map_info);
	//	draw_assets(map_info);
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
