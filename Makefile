# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 04:49:55 by agaladi           #+#    #+#              #
#    Updated: 2024/03/22 02:49:02 by agaladi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRCS = utils.c error_handling.c
SRVR = server.c
CLNT = client.c
BSRCS = client_bonus.c utils_bonus.c error_handling_bonus.c server_bonus.c
CFLAGS = -Wall -Wextra -Werror
DEPS = minitalk.h
NAME = minitalk.a
EXE1 = server
EXE2 = client
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
BDEPS = minitalk_bonus.h
BNAME = minitalk_bonus.a
BCLNT = client_bonus.c
BSRVR = server_bonus.c
BEXE1 = server_bonus
BEXE2 = client_bonus

all: $(NAME) $(EXE1) $(EXE2)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(BNAME): $(BOBJS)
	ar -rc $(BNAME) $(BOBJS)

%.o: %.c $(DEPS)
	$(CC) ${CFLAGS} -c $<

clean :
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -rf $(NAME) $(EXE1) $(EXE2) $(BNAME) $(BEXE1) $(BEXE2)

bonus: $(BNAME) $(BEXE1) $(BEXE2)

re : fclean all

$(BEXE1) : $(BNAME) $(BSRVR)
	$(CC) ${CFLAGS} $(BSRVR) $(BNAME) -o $(BEXE1)

$(BEXE2) : $(BNAME) $(BCLNT)
	$(CC) ${CFLAGS} $(BCLNT) $(BNAME) -o $(BEXE2)

$(EXE1) : $(NAME) $(SRVR)
	$(CC) ${CFLAGS} $(SRVR) $(NAME) -o $(EXE1)

$(EXE2) : $(NAME) $(CLNT)
	$(CC) ${CFLAGS} $(CLNT) $(NAME) -o $(EXE2)

