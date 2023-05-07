/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:47:35 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/07 22:04:22 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_S)
		move_down(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_ESC)
		exit_game(game);
	// if (game->collected == game->collectibles && 
	// 		game->map[game->p_x - 1][game->p_y] == 'E')
	// 	exit_game(game);
	return (0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->image.mlx, game->image.mlx_win);
	free_tmp(game->tmp);
	free_tmp(game->map);
	if (game->collectibles == game->collected)
	{
		write (1, "Congratulations!\n", 17);
		exit(0);
	}
	exit(0);
	return (0);
}

// void exit_game(t_game *game)
// {
// 	t_image	*img;

// 	img = &game->image;
// 	mlx_destroy_image(img->mlx, img->mlx_img);
// 	mlx_destroy_window(img->mlx, img->mlx_win);
// 	// free(game->map);
// 	// free(game->tmp);
// 	exit(0);
// }
