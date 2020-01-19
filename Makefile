# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 20:54:17 by vrabaib           #+#    #+#              #
#    Updated: 2019/10/27 21:24:00 by vrabaib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

CC = clang++
CPPFLAGS = -Wall -Werror -Wextra

HDRS = Bullet.hpp Enemy.hpp Player.hpp Screen.hpp Swarm.hpp Stars.hpp
SRCS = Bullet.cpp Enemy.cpp Player.cpp Screen.cpp Swarm.cpp Stars.cpp main.cpp
SRCO = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(SRCO) $(HDRS)
	$(CC) $(SRCO) -lncurses -o $@

%.o: %.cpp %.hpp
	$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
