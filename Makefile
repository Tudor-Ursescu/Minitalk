# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 08:46:50 by tursescu          #+#    #+#              #
#    Updated: 2024/09/10 17:08:27 by tursescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = client.c server.c 

CC = cc

RM = -rm -f

NAME = minitalk

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o:	%.c
			$(CC) $(CFLAGS) -Ilibft -c $? -o $@

$(NAME): server client

server:	server.o
		@make -C libft
		$(CC) $(CFLAGS) $? -Llibft -lft -o server
			
client:	client.o
		@make -C libft
		$(CC) $(CFLAGS) $? -Llibft -lft -o client

libft:		make -C libft

clean :
	$(RM) $(OBJS)
	@make clean -C libft

fclean : clean
	$(RM) server client

re: fclean all

.PHONY: all libft clean fclean re
	