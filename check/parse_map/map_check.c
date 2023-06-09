/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:17:27 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/09 13:53:46 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	comp_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != 'P'
				&& game->map[i][j] != '0' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	p_check(t_game *game)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	c = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
				c++;
		}
	}
	if (c != 1)
	{
		write (2, "Error\nPlayer error\n", 20);
		free_tmp(game->map);
		free_tmp(game->tmp);
		exit (1);
	}
	return (0);
}

int	e_check(t_game *game)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	c = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'E')
				c++;
		}
	}
	if (c != 1)
	{
		write (2, "Error\nExit error\n", 18);
		free_tmp(game->map);
		free_tmp(game->tmp);
		exit (1);
	}
	return (0);
}

void	c_check2(t_game *game, int c)
{
	if (c < 1)
	{
		write (2, "Error\nNo collectibles in map\n", 30);
		free_tmp(game->map);
		free_tmp(game->tmp);
		exit (1);
	}
}

int	c_check1(t_game *game)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	game->rows = 0;
	while (game->map[i])
	{
		game->rows++;
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	game->collectibles = c;
	game->collected = 0;
	c_check2(game, c);
	return (0);
}
