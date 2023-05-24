# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 15:26:52 by tfranchi          #+#    #+#              #
#    Updated: 2023/05/21 15:26:52 by tfranchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Sources ------------------------------

# LIBFT & PRINTF

MAKE_LIBFT			=	cd libft && make -s

LIBFT				=	libft/libft.a

# Sources and objects

SERVER_SRC			=	server.c

SERVER_OBJ			=	$(SERVER_SRC:.c=.o)

CLIENT_SRC			=	client.c

CLIENT_OBJ			=	$(CLIENT_SRC:.c=.o)

GCC					=	gcc

FLAGS				=	-Wall -Wextra -Werror

FSANITIZE			= 	-fsanitize=address -g3

SERVER_NAME			=	server

CLIENT_NAME			=	client

NAME				=	minitalk



START				=	echo "\n START COMPILATION \n"

LIBFT_READY			=	echo "\n LIBFT COMPILED \n"

SERVER_READY		=	echo "\n SERVER DONE ! \n"

CLIENT_READY		=	echo "\n CLIENT DONE ! \n"

all: $(NAME)

$(NAME): make server client

make:
	@$(START)
	@$(MAKE_LIBFT)
	@$(LIBFT_READY)

server: $(SERVER_OBJ)
	@$(GCC) $(FLAGS) $(SERVER_OBJ) $(LIBFT) $(FSANITIZE) -o $(SERVER_NAME)
	@$(SERVER_READY)

client: $(CLIENT_OBJ)
	@$(GCC) $(FLAGS) $(CLIENT_OBJ) $(LIBFT) $(FSANITIZE) -o $(CLIENT_NAME)
	@$(CLIENT_READY)

clean:
	@rm -rf $(SERVER_OBJ) $(CLIENT_OBJ)
	@cd libft && make -s clean

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	@cd libft && make -s fclean

re:	fclean all

.PHONY: all server client clean fclean re libft