/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_game_over.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:40:43 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 21:07:21 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_game_over(t_game *game, t_status status)
{
	char	*msg;

	if (status == MY_EXIT_FAILURE)
		msg = "You lost! Better luck next time!";
	else if (status == MY_EXIT_SUCCESS)
		msg = "Congratulations! You won the game!";
	else
		return ;
	mlx_string_put(game->mlx_ptr, game->win_ptr, game->map_width * TILE_SIZE / 2 - 100,
		game->map_height * TILE_SIZE / 2 - 10, WHITE, msg);
	mlx_string_put(game->mlx_ptr, game->win_ptr, game->map_width * TILE_SIZE / 2 - 75,
		game->map_height * TILE_SIZE / 2 + 20, WHITE, "Press ESC to exit");
}
