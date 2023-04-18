/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:04:43 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/01/19 12:25:16 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_alpha(int nb)
{
	if (nb == 10)
		ft_putchar('a');
	if (nb == 11)
		ft_putchar('b');
	if (nb == 12)
		ft_putchar('c');
	if (nb == 13)
		ft_putchar('d');
	if (nb == 14)
		ft_putchar('e');
	if (nb == 15)
		ft_putchar('f');
	return (1);
}

int	ft_puthexa_l(unsigned int val)
{
	int	count;

	count = 0;
	if (val >= 16)
	{
		count += ft_puthexa_l(val / 16);
		count += ft_puthexa_l(val % 16);
	}
	if (val >= 0 && val <= 9)
		count += ft_putbase_u(val);
	if (val >= 10 && val <= 15)
		count += ft_alpha(val);
	return (count);
}
