# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: alfred <alfred@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/13 10:04:20 by alfred        #+#    #+#                  #
#    Updated: 2022/02/04 10:55:42 by fpolycar      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
FLAGS = -Wall -Werror -Wextra -fsanitize=address
LIBRARIES = -L$(LIBFT_DIRECTORY) -lft 
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

HEADERS_LIST = push_swap.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
c-files = push_swap.c utils.c utils2.c sort_small_stack.c instructions.c instructions2.c instructions3.c sort_big_stack.c optimize.c closest.c 
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(c-files))

OBJECTS_DIRECTORY = ./objects/
o-files = $(patsubst %.c, %.o, $(c-files))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(o-files))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME) $(LIBRARIES)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS)
	$(CC) $(FLAGS) -c -g $(INCLUDES) -o $@ $<
	
$(LIBFT):
	@make bonus -C $(LIBFT_DIRECTORY)
	
clean:
	@make clean -C $(LIBFT_DIRECTORY)
	@rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	@make fclean -C $(LIBFT_DIRECTORY)
	@rm -f $(NAME)

re: fclean all

