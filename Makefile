# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 04:49:55 by agaladi           #+#    #+#              #
#    Updated: 2024/03/21 04:14:41 by agaladi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRCS = utils.c error_handling.c

CFLAGS = -Wall -Wextra -Werror -c
DEPS = minitalk.h
NAME = minitalk.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) ${CFLAGS} $<

clean :
	rm -f $(OBJS)
	rm -f $(OBJSBONUS)

fclean : clean
	rm -rf $(NAME)

re : fclean all