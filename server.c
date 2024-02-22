/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:51:38 by agaladi           #+#    #+#             */
/*   Updated: 2024/02/22 03:32:49 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	signal_handler(int signal)
{
	static unsigned char	output_char;
	static int				count;

	if (signal == SIGUSR1)
	{
		output_char = output_char << 1;
		count++;
	}
	if (signal == SIGUSR2)
	{
		output_char = output_char << 1;
		output_char = output_char | 1;
		count++;
	}
	if (8 == count)
	{
		write(1, &output_char, 1);
		count = 0;
	}
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	print_message(pid);
	while (1)
		sleep(1);
	return (0);
}
