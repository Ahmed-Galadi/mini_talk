/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:55:11 by agaladi           #+#    #+#             */
/*   Updated: 2024/02/21 06:27:41 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *str)
{
	while(*str)
		write(1, str++, 1);
}

static int	ft_isspace(char character)
{
	return (character == ' '
		|| character == '\n'
		|| character == '\t'
		|| character == '\f'
		|| character == '\v'
		|| character == '\r');
}

int	ft_atoi(const char *nptr)
{
	unsigned long output;
	int				sign;
	int				i;

	output = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		output = output * 10 + (nptr[i] - '0');
		i++;
	}
	return (output * sign);
}

static int nbr_len(int nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		count++;
	while (nbr)
	{	
		count++;
		nbr /= 10;
	}
	return (count);
}

char *ft_itoa(int n)
{
	char *nbr_str;
	int len_nbr;
	long nbr;

	nbr = n;
	len_nbr = nbr_len(nbr);
	nbr_str = malloc(len_nbr + 1);
	nbr_str[len_nbr + 1] = '\0';
	if (nbr < 0)
	{
		nbr_str[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
	{
		nbr_str[0] = '0';
		return (nbr_str);
	}
	while (nbr)
	{
		nbr_str[--len_nbr] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (nbr_str);
}