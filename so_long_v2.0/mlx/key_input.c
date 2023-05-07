/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:47:35 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/07 17:51:30 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_up(game);
	// else if (keycode == KEY_S)
	// 	move_down(game);
	// else if (keycode == KEY_A)
	// 	move_left(game);
	// else if (keycode == KEY_D)
	// 	move_right(game);
	else if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->image.mlx, game->image.mlx_win);
	free_tmp(game->map);
	if (game->collectibles == 0)
	{
		write (1, "Congratulations!\n", 17);
		exit(0);
	}
	exit(1);
	return (0);
}