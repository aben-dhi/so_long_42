/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:19:25 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/01/19 13:29:49 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char args);
int		ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_printf(const char *fmt, ...);
int		ft_putbase(long int arg);
int		ft_putbase_u(unsigned int arg);
int		ft_puthexa_l(unsigned int arg);
int		ft_putptr(void *arg);
int		ft_puthexa_u(unsigned int arg);

#endif
