# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 14:08:08 by smizuoch          #+#    #+#              #
#    Updated: 2023/12/12 15:29:57 by smizuoch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INC_DIR = ./includes

SRCS_DIR = ./srcs

SRCS_FILES = main.c \
			init_arg.c \
			ft_isdigit.c \
			philo_atoi.c \
			

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
	$(RM) $(RMFLAGS) #(NAME)
	
re: fclean all

.PHONY: all clean fclean re debug