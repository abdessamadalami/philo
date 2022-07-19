# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sultan <sultan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 12:32:39 by ael-oual          #+#    #+#              #
#    Updated: 2022/07/18 11:09:34 by sultan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BS = main.c message.c philo.c rotine.c tools.c
CC = gcc
CFLkAGS = -Wall -Wextra -Werror -g -fsanitize=thread #
NAME = philo
OBJB = $(BS:.c=.o)
all: $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) 
clean: 
	rm -f $(OBJB)
fclean:clean
re: fclean all