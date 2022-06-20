/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:49:43 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/20 18:49:53 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "map.h"
# include "window.h"
# include "key.h"
# include <stdio.h>

int	open_map(char *map_target);

#endif