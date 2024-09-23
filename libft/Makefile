# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cumoncoq <cumoncoq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 20:41:31 by cumoncoq          #+#    #+#              #
#    Updated: 2024/06/11 18:33:53 by cumoncoq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END=\033[0m
_BOLD=\033[1m
_UNDER=\033[4m
_REV=\033[7m
_RED=\033[31m
_FOREST_GREEN=\033[32m
_DARK_BLUE=\033[34m
_YELLOW=\033[33m
_ORANGE=\033[38;5;208m
_PURPLE=\033[38;5;129m
_PINK=\033[38;5;218m
_CYAN=\033[36m
_GREY=\033[30m
_BROWN=\033[38;5;137m
_KAKI=\033[38;5;136m
_GOLD=\033[38;5;220m
_SILVER=\033[38;6;7m
_MAGENTA=\033[35;5m
_EMMERALD=\033[38;5;118m
_LILAC=\033[38;5;127m
_LAGOON=\033[38;5;120m
_AQUAMARINE=\033[38;5;122m
_CORAL=\033[38;5;201m
_RIVIERA=\033[38;5;32m
_SALMON=\033[38;5;209m

LIBC += ft_itoa.c
LIBC += ft_atoi.c
LIBC += ft_bzero.c
LIBC += ft_split.c
LIBC += ft_printf.c
LIBC += ft_calloc.c
LIBC += ft_memchr.c
LIBC += ft_memcmp.c
LIBC += ft_memcpy.c
LIBC += ft_memset.c
LIBC += ft_strchr.c
LIBC += ft_strdup.c
LIBC += ft_strlen.c
LIBC += ft_substr.c
LIBC += ft_memmove.c
LIBC += ft_strlcat.c
LIBC += ft_strlcpy.c
LIBC += ft_strncmp.c
LIBC += ft_strnstr.c
LIBC += ft_strrchr.c
LIBC += ft_tolower.c
LIBC += ft_toupper.c
LIBC += ft_strjoin.c
LIBC += ft_strmapi.c
LIBC += ft_strtrim.c
LIBC += ft_isalnum.c
LIBC += ft_isalpha.c
LIBC += ft_isascii.c
LIBC += ft_isdigit.c
LIBC += ft_isprint.c
LIBC += ft_support.c
LIBC += ft_striteri.c
LIBC += ft_putnbr_fd.c
LIBC += ft_putstr_fd.c
LIBC += get_next_line.c
LIBC += ft_putchar_fd.c
LIBC += ft_putendl_fd.c
LIBC += get_next_line_utils.c

BONUS += ft_lstmap_bonus.c
BONUS += ft_lstnew_bonus.c
BONUS += ft_lstiter_bonus.c
BONUS += ft_lstlast_bonus.c
BONUS += ft_lstsize_bonus.c
BONUS += ft_lstclear_bonus.c
BONUS += ft_lstdelone_bonus.c
BONUS += ft_lstadd_back_bonus.c
BONUS += ft_lstadd_front_bonus.c


SRCS = ${LIBC}

SRCSALL = ${LIBC} ${BONUS}

OBJS = $(SRCS:.c=.o)

OBJSALL = ${SRCSALL:.c=.o}

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

TOTAL_FILES := $(words $(SRCSALL))

COMPILED_FILES := 0

define compile_file
@printf "\e[?25l"
@${CC} ${CFLAGS} -c $1 -o $2
@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
@printf "$(_GOLD)"
@for i in `seq 1 $$(( $(COMPILED_FILES)*20/$(TOTAL_FILES) ))`; do printf "🟨"; done
@for i in `seq $$(( $(COMPILED_FILES)*20/$(TOTAL_FILES)+1 )) 20`; do printf "⬛"; done
@printf "  Compiling %s... \r" $1
endef

%.o : %.c
	$(call compile_file,$<,$@)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨 ✅$(_BOLD)$(_GOLD) Libft successfully built.         \n$(_END)"
	@printf "\e[?25h"

bonus: ${OBJSALL}
	@ar -rcs $(NAME) $(OBJSALL)
	@echo "🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨🟨 ✅$(_BOLD)$(_GOLD) Libft successfully built.         \n$(_END)"
	@printf "\e[?25h"

all: $(NAME)

clean:
	rm -f $(OBJSALL)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
