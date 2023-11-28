/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:35:01 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/28 12:05:13 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minitalk.h"

#include <stdio.h>
#include <signal.h>

void ft_handler(int signal)
{
    static int bit = 0;
    static int i = 0;

    if (signal == SIGUSR1)
    {
        i |= (0x01 << bit);
    }
    bit++;

    if (bit == 8)
    {
        printf("%c", i);
        bit = 0;
        i = 0;
    }
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./server\033[0m\n");
		return (0);
	}
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", getpid());
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}
