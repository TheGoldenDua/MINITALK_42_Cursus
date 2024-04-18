/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 06:32:22 by del-ganb          #+#    #+#             */
/*   Updated: 2024/04/18 06:32:23 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_putnbr(int nb, int *len)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar(('-'), len);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr((n / 10), len);
		ft_putchar((n % 10) + '0', len);
	}
	else
		ft_putchar(n + '0', len);
}
