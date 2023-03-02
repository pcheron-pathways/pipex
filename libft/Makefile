# project
NAME = libft.a

# compiler
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs

# sources
SRC = 	ft_memo.c \
		ft_str_utils.c \
		ft_split.c
OBJ = $(SRC:.c=.o)
SRC_B = 
OBJ_B = $(SRC_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $^

%.o : %.c
	$(CC) -o $@ -c $^

.sentinel_bonus : $(OBJ_B)
	$(AR) $(NAME) $^
	touch .sentinel_bonus

bonus : .sentinel_bonus

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)
	rm -rf .sentinel_bonus

re : fclean all

.PHONY: re clean fclean bonus all
