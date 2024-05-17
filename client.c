/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aogbi <aogbi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:56:13 by aogbi             #+#    #+#             */
/*   Updated: 2024/05/17 22:45:20 by aogbi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void send_message(pid_t server_pid, const char *message) {
    while (*message) {
        if (*message == '1') {
            kill(server_pid, SIGUSR1);
        } else if (*message == '0') {
            kill(server_pid, SIGUSR2);
        }
        usleep(100);  // Small delay to ensure the signal is sent
        message++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_pid> <message>\n", argv[0]);
        return 1;
    }

    pid_t server_pid = atoi(argv[1]);
    const char *message = argv[2];

    send_message(server_pid, message);

    return 0;
}
