/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:50:02 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/21 01:11:43 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_CLOSE 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

int		handle_key(int key_code, t_game **game);
void	press_key_up(t_game **g);
int		close_window(t_game *game);

#endif