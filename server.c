/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:51:38 by agaladi           #+#    #+#             */
/*   Updated: 2024/02/21 22:25:21 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_putstr(TITLE_MSG);
	ft_putstr("server PID: ");
	ft_putstr(DEVIDER);
	ft_putstr(pid);
	ft_putstr("\n");

	while (1)
		sleep(1);
	return (0);
}
