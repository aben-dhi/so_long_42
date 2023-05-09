/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:07:26 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/08 20:02:01 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_frame(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
	{
		if (ft_strlen(game->map[i]) != game->columns)
			return (1);
	}
	return (0);
}

int	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->rows)
	{
		if (game->map[i][0] != '1' || game->map[i][game->columns - 1] != '1')
			return (1);
		i++;
	}
	while (j < game->columns)
	{
		if (game->map[0][j] != '1' || game->map[game->rows - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

void	player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->columns)
		{
			if (game->map[i][j] == 'P')
			{
				game->p_x = i;
				game->p_y = j;
			}
			j++;
		}
		i++;
	}
}

void	exit_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->columns)
		{
			if (game->map[i][j] == 'E')
			{
				game->e_x = i;
				game->e_y = j;
			}
			j++;
		}
		i++;
	}
}
