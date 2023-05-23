# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefooo                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 16:48:47 by mmesbahi          #+#    #+#              #
#    Updated: 2023/02/10 16:05:34 by mmesbahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = client
SNAME = server

NAME_BONUS = client_bonus
SNAME_BONUS = server_bonus

RM = rm -rf

SRC = client.c utils.c utils_2.c
SRS = server.c utils.c utils_2.c

SRC_BONUS = client_bonus.c utils.c utils_2.c
SRS_BONUS = server_bonus.c utils.c utils_2.c

OBJ = $(SRC:.c=.o)
OBJT = $(SRS:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJT_BONUS = $(SRS_BONUS:.c=.o)

all :$(SNAME) $(NAME) 


$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(SNAME) : $(OBJT)
	$(CC) $(CFLAGS) $(OBJT) -o $(SNAME)

bonus :$(SNAME_BONUS) $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

$(SNAME_BONUS) : $(OBJT_BONUS)
	$(CC) $(CFLAGS) $(OBJT_BONUS) -o $(SNAME_BONUS)

%.o : %.c minitalk.h minitalk_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all bonus 

clean:
		$(RM) $(OBJ) $(OBJT) $(OBJ_BONUS) $(OBJT_BONUS)
fclean : clean
		$(RM) $(NAME) $(SNAME) $(SNAME_BONUS) $(NAME_BONUS)
