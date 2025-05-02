# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kato <kato@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 00:00:00 by kato              #+#    #+#              #
#    Updated: 2025/05/02 23:21:21 by kato             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXEC = ft_printf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../libft

SRCS = ft_printf.c
MAIN = main.c

OBJS = $(SRCS:.c=.o)
MAIN_OBJS = $(MAIN:.c=.o)

AR = ar rcs
RM = rm -f

all: $(NAME) $(EXEC)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(EXEC): $(NAME) $(MAIN_OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(MAIN_OBJS) $(NAME) ../libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(MAIN_OBJS)

fclean: clean
	$(RM) $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re
