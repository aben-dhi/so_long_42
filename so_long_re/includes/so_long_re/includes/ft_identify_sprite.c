/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identify_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:55:43 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 17:07:23 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_identify_sprite(char c, t_game *game)
{
	if (c == 'P')
	{
		game->player_found = true;
		return (PLAYER_FRONT_XPM);
	}
	else if (c == 'C')
	{
		game->collectible++;
		return (COINS_XPM);
	}
	else if (c == 'E')
	{
		game->exit_found = true;
		return (EXIT_XPM);
	}
	else if (c == '1')
		return (WALL_XPM);
	else if (c == '0')
		return (FLOOR_XPM);
	return (-1);
}

