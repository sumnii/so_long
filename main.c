/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:50:20 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/22 20:51:20 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
	{
		printf("type => \"./so_long <map file>\"\n");
		exit(1);
	}
	game = (t_game *)calloc(sizeof(t_game), 1);
	if (!game)
		return (1);
	map_load(argv[1], &(game->map));
	make_window(game);
}
