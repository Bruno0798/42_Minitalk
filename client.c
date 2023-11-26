/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:29:14 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/26 22:53:54 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <signal.h>

void signal_handler(int signum, char c)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 1)
			kill(signum, SIGUSR1);
		else
			kill(signum, SIGUSR2);
		c = c >> 1;
		usleep(100);
		bit++;
	}
	
}

int main(int argc, char **argv)
{
	int i;

	i = 0;
	
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments.\n");
		ft_printf("Usage: ./client [server_ip] [server_port]\n");
		return 0;
	}else
	{
		while (argv[2][i] != '\0')
		{
			signal_handler(ft_atoi(argv[1]), argv[2][i]);
			i++;
		}
		signal_handler(ft_atoi(argv[1]), '\n');
		
	}
	return 0;
}