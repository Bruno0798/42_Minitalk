/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:07:58 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/30 16:33:49 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_BONUS_H
# define FT_MINITALK_BONUS_H

#include "../libft/includes/libft.h"
# include <signal.h>

void ft_send_bits(int pid, char i);
/**
 * Sends each bit of a character to a process identified by its PID.
 * 
 * @param pid The process ID of the receiver process.
 * @param i The character to be sent.
 */

void ft_handler(int signal);
/**
 * @brief Signal handler function that processes incoming signals.
 * 
 * This function is responsible for handling the SIGUSR1 and SIGUSR2 signals.
 * It converts the received signals into a character and prints it to the console.
 * 
 * @param signal The signal received by the handler.
 */

static void	ft_confirm(int signal);
/**
 * @brief Signal handler function that processes incoming signals.
 * 
 * This function is responsible for handling the SIGUSR1 and SIGUSR2 signals.
 * It prints a confirmation message to the console.
 * 
 * @param signal The signal received by the handler.
 */


#endif