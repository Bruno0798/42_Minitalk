/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:35:01 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/26 22:45:43 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <signal.h>

void signal_handler(int signum)
{
	static int bit = 0;
	static char c = 0;
	
	if (signum == SIGUSR1)
		c = c | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int main(int argc, char **argv)
{
	(void)argv;
	
	if (argc != 1)
	{
		ft_printf("Invalid number of arguments.\n");
		ft_printf("Usage: ./server\n");
		return 0;
	}
	ft_printf("Server started.\n");
	ft_printf("PID: %d\n", getpid());
	ft_printf("Waiting for signals...\n");
	while (1)
		{
			signal(SIGUSR1, signal_handler);
			signal(SIGUSR2, signal_handler);
		}
	
	return 0;
}