/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 05:05:24 by agaladi           #+#    #+#             */
/*   Updated: 2024/03/21 21:45:46 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# define TITLE_MSG "\
\033[1;36m███╗░░░███╗██╗███╗░░██╗██╗████████╗░█████╗░██╗░░░░░██╗░░██╗\n\
████╗░████║██║████╗░██║██║╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n\
██╔████╔██║██║██╔██╗██║██║░░░██║░░░███████║██║░░░░░█████═╝░\n\
██║╚██╔╝██║██║██║╚████║██║░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n\
██║░╚═╝░██║██║██║░╚███║██║░░░██║░░░██║░░██║███████╗██║░╚██╗\n\
╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝"

# define H_DEVIDER "\e[0;31m    ┄─━ ࿅ ༻  ✣ ༺ ࿅ ━─┄   \033[1;0m "

# define V_DEVIDER "\
\n\033[1;0m\e[0;34mতততততততততততততত\
ততততততততততততততততততততততততততততত\
তততততততততততততততততত\033[1;0m\n"

# define INV_INP_MSG "\
\033[38;5;9m\n\
████████████████████████████████████████████████████████████████████████████████\n\
█▄─▄█▄─▀█▄─▄█▄─█─▄██▀▄─██▄─▄███▄─▄█▄─▄▄▀███▄─▄█▄─▀█▄─▄█▄─▄▄─█▄─██─▄█─▄─▄─███░█░█\n\
██─███─█▄▀─███▄▀▄███─▀─███─██▀██─███─██─████─███─█▄▀─███─▄▄▄██─██─████─█████▄█▄█\n\
▀▄▄▄▀▄▄▄▀▀▄▄▀▀▀▄▀▀▀▄▄▀▄▄▀▄▄▄▄▄▀▄▄▄▀▄▄▄▄▀▀▀▀▄▄▄▀▄▄▄▀▀▄▄▀▄▄▄▀▀▀▀▄▄▄▄▀▀▀▄▄▄▀▀▀▀▄▀▄▀\033[0m\n\n\
\033[38;5;5m𝕡𝕝𝕖𝕒𝕤𝕖 𝕖𝕟𝕥𝕖𝕣 :\033[0m\033[38;5;208m	./client <server_pid> <message>\n\
"
# define SUCC_MSG "\n\
\033[38;5;10m        _____________________________\n\
\033[38;5;10m      /                    /   /   /\n\
\033[38;5;10m     /   \033[38;5;32m𝔐𝔢𝔰𝔰𝔞𝔤𝔢\033[0m      \033[38;5;10m    /__./   /\n\
\033[38;5;10m    /                ________    /\n\
\033[38;5;10m   /    \033[38;5;32m𝔯𝔢𝔠𝔢𝔦𝔳𝔢𝔡\033[0m  \033[38;5;10m  ________    /\n\
\033[38;5;10m  /                _______     /\n\
\033[38;5;10m /  \033[38;5;32m𝔰𝔲𝔠𝔠𝔢𝔰𝔰𝔣𝔲𝔩𝔩𝔶\033[0m    \033[38;5;10m          /\n\
\033[38;5;10m/____________________________/\n\
"

void	ft_putstr(char *str);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		is_valid(char *pid, char *message);
void	print_err(void);

#endif