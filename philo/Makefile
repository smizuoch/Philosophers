# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 14:08:08 by smizuoch          #+#    #+#              #
#    Updated: 2024/02/21 20:50:51 by smizuoch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INC_DIR = ./includes

SRCS_DIR = ./srcs

SRCS_FILES = main.c \
			init_arg.c \
			ft_isdigit.c \
			philo_atoi.c \
			init_philo.c \
			start_life.c \
			time.c \
			put_action.c \
			do_eat.c \
			do_sleep.c \
			do_think.c \
			observer.c \
			

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) 

RM = rm

RMFLAGS = -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re debug