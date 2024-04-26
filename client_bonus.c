/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:29:58 by del-ganb          #+#    #+#             */
/*   Updated: 2024/04/26 03:29:58 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_received;

void	ft_transmit(int signal)
{
	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		g_received++;
		usleep(400);
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
		write(1, "Incorrect PID!\n", 16);
		exit(1);
	}
}

void	send_signal(int pid, unsigned char c)
{
	int		i;
	char	tmp;

	i = 8;
	while (i > 0)
	{
		i--;
		tmp = c >> i;
		send_bit(pid, tmp & 1);
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int		server_id;
	char	*str;
	int		i;

	if (argc != 3)
	{
		write(1, "Error, incorrect parameters: <pid> <string to send>\n", 52);
		return (0);
	}
	if (!is_digit(argv[1]))
		return (write(1, "Error, not a valid PID\n", 23), 0);
	server_id = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	signal(SIGUSR1, ft_transmit);
	signal(SIGUSR2, ft_transmit);
	while (str[i])
		send_signal(server_id, (unsigned char)str[i++]);
	send_signal(server_id, '\0');
	ft_putnbr(g_received);
	write(1, " bits successfuly transmetted.\n", 31);
	return (0);
}
