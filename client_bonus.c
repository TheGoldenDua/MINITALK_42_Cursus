/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 07:15:36 by del-ganb          #+#    #+#             */
/*   Updated: 2024/04/18 07:23:09 by del-ganb         ###   ########.fr       */
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
		exit(printf("Error while sending signal \n"));
}

void	send_signal(int pid, char c)
{
	int		i;
	char	tmp;

	i = 7;
	while (i >= 0)
	{
		tmp = c >> i;
		send_bit(pid, tmp & 1);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int server_id;
	char *str;
	int i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("errror, the parametres: <pid> <string to send>\n");
		return (0);
	}
	if (!is_digit(argv[1]))
	{
		ft_printf("error, not a valid pid\n");
		return (0);
	}
	server_id = atoi(argv[1]);
	str = argv[2];
	while (str[i])
	{
		send_signal(server_id, str[i]);
		i++;
	}
	send_signal(server_id, '\0');
	return (0);
}