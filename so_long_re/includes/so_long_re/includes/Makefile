NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = so_long.c \
       ft_check_arguments.c \
       ft_init_map.c \
       ft_check_line.c \
       ft_init_vars.c \
       ft_check_map.c \
       ft_check_rows.c \
       ft_check_cell.c \
       ft_check_columns.c \
       ft_count_params.c \
       ft_verify_map.c \
       ft_load_image.c \
       ft_init_mlx.c \
       ft_init_sprites.c \
       ft_new_sprite.c \
       ft_render_map.c \
       ft_identify_sprite.c \
       ft_render_player.c \
       ft_handle_movements.c \
       ft_check_for_collectible.c \
       ft_check_for_exit.c \
       ft_render_collectibles.c \
       ft_render_image.c \
       ft_render_exit.c \
       ft_render_movements.c \
       ft_render_game_over.c \
       ft_exit_game.c \
       ft_exit_error.c \
       ft_get_key.c \
       ft_get_input.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ../libftproject
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I $(LIBFT_DIR)

GNL_DIR = ../get_next_line
GNL_LIB = $(GNL_DIR)/get_next_line.a
GNL_INC = -I $(GNL_DIR)

MLX_DIR = ./minilibx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_INC = -I $(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(GNL_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(GNL_LIB) $(MLX_LIB) -lXext -lX11 -lm -o $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBFT_INC) $(GNL_INC) $(MLX_INC)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
