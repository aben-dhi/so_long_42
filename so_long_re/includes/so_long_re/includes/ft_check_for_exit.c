/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_for_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:20:57 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 17:24:41 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_for_exit(t_game *game)
{
	if (game->exit_found && game->player_found 
    && game->player.x == game->exit_pos_x && game->player.y == game->exit_pos_y)
	{
		ft_putendl_fd("Congratulations, you have completed the game!", 1);
		ft_exit_game(game, EXIT_SUCCESS);
	}
}
