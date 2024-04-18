/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:48:42 by del-ganb          #+#    #+#             */
/*   Updated: 2024/04/18 06:58:36 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	static char	current_char;
	static int				i;

	current_char |= (signal == SIGUSR1);
    i++;
	if (i == 8)
	{
        if(current_char == '\0')
            ft_printf("\n");
        else
		    ft_printf("%c", current_char);
		i = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

int	main(void)
{
	ft_printf("server ID: %i\n", getpid());

    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
