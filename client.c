/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:53:56 by agaladi           #+#    #+#             */
/*   Updated: 2024/02/21 03:20:38 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(unsigned char character, pid_t pid)
{
	unsigned char bit_holder;
	int		i;

	i = 8;
	while (i)
	{
		bit_holder = 0;
		bit_holder = (character >> i) & 1;
		if (bit_holder == 1)
		{
			kill(pid, SIGUSR2);
			write(1, "0", 1);
		}
		else
		{
			kill(pid, SIGUSR1);
			write(1, "1", 1);
		}
		usleep(10000);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
    char	*message;
    int		i;

	if (3 != argc)
		ft_putstr("Usage: ./client <server_pid> <message>\n");
	else
	{
		server_pid = (pid_t)ft_atoi(argv[1]);
		message = argv[2];
		i = 0;
		while (message[i])
		{
			send_bits(message[i], server_pid);
			i++;
		}
	}
	return (0);
}