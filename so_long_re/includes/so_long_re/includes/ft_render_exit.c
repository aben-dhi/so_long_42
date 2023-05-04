/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:35:58 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 17:36:57 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_exit(t_game *game)
{
	t_image	*exit_img;

	if (game->exit_found)
	{
		if (game->collectible == 0)
			exit_img = game->exit_open;
		else
			exit_img = game->exit_closed;
		ft_render_image(game, exit_img, game->exit_pos_x, game->exit_pos_y);
	}
}
