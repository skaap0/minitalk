/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:42 by tfranchi          #+#    #+#             */
/*   Updated: 2023/05/04 11:48:42 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <string.h>

void	ft_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./server\033[0m\n");
		return (0);
	}
	pid = getpid();
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause ();
	}
	return (0);
}
