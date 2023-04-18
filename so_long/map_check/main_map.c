/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:49:43 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/04/18 01:25:21 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int map(int fd)
{
    int fd;
    char *str; 
    
    if (has_extension(fd, ".ber"));
    fd = open(fd, O_RDONLY);
    str = map_to_string(fd);
    if (check_line(str) == 1)
        ft_printf("error reading map, re-check characters");
    else
    if 
    // printf("%s\n", str);
    // printf("%d\n", check_line(str));
    // close(fd);
    // printf("%zu\n", ft_strlen(str));
    // printf("%d\n", check_repetitions(str));
    // printf("%d\n", count_lines(str));
    free(str);
}