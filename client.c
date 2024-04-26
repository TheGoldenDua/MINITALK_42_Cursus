/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:48:33 by del-ganb          #+#    #+#             */
/*   Updated: 2024/04/26 03:30:06 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(400);
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
	{
		write(1, "Error, not a valid PID\n", 23);
		return (1);
	}
	server_id = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i])
	{
		send_signal(server_id, (unsigned char)str[i]);
		i++;
	}
	send_signal(server_id, '\0');
	return (0);
}
