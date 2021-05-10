# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomez-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 08:55:31 by pgomez-a          #+#    #+#              #
#    Updated: 2021/05/07 11:15:29 by pgomez-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:	all clean fclean re

SRCS	= ./stack/stack.c	\
		  ./stack/rules.c	\
		  ./stack/utils.c	\
		  check_input.c		\
		  check_list.c		\
		  utils.c

OBJS	= $(SRCS:.c=.o)

CH_SRCS	= checker.c		\
		  ch_rules.c

CH_OBJS	= $(CH_SRCS:.c=.o)

PS_SRCS	= push_swap.c	\
		  ps_calls.c		\
		  ps_three.c		\
		  ps_five.c

PS_OBJS	= $(PS_SRCS:.c=.o)

CH_NAME	= checker

PS_NAME	= push_swap

LIBS	= -L./libft/ -lft

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

all: $(CH_NAME) $(PS_NAME)

$(CH_NAME):	$(OBJS) $(CH_OBJS)
	@make -C ./libft/
	@$(CC) $(CFLAGS) $(LIBS) $(OBJS) $(CH_OBJS) -o $(CH_NAME)
	@echo "\033[93mChecker Compiled\033[39m"

$(PS_NAME):	$(OBJS) $(PS_OBJS)
	@make -C ./libft/
	@$(CC) $(CFLAGS) $(LIBS) $(OBJS) $(PS_OBJS) -o $(PS_NAME)
	@echo "\033[93mPush_swap compiled\033[39m"

clean:
	@make clean -C ./libft/
	@$(RM) $(OBJS) $(CH_OBJS) $(PS_OBJS)

fclean:		clean
	@make fclean -C ./libft/
	@$(RM) $(CH_NAME) $(PS_NAME)

re:			fclean all
