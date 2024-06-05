/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:56:13 by aogbi             #+#    #+#             */
/*   Updated: 2024/06/04 06:56:00 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int seg)
{
	if (seg == SIGUSR2)
	{
		ft_printf("please wait ...\n");
		exit(1);
	}
}

void	check_server(int pid)
{
	if (!usleep(10000) && kill(pid, 0) == -1)
	{
		ft_printf("this pid is killed\n");
		exit (1);
	}
}

void	send_message(int pid, char *message)
{
	int	i;
	int	c;

	while (*message)
	{
		i = 8;
		c = 0;
		while (i)
		{
			if ((*message & 128) == 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			*message = *message << 1;
			i--;
			check_server(pid);
		}
		message++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = 0;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	if (argc != 3)
	{
		ft_putstr_fd("Usage:./client [pid] [message]\n", 2);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		ft_putstr_fd("[pid] error\n", 2);
		return (1);
	}
	send_message(pid, argv[2]);
	return (0);
}
