# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 16:58:07 by del-ganb          #+#    #+#              #
#    Updated: 2024/04/22 18:03:01 by del-ganb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CNAME = client
SNAME = server
CBONUS_NAME = client_bonus
SBONUS_NAME = server_bonus

CSRC = client.c
SSRC = server.c
CBONUS_SRC = client_bonus.c
SBONUS_SRC = server_bonus.c
UTILSRC = utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(CNAME) $(SNAME) $(CBONUS_NAME) $(SBONUS_NAME)

$(SNAME): $(SSRC) $(UTILSRC)
	$(CC) $(CFLAGS) $(UTILSRC) $(SSRC) -o $(SNAME)

$(CNAME): $(CSRC) $(UTILSRC)
	$(CC) $(CFLAGS) $(UTILSRC) $(CSRC) -o $(CNAME)

$(SBONUS_NAME): $(SBONUS_SRC) 
	$(CC) $(CFLAGS) $(UTILSRC) $(SBONUS_SRC) -o $(SBONUS_NAME)

$(CBONUS_NAME): $(CBONUS_SRC) $(UTILSRC)
	$(CC) $(CFLAGS) $(UTILSRC) $(CBONUS_SRC) -o $(CBONUS_NAME)

clean:
	$(RM) $(CNAME) $(SNAME) $(CBONUS_NAME) $(SBONUS_NAME)

fclean: clean
	$(RM) server client

re: fclean all

.PHONY: all clean fclean re


