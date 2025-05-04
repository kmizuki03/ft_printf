# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kato <kato@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 11:50:00 by kato              #+#              #
#    Updated: 2025/05/03 11:46:32 by kato             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXEC = ft_printf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c src.c
OBJS = $(SRCS:.c=.o)

MAIN = main.c
MAIN_OBJS = $(MAIN:.c=.o)

all: $(NAME) $(EXEC)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(EXEC): $(NAME) $(MAIN_OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(MAIN_OBJS) $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(MAIN_OBJS)

fclean: clean
	$(RM) $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re
