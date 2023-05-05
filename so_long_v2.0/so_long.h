/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:42:39 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/05 21:49:47 by aben-dhi         ###   ########.fr       */
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

# define WALL_XPM			"textures/sprites/wall.xpm"
# define FLOOR_XPM			"textures/sprites/floor.xpm"
# define COINS_XPM			"textures/sprites/coin-bag.xpm"
# define PLAYER_FRONT_XPM		"textures/player/front.xpm"
# define EXIT_XPM		"textures/sprites/exit.xpm"

typedef struct s_game
{
	bool	map_alloc;
	char	**map;
	int		rows;
	int		columns;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		collectibles;
	bool	exit_f;
	bool	player_f;
	int		moves;
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
int		c_check(t_game *game);
int		valid_frame(t_game *game);

#endif
