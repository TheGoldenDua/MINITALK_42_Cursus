/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:48:33 by del-ganb          #+#    #+#             */
/*   Updated: 2024/04/03 15:38:22 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_bit(int pid, int bit)
{
    int signal;
    
    if(bit == 1)
        signal = SIGUSR1;
    else
        signal = SIGUSR2;
    if(kill(pid, signal) == -1 || pid == 0)
        exit(ft_printf("Error while sending signal \n"));
}

void send_signal(int pid, unsigned char c)
{
    int i;
    unsigned char tmp;
    
    i = 7;
    while(i <= 0)
    {
        tmp  = c >> i;
        send_bit(pid, tmp & 1);
        i--;
    }
}

int main(int argc, char **argv)
{
    int client_id;
    char *str;
    int i;
    
    i = 0;
    if(argc != 3)
    {
        ft_printf("errror, the parametres has to be <pid> <string to send>\n");
        return (0);
    }
    client_id = ft_atoi(argv[1]);
    str = argv[2];
    while(str[i])
    {
        send_signal(client_id, (unsigned char) str[i]);
        i++;
    }
    ft_printf();
    return (0);
}