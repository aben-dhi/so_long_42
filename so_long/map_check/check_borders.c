/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:44:30 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/04/17 23:28:18 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "map_to_matrix.c"
#include "check_extension.c"
#include "parse_line.c"
#include "../get_next_line/get_next_line.c"
#include "../get_next_line/get_next_line_utils.c"
#include "check_repetition.c"
#include "line_check.c"
#include "../utils_fn.c"


int check_borders(char **matrix, int row, int column) {
    int i = 0;
    while (i < row) 
    {
        if (matrix[i][0] != '1' || matrix[i][column - 1] != '1')
            return 0;
        i++;
    }
    int j = 0;
    while (j < column) 
    {
        if (matrix[0][j] != '1' || matrix[row - 1][j] != '1')
            return 0;
        j++;
    }
    return 1;
}

// #include <stdio.h>



int main() {
   
   int fd = open("../map.ber",O_RDONLY);
   if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    char *str;
    str = map_to_string(fd);
    t_lay *lay = map_to_matrix(str);
    int result = check_borders(lay->matrix , lay->row, lay->column);
    printf ("%d\n", result);
    return 0;
}
