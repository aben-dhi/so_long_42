/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 03:41:48 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/03 18:38:38 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_line(char *line, t_game *game)
{
	int	len;

	len = ft_strlen(line);
	if (len != game->map_width)
	{
		ft_exit_game(game, "Error\nInvalid map: different line lengths.\n");
	}
	while (*line)
	{
		if (!ft_strchr("01CEP", *line))
		{
			ft_exit_game(game, "Error\nInvalid map: unknown character.\n");
		}
		line++;
	}
}
