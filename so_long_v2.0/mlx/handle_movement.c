/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:51:08 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/07 22:45:02 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	moves(t_game *game, int x, int y)
{
	if (game->map[x][y] == 'C')
	{
		game->collected++;
		game->map[x][y] = '0';
	}
	if (game->map[x][y] == 'E')
	{
		if (game->collected == game->collectibles)
		{
			exit_game(game);
			game->map[x][y] = '0';
		}
		else 
			game->map[x][y] = 'E';
	}
	else
		game->map[x][y] = '0';
	game->map[game->p_x][game->p_y] = '0';
	game->p_x = x;
	game->p_y = y;
	game->map[game->p_x][game->p_y] = 'P';
}

void	move_up(t_game *game)
{
	int	next_x;
	int	next_y;

	if (game->p_x - 1 <= 0 || game->map[game->p_x - 1][game->p_y] == '1')
		return ;
	next_x = game->p_x - 1;
	next_y = game->p_y;
	moves(game, next_x, next_y);
	put_img(game);
}


void	move_down(t_game *game)
{
	int	next_x;
	int	next_y;

	if (game->p_x + 1 <= 0 || game->map[game->p_x + 1][game->p_y] == '1')
		return ;
	next_x = game->p_x + 1;
	next_y = game->p_y;
	moves(game, next_x, next_y);
	put_img(game);
}

void	move_left(t_game *game)
{
	int	next_x;
	int	next_y;

	if (game->p_y - 1 <= 0 || game->map[game->p_x][game->p_y - 1] == '1')
		return ;

	next_x = game->p_x;
	next_y = game->p_y - 1;
	moves(game, next_x, next_y);
	put_img(game);
}

void	move_right(t_game *game)
{
	int	next_x;
	int	next_y;

	if (game->p_y + 1 <= 0 || game->map[game->p_x][game->p_y + 1] == '1')
		return ;
	next_x = game->p_x;
	next_y = game->p_y + 1;
	moves(game, next_x, next_y);
	put_img(game);
}


// x = 1;
// y = 1;
// player_pos[x][y] = '0';
// player_pos[x]++;
// player_pos[x][y] = 'P';
// mlx_image

// if the position of kirby hits the position of the exit: EXIT THE MF
// means, if kirby's coords == the bed's coords: EXIT THE MF!!

// if (game->p_x == game->e_x && game->p_y == game-e_y && collects == colletbs)
// 	EXIT THE MF;
