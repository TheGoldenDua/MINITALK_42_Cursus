/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 06:31:55 by del-ganb          #+#    #+#             */
/*   Updated: 2024/04/18 06:56:06 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minitalk.h"

static int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
