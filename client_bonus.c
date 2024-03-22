/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:53:56 by agaladi           #+#    #+#             */
/*   Updated: 2024/03/22 02:55:22 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bits(unsigned char character, pid_t pid)
{
	unsigned char	bit_holder;
	int				i;

	bit_holder = 0;
	i = 8;
	while (i--)
	{
		bit_holder = (character >> i) & 1;
		if (!bit_holder)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putstr(SUCC_MSG);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*message;
	int		i;

	signal(SIGUSR1, signal_handler);
	if (3 != argc || !is_valid(argv[1], argv[2]))
		print_err();
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
		while (i--)
			send_bits(0, server_pid);
	}
	return (0);
}
