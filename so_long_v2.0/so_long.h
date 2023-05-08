/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:42:39 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/08 13:20:51 by aben-dhi         ###   ########.fr       */
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
// # include <string.h>
# include <stdio.h>

# define BUFFER_SIZE 100

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_ESC  			53

# define WALL			"textures/sprites/wall.xpm"
# define FLOOR			"textures/sprites/floor.xpm"
# define COINS			"textures/sprites/coin-bag.xpm"
# define PLAYER		"textures/player/front.xpm"
# define EXIT		"textures/sprites/exit.xpm"

typedef struct s_image
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		len;
	int		wid;
}		t_image;

typedef struct s_game
{
	bool	map_alloc;
	char	**map;
	char	**tmp;
	int		rows;
	int		columns;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		collectibles;
	int		collected;
	bool	exit_f;
	bool	player_f;
	int		moves;
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	image;
}		t_game;

char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_get_line(char *left_str);
char	*ft_new_str(char *left_str);
char	**ft_split(char *s, char c);
int		comp_check(t_game *game);
int		p_check(t_game *game);
int		e_check(t_game *game);
int		c_check1(t_game *game);
void	c_check2(t_game *game, int c);
int		valid_frame(t_game *game);
int		ft_strcmp(char *s1, char *s2);
int		has_extension(char *filename, char *extension);
void	find_path(t_game *game, int i, int j);
int		path_check(t_game *game);
void	free_tmp(char **str);
void	init_game(t_game *game);
int		put_img(t_game *game);
void	floor_img(t_game *game, int i, int j);
void	wall_img(t_game *game, int i, int j);
void	collectible_img(t_game *game, int i, int j);
void	player_img(t_game *game, int i, int j);
void	exit_img(t_game *game, int i, int j);
void	mv_count(t_game *game);
int		handle_key_press(int keycode, t_game *game);
char	*ft_itoa(int n);
int		exit_game(t_game *game);
void	move_up(t_game *game);
void	full_check(t_game *game, char *filename, int fd);
void	get_matrix(int fd, t_game *game);
void	player_pos(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	exit_pos(t_game *game);

#endif
