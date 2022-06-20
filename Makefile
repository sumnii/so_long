# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 18:52:44 by sumsong           #+#    #+#              #
#    Updated: 2022/06/21 02:05:30 by sumsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

SRC1_DIR	= ./
SRC2_DIR	= ./gnl/
MLX_DIR		= ./mlx/

MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit -lz

SRC1		=	main.c map_load.c map_check.c window.c key_handle.c draw_map.c
SRC2		=	get_next_line.c get_next_line_utils.c

SRCS		=	$(addprefix $(SRC1_DIR), $(SRC1)) $(addprefix $(SRC2_DIR), $(SRC2))
OBJS		=	$(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	-arch -x86_64 $(CC) -o $@ $(MLX_FLAGS) $(OBJS)

all: $(NAME)

clean:
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

PHONY: all clean fclean re