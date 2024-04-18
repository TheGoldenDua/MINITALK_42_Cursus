/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 06:33:09 by del-ganb          #+#    #+#             */
/*   Updated: 2024/04/18 07:01:13 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include "../minitalk.h"

static void	format(va_list args, const char str, int *len)
{
	if (str == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (str == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (str == 'x' || str == 'X')
		ft_puthex(va_arg(args, int), str, len);
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (str == 'p')
		ft_putvoid(va_arg(args, void *), len);
	else if (str == 'u')
		ft_putunbr(va_arg(args, unsigned int), len);
	else if (str == '%')
		ft_putchar('%', len);
	else
	{
		*len = -1;
		return ;
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			format(args, str[i], &len);
			if (len == -1)
				return (len);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
