# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geonlee <geonlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 00:37:21 by geonlee           #+#    #+#              #
#    Updated: 2023/01/26 15:29:38 by geonlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS = main.c\
		move.c\
		parse_map.c\
		bfs_map.c\
		get_next_line.c\
		get_next_line2.c\

FLAGS	= -Wall -Wextra -Werror

OBJS	= $(SRCS:%.c=%.o)

all	:	$(NAME)

%.o : %.c
	cc $(FLAGS) -c $^

$(NAME)	:	$(OBJS)
	cc $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re