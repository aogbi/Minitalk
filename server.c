/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:54:17 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/24 19:19:02 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int signal)
{
	static int character = 0;
	static int bitn = 128;

	if (signal == SIGUSR1)
	    character += bitn;
	bitn /= 2;
	if (bitn <= 0)
	{
		ft_printf("%c", character);
		bitn = 128;
        character = 0;
	}
}

int main() {
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_printf("\n\033[1;32m  ███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗ ██╗\n");
  	ft_printf("  ████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║██╔╝\n");
	ft_printf("  ██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     ███╔╝ \n");
	ft_printf("  ██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██║██╗ \n");
	ft_printf("  ██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██╔═██╗\n");
	ft_printf("  ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝ ╚═╝\n");
	ft_printf("       ═════════════════ \033[1;35mpid = %d \033[1;32m═════════════════\033[0m\n", getpid());
	while (1){}
    return 0;
}
