/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:29:58 by del-ganb          #+#    #+#             */
/*   Updated: 2024/04/22 17:33:41 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		nb_received;

void	ft_transmit(int signal)
{
	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		nb_received++;
		ft_putnbr(nb_received);
		ft_putstr(" characters successfuly transmetted.\n");
		usleep(500);
	}
}

void	send_bit(int pid, int bit)
{
	int	signal;

	if (bit == 1)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	if (kill(pid, signal) == -1 || pid <= 0)
	{
		ft_putstr("incorrect pid!\n");
		exit(1);
	}
}

void	send_signal(int pid, char c)
{
	int		i;
	char	tmp;

	i = 8;
	while (i > 0)
	{
		i--;
		tmp = c >> i;
		send_bit(pid, tmp & 1);
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	int server_id;
	char *str;
	int i;

	if (argc != 3)
	{
		ft_putstr("Error, incorrect parameters: <pid> <string to send>\n");
		return (0);
	}
	if (!is_digit(argv[1]))
	{
		ft_putstr("Error, not a valid PID\n");
		return (0);
	}
	server_id = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	signal(SIGUSR1, ft_transmit);
	signal(SIGUSR2, ft_transmit);
	while (str[i])
	{
		send_signal(server_id, str[i]);
		i++;
	}
	send_signal(server_id, '\0');
	while (1)
		pause();
	return (0);
}