/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 03:01:04 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 20:13:28 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include "../libftproject/libft.h"
# include "../get_next_line/get_next_line.h"

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
	enum {
		UP,
		DOWN,
		LEFT,
		RIGHT
	}			player_dir;
	t_status	status;
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
int	    ft_get_key(int key, t_game *game);
int		ft_get_input(t_game *game);

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
int		ft_atoi(const char *str);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *left_str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *left_str);
char	*ft_new_str(char *left_str);

#endif