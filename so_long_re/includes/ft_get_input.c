/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:50:24 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 17:51:08 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_input(t_game *game)
{
	int	key;

	key = 0;
	if (game->status == IN_PROGRESS)
	{
		key = ft_get_key();
		if (key == KEY_ESC)
			ft_exit_game(game, EXIT_SUCCESS);
		ft_handle_movements(game, key);
		ft_check_for_collectible(game);
		ft_check_for_exit(game);
		if (game->status != IN_PROGRESS)
			ft_render_game_over(game, game->status);
	}
	return (key);
}
