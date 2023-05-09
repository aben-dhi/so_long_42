/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:58:41 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/09 13:51:26 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkinside(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->tmp[i])
	{
		j = 0;
		while (game->tmp[i][j])
		{
			if (game->tmp[i][j] != 'E' && game->tmp[i][j] != 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	find_path(t_game *game, int i, int j)
{
	if (i < 0 || j < 0 || i >= game->rows || j >= game->columns)
		return ;
	if (game->tmp[i][j] == '1')
		return ;
	if (game->tmp[i][j] != 'V')
	{
		game->tmp[i][j] = 'V';
		find_path(game, i, j + 1);
		find_path(game, i - 1, j);
		find_path(game, i, j - 1);
		find_path(game, i + 1, j);
		if (checkinside(game) == 1)
			return ;
	}
}

int	path_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->tmp[i])
	{
		j = 0;
		while (game->tmp[i][j])
		{
			if (game->tmp[i][j] != '1' && game->tmp[i][j] != 'V'
				&& game->tmp[i][j] != '0')
			{
				write (2, "Error\nPath not found\n", 22);
				free_tmp(game->tmp);
				free_tmp(game->map);
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	free_tmp(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}
