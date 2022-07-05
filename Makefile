# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 12:32:39 by ael-oual          #+#    #+#              #
#    Updated: 2022/07/04 18:09:25 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BS = main.c message.c philo.c rotine.c tools.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror# -fsanitize=thread
NAME = philo
OBJB = $(BS:.c=.o)
all: $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) 
clean: 
	rm -f $(OBJB)
fclean:clean
re: fclean all