/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:50:02 by sumsong           #+#    #+#             */
/*   Updated: 2022/06/27 16:12:12 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_BONUS_H
# define KEY_BONUS_H

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_CLOSE 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

int		handle_key(int key_code, t_game **game);
void	press_key_up(t_game **g);
void	press_key_down(t_game **g);
void	press_key_left(t_game **g);
void	press_key_right(t_game **g);

#endif