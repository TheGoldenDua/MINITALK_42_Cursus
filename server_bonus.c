/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:30:01 by del-ganb          #+#    #+#             */
/*   Updated: 2024/04/26 02:00:51 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *ptr)
{
	static char	current_char;
	static int	i;

	(void)ptr;
	current_char |= (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (current_char == '\0')
			ft_putchar('\n');
		else
			ft_putchar(current_char);
		i = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
	kill(info->si_pid, signal);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	pid = getpid();
	write(1, "Server pid:", 11);
	ft_putnbr(pid);
	ft_putchar('\n');
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
