/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:56:13 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/24 19:19:53 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


int main(int argc, char *argv[]) {
	int 				i;
	int 				pid = 0;

    if (argc != 3)
    {
        ft_putstr_fd("Usage:./server [pid] [message]\n", 2);
        return (1);
    }
	i = 0;
    while (ft_isdigit(argv[1][i]) || argv[1][i] == ' ')
		i++;
	if ((int)ft_strlen(argv[1]) == i)
		pid = ft_atoi(argv[1]);
	while(*argv[2])
	{
		i = 128;
		int c = 0;
		while(i)
		{
			if (*argv[2] >= i)
			{
				*argv[2] -= i;
			    kill(pid, SIGUSR1);
				c += i;
				i /= 2;
			}
			else
			{
			    kill(pid, SIGUSR2);
				i /= 2;
			}
			usleep(100);
		}
		(argv[2])++;
	}
    return (0);
}
