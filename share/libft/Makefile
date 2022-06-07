SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
      ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
      ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
      ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_free_tabs.c\
			ft_free.c ft_tabs.c ft_tabs2.c ft_strjoin_update.c

OBJ = ${SRC:.c=.o}

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c\
	ft_lstnew.c ft_lstsize.c 

OBJ_BONUS = ${BONUS:.c=.o}

NAME = libft.a

CC  = gcc

RM  = rm -f

FLAG = -Wall -Werror -Wextra

all: ${NAME}

%.o: %.c
	gcc ${FLAG} -c $< -o $@

${NAME}: ${OBJ}
	ar r $@ $^
	ranlib $@ 

bonus: ${OBJ_BONUS}
	ar r ${NAME} $^
	ranlib ${NAME}

clean:
	${RM} *.o

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus fclean clean re	
