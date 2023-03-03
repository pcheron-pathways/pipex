# project
NAME = pipex
BONUS = pipex_bonus

# compiler
CC = clang
CFLAGS = -Wall -Werror -Wextra -g
SAN = -fsanitize=address


# sources
SRC =	src/main.c \
		src/pipe_handling.c \
		src/files.c \
		src/tab.c \
		src/path.c 
SRC_BONUS = 
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# libft
LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

# include
INC_LIB = -I./libft/

# Colors
_END=\033[0m
_GREY=\033[30m
_RED=\033[31m
_GREEN=\033[32m
_YELLOW=\033[33m
_BLUE=\033[34m
_PURPLE=\033[35m
_CYAN=\033[36m
_WHITE=\033[37m

all : $(NAME)

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(NAME) : $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@ $(LIBFT) $(INC_LIB)
	@echo "$(_WHITE),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREEN)@@,,,((,,,,,,,,((,,,(((((,,/((,,@@@$(_END),,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREEN)@@,,,((,,,,,,,,((,,,((,,,((,,,,,@@@$(_END),,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREEN)@@,,,((,,,,,,,,((,,,(((((,,/((,,@@@$(_END),,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREEN)@@,,,((,,,,,,,,((,,,((,,,((,,,,,@@@$(_END),,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREEN)@@,,,((,,,,,,,,((,,,(((((,,/((,,@@@$(_END),,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,,,,,,$(_RED)%%%%%%%%%%%%%%%$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREEN)@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$(_END),,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,,,$(_RED)#%%%%%%%%%%%%%%%%%%%%%%$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREEN)@@,,,((,,,,,((((((((((((((((((((,,,((,,,,,@@@$(_END),,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,,,&&&&&&&&,,,,,@@,,,,,#,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREEN)@@,,,((,,,,,((((((((((((((((((((,,,((,,,,,@@@$(_END),,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,&&,,,&&,,,,,,,,@@,,,,,,,,#,,%%,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREEN)@@,,,((,,,,,(((((((((((((((((((((((,,/((,,@@@$(_END),,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,&&,,,&&&&&,,,,,,,@@@,,,,,,,#$(_RED)%%$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREEN)@@(((((,,,,,((((((((((((((((((((,,,((,,,,,@@@$(_END),,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,&&&&&,,,,,,,,,,@@@@@@@@@@$(_RED)%%$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREEN)@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@$(_END),,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_RED)#%%%%$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREEN)@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$(_END),,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,%%%$(_RED)%%%%%%%%%$(_BLUE)&&&$(_RED)%%%%%%%$(_BLUE)&&&$(_RED)%%%%%$(_END),,,,,$(_GREY)&&$(_END),,,,,,,,,,,,$(_PURPLE)______________________________________$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,%%%$(_RED)%%%%%%%%%%%%$(_BLUE)&&$(_RED)%%%%%%%%$(_BLUE)&&$(_END),,,,,$(_GREY)%&&&&$(_END),,,,,,,,,,,,$(_PURPLE)|                                    |$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,,,$(_RED)#%%%%%%%$(_BLUE)&&&&&&&&&&$(_YELLOW)[]$(_BLUE)&&&&&$(_GREY)&&&&&$(_END),,,,,,,,,,,,$(_PURPLE)|    ____  ____  ____  ____  _  _    |$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,,,,,,$(_BLUE)&&&&&$(_YELLOW)[]$(_BLUE)&&&&&&&&&&&&&&&$(_GREY)&&&&&$(_END),,,,,,,,,,,,$(_PURPLE)|   (  _ \(_  _)(  _ \( ___)( \/ )   |$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,$(_GREY)&&&$(_END)$(_BLUE)&&&&&&&&&&&&&&&&&&&&&&&&$(_GREY)&&&&&$(_END),,,,,,,,,,,,$(_PURPLE)|    )___/ _)(_  )___/ )__)  )  (    |$(_END),,,,,,,,,,,,,,,,,,,,,,,(##########),,,,,,,,,,,,,,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,$(_GREY)&&&&&&$(_END)$(_BLUE)&&&&&&&&&&&&&&&&&$(_END),,,,,,,,,,,,,,,,,,,,,,,,$(_PURPLE)|   (__)  (____)(__)  (____)(_/\_)   |$(_END),,,,,,,,,,,,,,,,,,,,(###############),,,,,,,,,,,,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,$(_GREY)&&&&&$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_PURPLE)|                                    |$(_END),,,,,,,,,,,,,,,,,,,(#################),,,,,,,,,,,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_PURPLE)|____________________________________|$(_END),,,,,,,,,,,,,,,,,,,,(###############),,,,,,,,,,,,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,(##########),,,,,,,,,,,,,,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,&##//(,,,,,,,,,,,,,,,,,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,$(_GREEN)@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,&%#((#,,,,,,,,,,,,,,,,,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,$(_GREEN)@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@@$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,&%%###,,,,,,,,,,,,,,,,,,,,,,,,$(_END)"
	@echo "$(_WHITE),,,,$(_GREEN)@@(((((,,,,,((((((((((((((((((((,,,((,,,,,@@@$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREY)#(((///,,,*,,,,%,*******,,,,,*,/,,,,,#/*,*****//($(_END),,$(_END)"
	@echo "$(_WHITE),,,,$(_GREEN)@@,,,((,,,,,(((((((((((((((((((((((,,/((,,@@@$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREY)%%%%%%#/*//,,,,%((((((((((/((//**,,,&%#(,//(((((/$(_END),,$(_END)"
	@echo "$(_WHITE),,,,$(_GREEN)@@,,,((,,,,,((((((((((((((((((((,,,((,,,,,@@@$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREY)/#######(/*/,,,,*///(//////*/*/***,,,((//****/*///$(_END),,$(_END)"
	@echo "$(_WHITE),,,,$(_GREEN)@@,,,((,,,,,(((((((((((((((((((((((,,/((,,@@@$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREY)(%%##%%%%####(#(//(((((((((/(/(/*,*//////(/(//*/(($(_END),,$(_END)"
	@echo "$(_WHITE),,,,$(_GREEN)@@,,,((,,,,,((((((((((((((((((((,,,((,,,,,@@@$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREY)#%%##%#%#######(*/(((((((((((((/*,*///(/////(/*((($(_END),,$(_END)"
	@echo "$(_WHITE),,,,,,$(_GREEN)@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREY)#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#%%%%%%%%%%%%%%%$(_END),,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,$(_GREEN)@@,,,((,,,,,,,,((,,,(((((,,/((,,@@@$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREY)#%#%%%%%%%%%%###%%%%%#%%#%#################(&$(_END),,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,$(_GREEN)@@,,,((,,,,,,,,((,,,((,,,((,,,,,@@@$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREY)(#########(#((((((/((/,*//***////////////*//$(_END),,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,$(_GREEN)@@,,,((,,,,,,,,((,,,(((((,,/((,,@@@$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREY)&%#(#%%########((((///,*/((((//((/((((//**(($(_END),,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,$(_GREEN)@@,,,((,,,,,,,,((,,,((,,,((,,,,,@@@$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREY)%#(#%%#######((((((/*,*/((((((///////(/**/($(_END),,,,,$(_END)"
	@echo "$(_WHITE),,,,,,,,,$(_GREEN)@@,,,((,,,,,,,,((,,,(((((,,/((,,@@@$(_END),,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,$(_GREY)%#(##########(((((/**,*//(///////(//((/**/($(_END),,,,,$(_END)"

malloc_test : $(LIBFT) $(OBJ) $(NAME)
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJ} $(LIBFT) $(INC_LIB) -L. -lmallocator 

bonus : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $^ -o $(BONUS)

clean :
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) $(BONUS) *.o

re : fclean all

%.o : %.c
	$(CC) -o $@ -c $^ -g
