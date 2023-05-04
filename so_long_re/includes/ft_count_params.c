/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 06:38:45 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/03 19:22:02 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_params(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map_height)
	{
		col = 0;
		while (col < game->map_width)
		{
			if (game->map[row][col] == 'P')
			{
				game->player.x = col;
				game->player.y = row;
			}
			else if (game->map[row][col] == 'C')
				game->collectible++;
			else if (game->map[row][col] == 'E')
				game->exit_found++;
			col++;
		}
		row++;
	}
	if (game->player.x == -1 || game->collectible == 0 || game->exit_found == 0)
		ft_exit_game(game, EXIT_FAILURE);
}
