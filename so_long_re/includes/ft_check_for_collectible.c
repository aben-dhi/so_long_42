/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_for_collectible.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:18:37 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 17:19:01 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_for_collectible(t_game *game)
{
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->collectible--;
		game->map[game->player.y][game->player.x] = '0';
		game->movements++;
	}
	if (game->collectible == 0)
	{
		game->exit_found = true;
		ft_exit_game(game, EXIT_SUCCESS);
	}
}
