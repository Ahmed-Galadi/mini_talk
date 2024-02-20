/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:51:38 by agaladi           #+#    #+#             */
/*   Updated: 2024/02/20 06:17:48 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal);

int main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_putstr("MINITALK\n");
	ft_putstr("server PID:\t");
	ft_putstr(pid);

	while (1)
		sleep(1);
	return (0);
}

void	signal_handler(int signal)
{
	static char	output_char;
	static int	count;

	if (signal == SIGUSR1)
	{
		output_char = output_char << 2;
		count++;
	}
	if (signal == SIGUSR2)
	{
		output_char = output_char | 1;
		count++;
	}
	if (8 == count)
	{
		write(1, &output_char, 1);
		count -= 8;
	}
}