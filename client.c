/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:48:45 by tfranchi          #+#    #+#             */
/*   Updated: 2023/05/04 11:48:45 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_number(const char *s)
{
	int	i;

	i = 0;
	while ((size_t)i < ft_strlen(s))
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(WAIT_TIME);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		if (!check_number(argv[1]))
			ft_printf("\033[91mError: wrong PID format.\033[0m\n");
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_bits(pid, argv[2][i]);
			i++;
		}
		ft_send_bits(pid, '\n');
	}
	else
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
	return (0);
}
