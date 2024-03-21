/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:29:39 by agaladi           #+#    #+#             */
/*   Updated: 2024/03/21 20:34:00 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isdigit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static size_t	ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	is_valid(char *pid, char *message)
{
	if (!pid || !message)
		return (0);
	if (!ft_isdigit(pid) || !ft_strlen(message))
		return (0);
	return (1);
}

void	print_err(void)
{
	ft_putstr(INV_INP_MSG);
	exit(EXIT_FAILURE);
}
