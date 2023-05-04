/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:04:07 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 21:07:21 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_movements(t_game *game, int key)
{
	int		next_x;
	int		next_y;
	char	next_pos;

	next_x = game->player.x;
	next_y = game->player.y;
	if (key == KEY_UP)
		next_y--;
	else if (key == KEY_DOWN)
		next_y++;
	else if (key == KEY_LEFT)
		next_x--;
	else if (key == KEY_RIGHT)
		next_x++;
	if (next_x < 0 || next_x >= game->map_width
		|| next_y < 0 || next_y >= game->map_height)
		return ;
	next_pos = game->map[next_y][next_x];
	if (next_pos == '1')
		return ;
	if (next_pos == 'C')
	{
		game->map[next_y][next_x] = '0';
		game->collectible--;
		game->movements++;
	}
	if (next_pos == 'E' && game->collectible == 0)
	{
		game->exit_found = true;
		ft_exit_game(game, MY_EXIT_SUCCESS);
	}
	game->player.x = next_x;
	game->player.y = next_y;
	game->movements++;
}

