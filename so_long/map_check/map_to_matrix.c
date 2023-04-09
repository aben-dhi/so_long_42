/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:58:09 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/04/09 00:58:51 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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