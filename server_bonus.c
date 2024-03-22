/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:51:38 by agaladi           #+#    #+#             */
/*   Updated: 2024/03/21 21:51:49 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	print_message(char *pid)
{
	ft_putstr(TITLE_MSG);
	ft_putstr("\n\n");
	ft_putstr("\t\e[1;97m\e[4;32mserver PID :");
	ft_putstr(H_DEVIDER);
	ft_putstr("\e[1;37m\e[42m");
	ft_putstr(pid);
	ft_putstr("\n");
	ft_putstr(V_DEVIDER);
	ft_putstr("\e[1;32m֎ \e[1;37mmessage\e[0;33m ⤳  \033[1;0m");
}

void	set_bit(int bit, unsigned char *output_char, int *count, void *context)
{
	context = NULL;
	if (bit == 0)
	{
		*output_char = *output_char << 1;
		*count += 1;
	}
	if (bit == 1)
	{
		*output_char = *output_char << 1;
		*output_char = *output_char | 1;
		*count += 1;
	}
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	output_char;
	static int				count;
	static int				client_pid;

	if (client_pid != 0)
	{
		if (client_pid != info->si_pid)
		{
			output_char = 0;
			count = 0;
		}
	}
	client_pid = info->si_pid;
	if (signal == SIGUSR1)
		set_bit(0, &output_char, &count, context);
	if (signal == SIGUSR2)
		set_bit(1, &output_char, &count, context);
	if (8 == count)
	{
		count = 0;
		if (output_char == 0)
			kill(client_pid, SIGUSR1);
		else
			write(1, &output_char, 1);
	}
}

int	main(void)
{
	char				*pid;
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = ft_itoa(getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	print_message(pid);
	free(pid);
	while (1)
		sleep(1);
	return (0);
}
