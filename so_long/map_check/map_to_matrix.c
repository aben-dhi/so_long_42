/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:58:09 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/04/17 23:10:52 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
// #include "line_check.c"
// #include "../get_next_line/get_next_line_utils.c"


t_lay *create_lay(int rows, int cols) {
    t_lay *lay = malloc(sizeof(t_lay));
    if (!lay) {
        return NULL;
    }
    lay->row = rows;
    lay->column = cols;
    lay->matrix = malloc(sizeof(char *) * rows);
    if (!lay->matrix) {
        free(lay);
        return NULL;
    }
    return lay;
}

void fill_lay(t_lay *lay, char *map_str) {
    char *temp = map_str;
    int i = 0;
    while (*temp)
    {
        char *line = malloc(sizeof(char) * (lay->column + 1));
        if (!line) {
            int j = 0;
            while (j < i) {
                free(lay->matrix[j]);
                j++;
            }
            free(lay->matrix);
            free(lay);
            return;
        }
        int j = 0;
        while (*temp != '\n')
        {
            line[j] = *temp;
            j++;
            temp++;
        }
        line[j] = '\0';
        lay->matrix[i] = line;
        i++;
        temp++;
    }
}

t_lay *map_to_matrix(char *map_str)
{
    int rows = count_lines(map_str);
    int cols = ft_strlen(map_str) / rows;

    t_lay *lay = create_lay(rows, cols);
    if (!lay) 
    {
        return NULL;
    }

    fill_lay(lay, map_str);

    return lay;
}

void free_matrix(t_lay *lay) 
{
    int i = 0;
    // void    *l_m;
    
    while (i < lay->row) 
    {
        int j = 0;
        while (j < lay->column)
        {
            
            free(&lay->matrix[i][j]);
            j++;
        }
        free(lay->matrix[i]);
        i++;
    }
    free(lay->matrix);
    free(lay);
}


// #include <stdio.h>

// int main()
// {
//     char *map_str = "11111\n10001\n10101\n10001\n11111\n";
//     t_lay *lay = map_to_matrix(map_str);

//     // Print the matrix
//     for (int i = 0; i < lay->row; i++) {
//         for (int j = 0; j < lay->column; j++) {
//             printf("%c ", lay->matrix[i][j]);
//         }
//         printf("\n");
//     }
//     printf("%c", lay->matrix[1][1]);
//         // Free the memory allocated for the matrix and the struct
//    free_matrix(lay);

//     return 0;
// }
