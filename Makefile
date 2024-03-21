# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 04:49:55 by agaladi           #+#    #+#              #
#    Updated: 2024/03/21 20:57:20 by agaladi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRCS = utils.c error_handling.c

CFLAGS = -Wall -Wextra -Werror
DEPS = minitalk.h
NAME = minitalk.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) ${CFLAGS} -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

xx : all
	$(CC) ${CFLAGS} server.c $(NAME) -o server
	$(CC) ${CFLAGS} client.c $(NAME) -o client
