/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:33:51 by aben-dhi          #+#    #+#             */
/*   Updated: 2023/01/19 12:25:25 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_alpha(unsigned int nb)
{
	if (nb == 10)
		ft_putchar('A');
	if (nb == 11)
		ft_putchar('B');
	if (nb == 12)
		ft_putchar('C');
	if (nb == 13)
		ft_putchar('D');
	if (nb == 14)
		ft_putchar('E');
	if (nb == 15)
		ft_putchar('F');
	return (1);
}

int	ft_puthexa_u(unsigned int val)
{
	int	count;

	count = 0;
	if (val >= 16)
	{
		count += ft_puthexa_u(val / 16);
		count += ft_puthexa_u(val % 16);
	}
	if (val >= 0 && val <= 9)
		count += ft_putbase_u(val);
	if (val >= 10 && val <= 15)
		count += ft_alpha(val);
	return (count);
}
