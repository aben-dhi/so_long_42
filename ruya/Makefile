NAME	= so_long

SRCS	= so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c parse_map/check_ext.c \
		parse_map/check_shape.c parse_map/map_check.c parse_map/path_check.c mlx/ft_init_mlx.c mlx/init_images.c \
		 mlx/movement_count.c libft/ft_split.c libft/ft_strcmp.c libft/ft_itoa.c mlx/handle_movement.c mlx/key_input.c\
		parse_map/full_check.c
OBJS	= $(SRCS:.c=.o)

CC		= cc

FLAGS	= -Wall -Wextra -Werror

MLX		= -lmlx -framework OpenGL -framework AppKit

.PHONY = all clean fclean re

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(MLX) $(OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all