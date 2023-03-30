/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:48:28 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/03/23 17:04:11 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//counting how many lines are in the file
int count_lines(int fd)
{
   int num_lines = 0;
   char c;
   
   while(read(fd, &c, 1) == 1) 
   {
       if(c == '\n') 
       {
           num_lines++;
       }
   }
   return (num_lines);
}

int no_repetition(char *line, char c)
{
    int i;
    int count;
    
    i = 1;
    count = 0;
    while(line[i] == c && i < ft_strlen(line))
    {
        count++;
        i++;
    }
    if (count >= 1)
        return(0);
    else
        return(1);
}

int check_first(char *line)
{
    int count;
    int i;
    
    count = 0;
    i = 0;
    while (*line && *line != '\n')
    {
        while (count == 0)
        {
            if (line[i] == 1)
            {
                i++;
                return(i);
            }
            else
                return (0);
            count++;
        }
    }
}

int check_last(char *line, int fd)
{
    int count;
    int i;

    count = count_lines(fd);
    i = 0;
    while (*line)
    {
        while (count == count_lines(fd))
        {
            if (line[i] == 1)
            {
                i++;
                return(i);
            }
            else
                return (0);
        }
    }
}


int check_map(int fd)
{
    int count;
    int i;
    char *line;

    i = 0;
    count = 0;
    //getting the first line
    line = get_next_line(fd);
    //checking if the first line is valid and then going to the next one
    if (check_first(line))
        line = get_next_line(fd);
    else
        return(0);
    count++;
    i = 1;
    while (count && (i < ft_strlen(line)))
    {
        while (line[0] == 1 && line[ft_strlen(line)] == 1)
        {
            while (line[i] == 1 || line[i] == 0 || line[i] == 'P' 
            || line[i] == 'C' || line[i] == 'E')
            {
                if (!(no_repetition(line, 'P') && (no_repetition(line, 'E'))))
                    return(0);
            }        
        }
        count--;
    }
}
// int check_walls(int fd)
// {
//     int num_lines = 0;
//     char c;
   
//    while(read(fd, &c, 1) == 1) {
//        if(c == 1) {
//            num_lines++;
//        }
//    }
//    return (num_lines);      
// }
 
//  int main() {
//     int fd = open("map.ber", O_RDONLY);
//     if(fd == -1) {
//         perror("open");
//         return 1;
//     }
//     int num_lines = count_lines(fd);
//     printf("Number of lines: %d\n", num_lines + 1);
//     close(fd);
//     return 0;
// }