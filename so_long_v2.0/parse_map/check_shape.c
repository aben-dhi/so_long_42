/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:07:26 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/05 21:52:08 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_frame(t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	game->columns = ft_strlen(game->map[i]);
	while (game->map[++i])
	{
		if (ft_strlen(game->map[i]) != game->columns)
			return (1);
	}
	return (0);
}

int	check_walls(t_game *game)
{
	int	j;

	j = -1;
	while (++j < game->rows)
	{
		if (game->map[0][j] != 1 || game->map[game->rows - 1][j] != 1)
			return (1);
	}
	j = -1;
	while (++j < game->columns)
	{
		if (game->map[j][0] != 1 || game->map[j][game->columns - 1] != 1)
			return (1);
	}
	return (0);
}

int	valid_frame(t_game *game)
{
	if (check_walls(game) == 0 && check_frame(game) == 0)
		return (0);
	return (1);
}
