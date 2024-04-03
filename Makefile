# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: del-ganb <del-ganb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 14:48:40 by del-ganb          #+#    #+#              #
#    Updated: 2024/04/03 15:54:17 by del-ganb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CSRCS = client.c
SSRCS = server.c

COBJS = $(CSRCS:.c=.o)
SOBJS = $(SSRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk.a
RM = rm -rf

all: $(NAME)

$(NAME): $(COBJS) $(SOBJS)
	ar rc $(NAME) $(COBJS) $(SOBJS)

clean:
	$(RM) $(COBJS) $(SOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re