/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 06:32:43 by del-ganb          #+#    #+#             */
/*   Updated: 2024/04/18 06:32:46 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static void	ft_puthex_2(unsigned long nb, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_puthex_2(nb / 16, len);
		ft_putchar(base[nb % 16], len);
	}
	else
		ft_putchar(base[nb % 16], len);
}

void	ft_putvoid(void *str, int *len)
{
	unsigned long	n;

	n = (unsigned long)str;
	if (n == 0)
		ft_putstr("(nil)", len);
	else
	{
		ft_putstr("0x", len);
		ft_puthex_2(n, len);
	}
}
