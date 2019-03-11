# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/10 16:31:25 by cdeniau           #+#    #+#              #
#    Updated: 2019/03/11 09:59:29 by cdeniau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ssl
ALL_CFLAGS	= -Wall -Werror -Wextra
CC			= gcc
RM			= rm -rf
LIBFT_DIR	= ./libft/
OBJS_DIR	= objs
SRCS_DIR	= srcs
INCS_DIR	= incs
SRCS		= ft_ssl.c					\
			  fi_ctor.c					\
			  fi_dtor.c					\
			  fi_run.c
OBJS		= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT_DIR)
			$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
		$(CC) $(ALL_CFLAGS) -I$(INCS_DIR) -I$(LIBFT_DIR)/$(INCS_DIR) -c $< -o $@
			@echo "\033[A\033[K\033[A"

clean:
		@$(RM) $(OBJS)	

fclean: clean
		@$(RM) $(NAME)

re: fclean all

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
		mkdir $(OBJS_DIR)
