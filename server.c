/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:54:17 by aogbi             #+#    #+#             */
/*   Updated: 2024/06/04 06:56:00 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_minitalk = 0;

void	write_minitalk(int *bitn, int *character)
{
	*bitn /= 2;
	if (*bitn <= 0)
	{
		ft_printf("%c", *character);
		*bitn = 128;
		*character = 0;
	}
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	character = 0;
	static int	bitn = 128;

	context = NULL;
	if (g_minitalk == 0)
		g_minitalk = info->si_pid;
	if (g_minitalk != info->si_pid)
	{
		usleep(1000);
		if (kill(g_minitalk, 0) == 0)
		{
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		g_minitalk = info->si_pid;
		bitn = 128;
		character = 0;
	}
	if (signal == SIGUSR1)
		character += bitn;
	write_minitalk(&bitn, &character);
	kill(info->si_pid, SIGUSR1);
}

void	makefile_str(void)
{
	ft_printf("\n\033[1;32m  ███╗   ███╗██╗███╗   ");
	ft_printf("██╗██╗████████╗ █████╗ ██╗     ██╗ ██╗\n");
	ft_printf("  ████╗ ████║██║████╗  ██║██║╚══");
	ft_printf("██╔══╝██╔══██╗██║     ██║██╔╝\n");
	ft_printf("  ██╔████╔██║██║██╔██╗ ██║██║   ██║  ");
	ft_printf(" ███████║██║     ███╔╝ \n");
	ft_printf("  ██║╚██╔╝██║██║██║╚██╗██║██║   ");
	ft_printf("██║   ██╔══██║██║     ██║██╗ \n");
	ft_printf("  ██║ ╚═╝ ██║██║██║ ╚████║██║   ██");
	ft_printf("║   ██║  ██║███████╗██╔═██╗\n");
	ft_printf("  ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ");
	ft_printf("╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝ ╚═╝\n");
	ft_printf("       ═════════════════ \033[1;35mpid = %d", getpid());
	ft_printf(" \033[1;32m═════════════════\033[0m\n");
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	makefile_str();
	while (1)
		pause();
	return (0);
}
