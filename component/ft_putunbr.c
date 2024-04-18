/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 06:32:36 by del-ganb          #+#    #+#             */
/*   Updated: 2024/04/18 06:32:39 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_putunbr(int nb, int *len)
{
	unsigned int	n;

	n = nb;
	if (n >= 10)
	{
		ft_putnbr(n / 10, len);
		ft_putchar((n % 10) + '0', len);
	}
	else
		ft_putchar(n + '0', len);
}
