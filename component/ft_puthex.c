/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 06:32:15 by del-ganb          #+#    #+#             */
/*   Updated: 2024/04/18 06:32:16 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_puthex(int nb, char type, int *len)
{
	char			*base;
	unsigned int	n;

	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	n = nb;
	if (n >= 16)
	{
		ft_puthex(n / 16, type, len);
		ft_putchar(base[n % 16], len);
	}
	else
		ft_putchar(base[n % 16], len);
}
