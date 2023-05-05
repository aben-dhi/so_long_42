/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:17:27 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/05 21:42:25 by aben-dhi         ###   ########.fr       */
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

	i = 0;
	c = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				c++;
			j++;
		}
		i++;
	}
	if (c != 1)
		return (1);
	return (0);
}

int	e_check(t_game *game)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				c++;
			j++;
		}
		i++;
	}
	if (c != 1)
		return (1);
	return (0);
}

int	c_check(t_game *game)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
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
	if (c < 1)
		return (1);
	return (0);
}
