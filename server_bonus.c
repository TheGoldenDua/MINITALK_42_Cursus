/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:30:01 by del-ganb          #+#    #+#             */
/*   Updated: 2024/04/20 23:52:09 by del-ganb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signal(int signal, siginfo_t *info, void *ptr)
{
    static char current_char;
    static int i;
    
    current_char |= (signal == SIGUSR1);
    i++;
    if(i == 8)
    {
        if(current_char == '\0')
            ft_putchar('\n');
        else
            ft_putchar(current_char);
        i = 0;
        current_char = 0;
    }
    else
        current_char <<= i;
}

int main()
{
    int pid;
    struct sigaction sa;
    
    pid = getpid();
    ft_putstr("Server pid:");
    ft_putnbr(pid);
    ft_putchar('\n');
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_signal;           
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1)
        pause();
    return (0);
}