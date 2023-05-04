/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 03:37:22 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/05/04 21:06:54 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_check_arguments(int argc, char **argv, t_game *game)
 {
    if (argc != 2) {
        perror("Error: Invalid number of arguments.\n");
        exit(MY_EXIT_FAILURE);
    }

    char *filename = argv[1];
    int len = ft_strlen(filename);
    if (len < 4 || ft_strcmp(filename + len - 4, ".ber") != 0) {
        perror("Error: Invalid file extension. The file should have a .ber extension.\n");
        exit(MY_EXIT_FAILURE);
    }

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error: Unable to open file.\n");
        exit(MY_EXIT_FAILURE);
    }

    close(fd);
    ft_init_map(game, filename);
}
