/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 03:44:29 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 16:59:22 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_vars(t_game *game)
{
	game->map_alloc = false;
	game->map_width = 0;
	game->map_height = 0;
	game->collectible = 0;
	game->movements = 0;
	game->exit_found = false;
	game->player_found = false;
	game->collectible = NULL;
	game->player_up = NULL;
	game->player_down = NULL;
	game->player_left = NULL;
	game->player_right = NULL;
	game->wall = NULL;
	game->floor = NULL;
	game->exit_closed = NULL;
	game->exit_open = NULL;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
}

