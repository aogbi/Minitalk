# Minitalk
Minitalk is a client-server program that exchanges data using Unix signals. The server prints its PID. The client takes the server's PID and a string, encodes the string into bits using SIGUSR1/SIGUSR2 signals, and transmits it to the server. The server decodes the signals and displays the original string.
