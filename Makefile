# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 14:37:00 by aguemazi          #+#    #+#              #
#    Updated: 2022/11/02 13:40:07 by aguemazi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_thread_function.c main_function.c utils.c ft_usleep.c ft_putchar_fd.c ft_itoa.c ft_putstr_fd.c ft_strlen.c ft_putnbr_fd.c ft_bzero.c ft_strjoin.c main.c

OBJS	=	$(SRCS:.c=.o)

GCC		=	gcc

RM		=	rm -rf

FLAGS	=	-Wall -Wextra -Werror  #-fsanitize=thread

NAME	=	philo

all:		$(NAME)

%.o:		%.c
			@$(GCC) -I. -o $@ -c $? $(FLAGS) -g3

$(NAME):	$(OBJS)
			@$(GCC) $(FLAGS) $(OBJS) -o $(NAME) 
			@echo "\033[1;32mCompilation complete ✅";

clean:
			@$(RM) $(OBJS)
			@echo "\033[1;32mCleaning complete 🧽"

fclean:		clean
			@$(RM) $(NAME)
			@echo "\033[1;32mFull cleaning complete 🧹"

re:			fclean all
			@echo "\033[1;32mRebuild complete 🔨"

.PHONY:		all fclean clean re
