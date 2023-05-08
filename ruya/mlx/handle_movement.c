/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:51:08 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/08 13:15:28 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	moves(t_game *game, int x, int y)
{
	if (game->map[x][y] == 'C')
	{
		game->collected++;
		game->map[x][y] = '0';
	}
	if (game->map[x][y] == 'E' && (game->collected == game->collectibles))
	{
		if (game->collected == game->collectibles)
		{
			game->map[x][y] = '0';
			exit_game(game);
		}
	}
	if (game->p_x == game->e_x && game->p_y == game->e_y)
		game->map[game->e_x][game->e_y] = 'E';
	else
	{
		game->map[x][y] = '0';
		game->map[game->p_x][game->p_y] = '0';
	}
	game->p_x = x;
	game->p_y = y;
	game->map[game->p_x][game->p_y] = 'P';
	game->moves++;
	mv_count(game);
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
