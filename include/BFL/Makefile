# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 15:47:45 by ribana-b          #+#    #+#              #
#    Updated: 2025/01/01 15:13:56 by ribana-b         ###   ########.com       #
#                                                                              #
# **************************************************************************** #

# @--------------------------------------------------------------------------@ #
# |                                 Colors                                   | #
# @--------------------------------------------------------------------------@ #

T_BLACK := \033[30m
T_RED := \033[31m
T_GREEN := \033[32m
T_YELLOW := \033[33m
T_BLUE := \033[34m
T_MAGENTA := \033[35m
T_CYAN := \033[36m
T_WHITE := \033[37m

BOLD := \033[1m
ITALIC := \033[3m
UNDERLINE := \033[4m
STRIKETHROUGH := \033[5m

B_BLACK := \033[40m
B_RED := \033[41m
B_GREEN := \033[42m
B_YELLOW := \033[43m
B_BLUE := \033[44m
B_MAGENTA := \033[45m
B_CYAN := \033[46m
B_WHITE := \033[47m

CLEAR_LINE := \033[1F\r\033[2K

RESET := \033[0m

# @--------------------------------------------------------------------------@ #
# |                                 Macros                                   | #
# @--------------------------------------------------------------------------@ #

NAME := libBFL.a

INCLUDE_DIR := ./include/
BOOL_DIR := ./bool/
CHAR_DIR := ./char/
LINKED_LIST_DIR := ./linked_list/
FD_DIR := ./fd/
BFL_PRINTF_DIR := ./bfl_printf/
GET_NEXT_LINE_DIR := ./get_next_line/
MATH_DIR := ./math/
MEMORY_DIR := ./memory/
STRING_DIR := ./string/
OBJ_DIR := ./obj/

INCLUDE_FILES := BFL.h

BOOL_FILES := bfl_isalnum.c \
				bfl_isalpha.c \
				bfl_isascii.c \
				bfl_isblank.c \
				bfl_isdigit.c \
				bfl_islower.c \
				bfl_isprint.c \
				bfl_isupper.c \
				bfl_isxdigit.c \
				bfl_isspace.c \

CHAR_FILES := bfl_tolower.c \
				bfl_toupper.c \

LINKED_LIST_FILES := bfl_ll_create_node.c \
						bfl_ll_generate.c \
						bfl_ll_add_back.c \
						bfl_ll_add_front.c \
						bfl_ll_destroy_content.c \
						bfl_ll_destroy_one.c \
						bfl_ll_destroy.c \
						bfl_ll_size.c \

FD_FILES := bfl_putaddress_fd.c \
			bfl_putchar_fd.c \
			bfl_putendl_fd.c \
			bfl_puthexl_fd.c \
			bfl_puthexu_fd.c \
			bfl_putnbr_fd.c \
			bfl_putstr_fd.c \
			bfl_putunbr_fd.c \

BFL_PRINTF_FILES := bfl_printf.c \
					bfl_fprintf.c \

GET_NEXT_LINE_FILES := get_next_line.c

MATH_FILES := bfl_gcd.c \
			 bfl_lcm.c \
			 bfl_pow.c \
			 bfl_sqrt.c \
			 bfl_mod.c

MEMORY_FILES := bfl_bzero.c \
				bfl_calloc.c \
				bfl_free.c \
				bfl_memchr.c \
				bfl_memcmp.c \
				bfl_memcpy.c \
				bfl_memmove.c \
				bfl_memset.c \
				bfl_realloc.c \

STRING_FILES := bfl_atoi.c \
				bfl_atol.c \
				bfl_itoa.c \
				bfl_strbuild.c \
				bfl_strchr.c \
				bfl_strdup.c \
				bfl_striteri.c \
				bfl_strjoin.c \
				bfl_strlcat.c \
				bfl_strlcpy.c \
				bfl_strlen.c \
				bfl_strmapi.c \
				bfl_strcmp.c \
				bfl_strncmp.c \
				bfl_strnstr.c \
				bfl_split.c \
				bfl_splitlen.c \
				bfl_strrchr.c \
				bfl_substr.c \
				bfl_strndup.c \

INCLUDE = $(addprefix $(INCLUDE_DIR), $(INCLUDE_FILES))
BOOL = $(addprefix $(BOOL_DIR), $(BOOL_FILES))
CHAR = $(addprefix $(CHAR_DIR), $(CHAR_FILES))
LINKED_LIST = $(addprefix $(LINKED_LIST_DIR), $(LINKED_LIST_FILES))
FD = $(addprefix $(FD_DIR), $(FD_FILES))
BFL_PRINTF = $(addprefix $(BFL_PRINTF_DIR), $(BFL_PRINTF_FILES))
GET_NEXT_LINE = $(addprefix $(GET_NEXT_LINE_DIR), $(GET_NEXT_LINE_FILES))
MATH = $(addprefix $(MATH_DIR), $(MATH_FILES))
MEMORY = $(addprefix $(MEMORY_DIR), $(MEMORY_FILES))
STRING = $(addprefix $(STRING_DIR), $(STRING_FILES))

OBJ = $(patsubst $(BOOL_DIR)%.c, $(OBJ_DIR)%.o, $(BOOL)) \
		$(patsubst $(CHAR_DIR)%.c, $(OBJ_DIR)%.o, $(CHAR)) \
		$(patsubst $(LINKED_LIST_DIR)%.c, $(OBJ_DIR)%.o, $(LINKED_LIST)) \
		$(patsubst $(FD_DIR)%.c, $(OBJ_DIR)%.o, $(FD)) \
		$(patsubst $(BFL_PRINTF_DIR)%.c, $(OBJ_DIR)%.o, $(BFL_PRINTF)) \
		$(patsubst $(GET_NEXT_LINE_DIR)%.c, $(OBJ_DIR)%.o, $(GET_NEXT_LINE)) \
		$(patsubst $(MATH_DIR)%.c, $(OBJ_DIR)%.o, $(MATH)) \
		$(patsubst $(MEMORY_DIR)%.c, $(OBJ_DIR)%.o, $(MEMORY)) \
		$(patsubst $(STRING_DIR)%.c, $(OBJ_DIR)%.o, $(STRING))

CC := clang

ifdef WITH_DEBUG
	CFLAGS := -Wall -Wextra -Werror -gdwarf-2
else
	CFLAGS := -Wall -Wextra -Werror
endif

CPPFLAGS := -I $(INCLUDE_DIR)

RM := rm -rf

# @--------------------------------------------------------------------------@ #
# |                                Messages                                  | #
# @--------------------------------------------------------------------------@ #

COMPILE_MSG = @echo "$(CLEAR_LINE)🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
OBJ_MSG = @echo "✅ 🦔 $(T_YELLOW)$(BOLD)$(NAME) Objects $(RESET)$(T_GREEN)created successfully$(RESET)"
OUTPUT_MSG = @echo "✅ 🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully$(RESET)"
CLEAN_MSG = @echo "🗑️  🦔 $(T_YELLOW)$(BOLD)$(NAME) Objects $(RESET)$(T_RED)destroyed successfully$(RESET)"
FCLEAN_MSG = @echo "🗑️  🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_RED)destroyed successfully$(RESET)"

# @--------------------------------------------------------------------------@ #
# |                                 Targets                                  | #
# @--------------------------------------------------------------------------@ #

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(OBJ_MSG)
	@ar rcs $@ $(OBJ)
	$(OUTPUT_MSG)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo

$(OBJ_DIR)%.o: $(BOOL_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(CHAR_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(LINKED_LIST_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(FD_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(BFL_PRINTF_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(GET_NEXT_LINE_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(MATH_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(MEMORY_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(STRING_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	$(CLEAN_MSG)

fclean: clean
	@$(RM) $(NAME)
	$(FCLEAN_MSG)

re:
	@make -s fclean
	@make -s all

test: all
	@$(CC) $(CFLAGS) $(CPPFLAGS) test/main_test.c $(NAME)
	@./a.out
	@rm ./a.out *.txt

debug: fclean
	@make -s WITH_DEBUG=1

.PHONY: all clean debug fclean re test
