/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 02:35:14 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/04/27 05:39:39 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_map(t_game *game);
void check_rows(t_game *game);
void check_columns(t_game *game);
void count_map_parameters(t_game *game);
void verify_map_parameters(t_game *game);

void check_map(t_game *game)
{
    check_rows(game);
    check_columns(game);
    count_map_parameters(game);
    verify_map_parameters(game);
}

void check_rows(t_game *game)
{
    int i = 0;
    while (i < game->map.rows)
    {
        if ((int)ft_strlen(game->map.full[i]) != game->map.columns)
            ft_exit_error("Invalid Map. The Map must be rectangular!", game);
        else if (game->map.full[i][0] != WALL)
            ft_exit_error("Invalid Map. \
There's a Wall missing from the first row.\n\
The Map must be surrounded by walls!.", game);
        else if (game->map.full[i][game->map.columns - 1] != WALL)
            ft_exit_error("Invalid Map. \
There's a Wall missing from the last row.\n\
The Map must be surrounded by walls!.", game);
        i++;
    }
}

void check_columns(t_game *game)
{
    int i = 0;
    while (i < game->map.columns)
    {
        if (game->map.full[0][i] != WALL)
            ft_exit_error("Invalid Map. \
There's a Wall missing from the first column.\n\
The Map must be surrounded by walls!.", game);
        else if (game->map.full[game->map.rows - 1][i] != WALL)
            ft_exit_error("Invalid Map. \
There's a Wall missing from the last column.\n\
The Map must be surrounded by walls!.", game);
        i++;
    }
}

void count_map_parameters(t_game *game)
{
    int x, y;

    y = 0;
    while (y < game->map.rows)
    {
        x = 0;
        while (x < game->map.columns)
        {
            if (!ft_strchr("CEP01", game->map.full[y][x]))
                ft_exit_error("Invalid Map. Not expected map parameter.", game);
            else if (game->map.full[y][x] == PLAYER)
            {
                game->map.players++;
                game->map.player.x = x;
                game->map.player.y = y;
            }
            else if (game->map.full[y][x] == COINS)
                game->map.coins++;
            else if (game->map.full[y][x] == MAP_EXIT)
                game->map.exit++;
            x++;
        }
        y++;
    }
}

void verify_map_parameters(t_game *game)
{
    if (game->map.coins == 0)
        ft_exit_error("Invalid Map. There are no Coins!", game);
    else if (game->map.exit == 0)
        ft_exit_error("Invalid Map. There is no Exit.", game);
    else if (game->map.players != 1)
        ft_exit_error("Invalid Map. Invalid Player quantity. \
It's a single player game.", game);
}
