/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:17:27 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/07 16:53:22 by aben-dhi         ###   ########.fr       */
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
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
			&& game->map[i][j] != 'P' && game->map[i][j] != 'C'
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
	game->p_x = i - 1;
	game->p_y = j - 1;
	if (c != 1)
	{
		write (2, "error\n", 6);
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
		write (2, "error\n", 6);
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
		write (2, "error\n", 6);
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
	c_check2(game, c);
	return (0);
}