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
		wall_checker.c \

H_FILE = cub3d_mat.h

SRCS = $(addprefix $(SRCDIR),$(FILES))

HEADERS = $(addprefix $(SRCDIR),$(H_FILES))

OBJS = $(addprefix $(OBJDIR),$(FILES:.c=.o))

LIBFT = libft/libft.a

LIBFTDIR = libft

SRCDIR = srcs/

OBJDIR = objs/

NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

TOTAL_FILES := $(words $(SRCS))

COMPILED_FILES := 0

define compile_file
@printf "\e[?25l"
@mkdir -p $(OBJDIR)
@${CC} ${CFLAGS} $(INCLUDES) -c $1 -o $2
@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
@for i in `seq 1 $$(( $(COMPILED_FILES)*20/$(TOTAL_FILES) ))`; do printf "⬜"; done
@for i in `seq $$(( $(COMPILED_FILES)*20/$(TOTAL_FILES)+1 )) 20`; do printf "⬛"; done
@printf "  Compiling %s... \r" $1
endef

all: $(NAME)

$(LIBFT):
	@echo ""
	@make bonus -sC $(LIBFTDIR)

$(OBJDIR)%.o : $(SRCDIR)%.c $(HEADERS)
	$(call compile_file,$<,$@)

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	@$(CC) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft
	@echo "⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ ✅$(_BOLD) Cub3d successfully built!$(_END)\n"
	@printf "\e[?25h"

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
	@make clean -sC $(LIBFTDIR)
	@echo "\n$(_UNDER)cleaning..\n$(_END)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@echo "$(_UNDER)and cleaning again..\n$(_END)"

push: fclean
	@git add .
	@git commit -m make
	@git push > /dev/null 2>&1
	@if [ $$? -eq 0 ]; then \
		printf "\033[38;5;255m          ,~-. \033[0m\n";\
		printf "\033[38;5;255m         (  ' )-.          ,~'\`-. \033[0m\n";\
		printf "\033[38;5;255m      ,~' \`  ' ) )       _(   _) ) \033[0m\n";\
		printf "\033[38;5;255m     ( (\033[38;5;111m .--.===.--.  \033[38;5;255m  (  \`    ' ) \033[0m\n";\
		printf "\033[38;5;111m      \`.%%.;::|888.#\`. \033[38;5;255m  \`-'\`~~=~' \033[0m\n";\
		printf "\033[38;5;117m      /%%/::::|8888\##\\ \033[0m\n";\
		printf "\033[38;5;123m     |%%/:::::|88888\##| \033[0m\n";\
		printf "\033[38;5;159m     |%%|:::::|88888|##|\033[38;5;255m.,-. \033[0m\n";\
		printf "\033[38;5;195m     \%%|:::::|88888|##/ \033[38;5;255m   )_ \033[0m\n";\
		printf "\033[38;5;255m      \%%\:::::|88888/#/ ( \`'  ) \033[0m\n";\
		printf "\033[38;5;253m       \%%\::::|8888/#/(  ,  -'\`-. \033[0m\n";\
		printf "\033[38;5;255m   ,~-.\033[38;5;251m \`%%\:::|888/#'\033[38;5;255m(  (     ') ) \033[0m\n";\
		printf "\033[38;5;255m  (  ) )_\033[38;5;249m \`\__|__/' \033[38;5;255m  \`~-~=--~~=' \033[0m\n";\
		printf "\033[38;5;255m ( \` ')  )\033[38;5;247m [VVVVV] \033[0m\n";\
		printf "\033[38;5;255m(_(_.~~~' \033[38;5;245m  \|_|/      \033[0m\n";\
		printf "\033[38;5;243m            [XXX] \033[0m\n";\
		printf "$(_BOLD)\n    Travail terminé !  \n\033[0m\n"\
    else \
        echo "$(_RED)$(_BOLD)\n  Git push failed!  \n$(_END)"; \
    fi

re: fclean all