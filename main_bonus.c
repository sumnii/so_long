/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:50:20 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/23 00:27:33 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/solong_bonus.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
	{
		printf("type => \"./so_long <map file>\"\n");
		exit(1);
	}
	if (ber_check(argv[1]) == 1)
	{
		printf("map file isn't '.ber' file.\n");
		exit(1);
	}
	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (1);
	map_load(argv[1], &(game->map));
	make_window(game);
}

int	ber_check(char *map_file)
{
	size_t	len;
	char	*target;

	len = ft_strlen(map_file);
	if (len < 4)
		return (1);
	target = ft_strnstr(map_file, ".ber", len);
	if (!target || ft_strlen(target) != 4)
		return (1);
	return (0);
}
