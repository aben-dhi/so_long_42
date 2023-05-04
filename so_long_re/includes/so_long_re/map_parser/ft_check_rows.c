/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 06:21:38 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/04/27 05:23:05 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->map_width)
			ft_exit_error(game, "Invalid map file: inconsistent row length");
		i++;
	}
}
