/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:26:52 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/04/15 19:51:51 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_lay{
    int     row;
    int     column;
    char    **matrix;
}   t_lay;

//gnl /libft
char	*get_next_line(int fd);
char	*ft_read(int fd, char *left_str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *left_str);
char	*ft_new_str(char *left_str);
int     ft_strcmp(char *s1, char *s2);
//so_long
int check_repetitions(char* str);
int has_extension(char *filename,  char *extension);
char *map_to_string(int fd);
int count_lines(char *str);
int check_line(char *str);



#endif