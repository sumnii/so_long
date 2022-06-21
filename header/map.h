/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:49:24 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/22 01:59:02 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_compo {
	int		cnt_1;
	int		cnt_0;
	int		cnt_c;
	int		cnt_e;
	int		cnt_p;
}			t_compo;

typedef struct s_map {
	char	**map;
	int		x;
	int		y;
	t_compo	compos;
}				t_map;

void	map_load(char *mapfile, t_map *map_info);
int		open_map(char *map_target);
int		map_line_count(int fd);
void	map_read(int line_cnt, char ***map, int fd);

void	map_valid_check(t_map *map_info, int line_cnt);
int		map_rectangle_check(t_map *map_info, int y);
int		map_components_check(t_map *map_info, int line_cnt);
t_compo	*map_components_count(t_map *map_info, int line_cnt);
int		map_wall_check(t_map *map_info, int y);

#endif