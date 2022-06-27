# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 18:52:44 by sumsong           #+#    #+#              #
#    Updated: 2022/06/27 15:52:03 by sumsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
NAME_BONUS	=	so_long_bonus

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
AR			=	ar rcs
RM			=	rm -f

SRC_DIR		=	./
GNL_DIR		=	./gnl/
LIBFT_DIR	=	./libft/
MLX_DIR		=	./mlx/

MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit
LIBFT_FLAGS	=	-L$(LIBFT_DIR) -lft

SRC			=	main.c map_load.c map_check.c window.c key_handle.c draw_map.c
GNL_SRC		=	get_next_line.c get_next_line_utils.c
BONUS_SRC	=	main_bonus.c map_load_bonus.c map_check_bonus.c window_bonus.c \
				key_handle_bonus.c draw_map_bonus.c player_moving_bonus.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC)) $(addprefix $(GNL_DIR), $(GNL_SRC))
OBJS		=	$(SRCS:.c=.o)

BONUS_SRCS	=	$(addprefix $(SRC_DIR), $(BONUS_SRC)) $(addprefix $(GNL_DIR), $(GNL_SRC))
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)


all: $(NAME)

clean:
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re: clean all

bonus: $(NAME_BONUS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	$(CC) -o $@ $(MLX_FLAGS) $(LIBFT_FLAGS) $(OBJS)

$(NAME_BONUS): $(BONUS_OBJS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	$(CC) -o $@ $(MLX_FLAGS) $(LIBFT_FLAGS) $(BONUS_OBJS)

PHONY: all clean fclean re bonus