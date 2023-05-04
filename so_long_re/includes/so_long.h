/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 03:01:04 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 18:05:25 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include  <errno.h>
#include  <stdlib.h>
// # include <X11/X.h>
// # include <X11/keysym.h>
# include "../Libftproject/libft.h"

// # define IMG_HEIGHT			32
// # define IMG_WIDTH			32
# define EXIT_FAILURE		1
# define EXIT_SUCCESS		0

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_Q				113
# define KEY_ESC  			65307

# define TILE_SIZE			32

# define WHITE				0x00FFFFFF

// # define FRONT				1
// # define LEFT				2
// # define RIGHT				3
// # define BACK				4

# define WALL_XPM			"textures/sprites/wall.xpm"
# define FLOOR_XPM			"textures/sprites/floor.xpm"
# define COINS_XPM			"textures/sprites/coin-bag.xpm"
# define PLAYER_FRONT_XPM		"textures/player/front.xpm"
# define EXIT_XPM		"textures/sprites/exit.xpm"


typedef struct	s_game
{
	bool		map_alloc;
	char		**map;
	int			map_width;
	int			map_height;
	int			map_rows;
	int			map_cols;
	struct {
		int		x;
		int		y;
	}			player;
	int			collectibles;
	int			movements;
	bool		exit_found;
	bool		player_found;
	char        *collectible_path;
   	char        *player_up_path;
   	char        *player_down_path;
   	char        *player_left_path;
   	char        *player_right_path;
   	char        *wall_path;
   	char        *floor_path;
   	char        *exit_closed_path;
   	char        *exit_open_path;
	t_image		*collectible;
	t_image		*player_up;
	t_image		*player_down;
	t_image		*player_left;
	t_image		*player_right;
	t_image		*wall;
	t_image		*floor;
	t_image		*exit_closed;
	t_image		*exit_open;
	void		*mlx_ptr;
	void		*win_ptr;
	int			exit_pos_x;
	int			exit_pos_y;
	t_status	status;
	enum {
		UP,
		DOWN,
		LEFT,
		RIGHT
	}			player_dir;
}				t_game;


typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_image;


typedef struct	s_sprite
{
	t_image		*image;
	int			x;
	int			y;
	int			width;
	int			height;
}				t_sprite;


typedef struct	s_map
{
	char	**full;
	int		rows;
	int		cols;
}				t_map;

typedef enum e_status
{
	EXIT_SUCCESS,
	EXIT_FAILURE,
	IN_PROGRESS,
}				t_status;



void	ft_check_arguments(int argc, char **argv, t_game *game);
void	ft_init_map(t_game *game, char *filename);
void	ft_check_line(char *line, t_game *game);
void	ft_init_vars(t_game *game);
bool	ft_check_map(t_game *game);
static void	ft_check_rows(t_game *game);
static void	ft_check_cell(t_game *game, int x, int y);
void	ft_check_columns(t_game *game);
void	ft_count_params(t_game *game);
void	ft_verify_map(t_game *game);
t_image	*ft_load_image(void *mlx_ptr, char *path);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
t_image	*ft_new_sprite(void *mlx_ptr, char *path);
void	ft_render_map(t_game *game);
t_sprite	ft_identify_sprite(char c, t_game *game);
void	ft_render_player(t_game *game);
void	ft_handle_movements(t_game *game, int key);
void	ft_check_for_collectible(t_game *game);
void	ft_check_for_exit(t_game *game);
void	ft_render_collectibles(t_game *game);
void	ft_render_image(t_game *game, t_image *img, int x, int y);
void	ft_render_exit(t_game *game);
void	ft_render_movements(t_game *game);
void	ft_render_game_over(t_game *game, t_status status);
void	ft_exit_game(t_game *game,t_status status);
void	ft_exit_error(t_game *game, char *error_msg);

#endif