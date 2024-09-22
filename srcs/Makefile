_END = \033[0m
_BOLD = \033[1m
_UNDER = \033[4m
_RED = \033[31m
_FOREST_GREEN = \033[32m

FILES = error.c \
		file_checking.c \
		map_checking.c \
		map_checking2.c \
		parsing.c \
		support2.c \
		support3.c \
		textures_check.c \
		textures_check2.c \
		trash.c \
		wall_checker.c 

H_FILES = cub3d_mat.h

LIBFT = ../libft/libft.a

LIB_DIR = ../libft

HEADERS = $(addprefix $(SRC_DIR), $(H_FILES))

SRCS = $(addprefix $(SRC_DIR), $(FILES))

OBJS = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

SRC_DIR = parsing_folder/

OBJ_DIR = parsing_folder_objs/

NAME = parsing

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

TOTAL_FILES := $(words $(SRCS))

COMPILED_FILES := 0

define compile_file
@printf "\e[?25l"
@mkdir -p $(OBJ_DIR)
@${CC} ${CFLAGS} -c $1 -o $2
@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
@for i in `seq 1 $$(( $(COMPILED_FILES)*20/$(TOTAL_FILES) ))`; do printf "⬜"; done
@for i in `seq $$(( $(COMPILED_FILES)*20/$(TOTAL_FILES)+1 )) 20`; do printf "⬛"; done
@printf "  Compiling %s... \r" $1
endef


$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	$(call compile_file, $<, $@)

all: $(NAME)

$(LIBFT):
	@echo ""
	@make bonus -sC $(LIB_DIR)

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIB_DIR) -lft
	@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ ✅$(_BOLD) Parsing successfully built!$(_END)\n"
	@printf "\e[?25h"

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@make clean -sC $(LIB_DIR)
	@echo "\n$(_UNDER)cleaning..\n$(_END)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@echo "$(_UNDER)and cleaning again..\n$(_END)"

re: fclean all

x: $(NAME)
	@clear
	@./$(NAME) ../maps/map2.cub

.PHONY: all clean fclean re x