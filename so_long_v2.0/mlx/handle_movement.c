/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:51:08 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/07 16:53:42 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *game)
{
	int	next_x;
	int	next_y;

	if (game->p_x - 1 < 0 || game->map[game->p_x - 1][game->p_y] == '1')
		return ;
	next_x = game->p_x - 1;
	next_y = game->p_y;
	if (game->map[next_x][next_y] == 'E'
		&& game->collected != game->collectibles)
		return ;
	if (game->map[next_x][next_y] == 'C')
	{
		game->collected++;
		if (game->collected == game->collectibles)
			game->map[next_x][next_y] = 'E';
		else
			game->map[next_x][next_y] = '0';
	}
	else
		game->map[next_x][next_y] = '0';
	game->map[game->p_x][game->p_y] = '0';
	game->p_x = next_x;
	game->p_y = next_y;
	game->map[game->p_x][game->p_y] = 'P';
	put_img(game);
}


// int	move_down(t_game *game)
// {
// 	// Update the game state to move the player down
// }

// int	move_left(t_game *game)
// {
// 	// Update the game state to move the player left
// }

// int	move_right(t_game *game)
// {
// 	// Update the game state to move the player right
// }

// x = 1;
// y = 1;
// player_pos[x][y] = '0';
// player_pos[x]++;
// player_pos[x][y] = 'P';
// mlx_image