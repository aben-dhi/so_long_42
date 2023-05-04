/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 06:19:20 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 17:01:49 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_rows(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (j != game->map_cols)
			ft_exit_game(game,EXIT_FAILURE);
		i++;
	}
}

static void	ft_check_cell(t_game *game, int x, int y)
{
	if (game->map[x][y] == 'P')
	{
		if (game->player.x != -1 && game->player.y != -1)
			ft_exit_game(game, EXIT_FAILURE);
		game->player.x = x;
		game->player.y = y;
	}
	else if (ft_strchr("012", game->map[x][y]) == NULL
		&& !ft_strchr(game, game->map[x][y]))
		ft_exit_game(game, EXIT_FAILURE);
}

void	ft_check_columns(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[j] && game->map[j][i])
			j++;
		if (j != game->map_rows)
			ft_exit_game(game, EXIT_FAILURE);
		i++;
	}
}

bool	ft_check_map(t_game *game)
{
	ft_check_rows(game);
	ft_check_columns(game);
	ft_verify_map(game);
	return (true);
}

