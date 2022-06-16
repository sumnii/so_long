NAME		= so_long

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR			= ar rcs
RM			= rm -f

INCS_DIR	= ./header/
SRCS_DIR	= ./
MLX_DIR		= ./mlx/

INCS		= -I include
MLX_FLAGS	= -L./mlx -lmlx -framework OpenGL -framework Appkit

SRC			=	main.c map_load.c map_check.c window.c \
				gnl/get_next_line.c gnl/get_next_line_utils.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
OBJS		=	$(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(SRCS) -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

all : $(NAME)

clean :
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : clean all

PHONY	: all clean fclean re