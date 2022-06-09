# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: engooh <engooh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 11:25:28 by engooh            #+#    #+#              #
#    Updated: 2022/06/09 16:33:04 by engooh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main.c src/routine.c src/init.c src/destroy.c src/join.c src/status.c src/parse.c src/utils.c src/time.c
OBJ = ${SRC:%.c=%.o}
SRC_BONUS = src_bonus/exit_bonus.c src_bonus/kill_bonus.c src_bonus/open_bonus.c src_bonus/routine_bonus.c src_bonus/init_bonus.c  src_bonus/main_bonus.c src_bonus/parse_bonus.c  src_bonus/utils_bonus.c src_bonus/status_bonus.c
OBJ_BONUS = ${SRC_BONUS:%.c=%.o}
CFLAG = -g3 -pthread -Wall -Wextra -Werror

all: philo

philo: $(OBJ)
	gcc $(CFLAG) $(OBJ) -o $@  share/libft/libft.a

fsanthread: $(OBJ)
	gcc -fsanitize=thread $(CFLAG) $(OBJ) -o philo share/libft/libft.a

fsanadress: $(OBJ)
	gcc -fsanitize=address $(CFLAG) $(OBJ) -o philo share/libft/libft.a

bonus: $(OBJ_BONUS)
	gcc $(CFLAG) $(OBJ_BONUS) -o philo share/libft/libft.a

fsanbonusthread: $(OBJ_BONUS)
	gcc -fsanitize=address $(CFLAG) $(OBJ_BONUS) -o philo share/libft/libft.a

fsanbonusadress: $(OBJ_BONUS)
	gcc -fsanitize=thread $(CFLAG) $(OBJ_BONUS) -o philo share/libft/libft.a

%.o: %.c
	gcc $(CFLAG) -c $^ -o $@ 

clean: 
	rm src/*.o
	rm src_bonus/*.o

fclean: clean 
	rm philo

re: fclean all

.PHONY: all fclean clean re bonus
