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
ITALIC := \033[2m
UNDERLINE := \033[3m
STRIKETHROUGH := \033[4m

CLEAR_LINE := \033[1F\r\033[2K

RESET := \033[0m

# @--------------------------------------------------------------------------@ #
# |                                 Macros                                   | #
# @--------------------------------------------------------------------------@ #

NAME := cub3d

INCLUDE_DIR := include/
BFL_DIR := $(INCLUDE_DIR)BFL/
SRC_DIR := src/
UTILS_DIR := utils/
OBJ_DIR := obj/

INCLUDE_FILES := cub3d.h
SRC_FILES := cub3d.c parser.c parser_2.c parser_3.c error.c
UTILS_FILES := utils.c

INCLUDE = $(addprefix $(INCLUDE_DIR), $(INCLUDE_FILES))
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC)) \
	$(patsubst $(UTILS_DIR)%.c, $(OBJ_DIR)%.o, $(UTILS))

CC = clang

ifdef WITH_DEBUG
	CFLAGS := -Wall -Wextra -Werror -gdwarf-2 
else
	CFLAGS := -Wall -Wextra -Werror
endif

CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I $(INCLUDE_DIR) -I $(BFL_DIR)include
LDFLAGS := -L $(BFL_DIR)

RM := rm -rf

# @--------------------------------------------------------------------------@ #
# |                                Messages                                  | #
# @--------------------------------------------------------------------------@ #

COMPILE_MSG = @echo "$(CLEAR_LINE)🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
OBJ_MSG = @echo "✅ 🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_GREEN)created successfully!$(RESET)"
OUTPUT_MSG = @echo "✅ 🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully!$(RESET)"
CLEAN_MSG = @echo "🗑️  🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_RED)destroyed successfully!$(RESET)"
FCLEAN_MSG = @echo "🗑️  🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_RED)destroyed successfully!$(RESET)"

# @--------------------------------------------------------------------------@ #
# |                                 Targets                                  | #
# @--------------------------------------------------------------------------@ #

all: $(NAME)

ifdef WITH_DEBUG
$(NAME): $(OBJ_DIR) $(OBJ)
	$(OBJ_MSG)
	@make -s debug -C $(BFL_DIR)
	@$(CC) -o $@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	$(OUTPUT_MSG)
else
$(NAME): $(OBJ_DIR) $(OBJ)
	$(OBJ_MSG)
	@make -s -C $(BFL_DIR)
	@$(CC) -o $@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	$(OUTPUT_MSG)
endif

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(BUILTIN_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(EXECUTE_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -s -C $(BFL_DIR)
	$(CLEAN_MSG)

fclean: clean
	@$(RM) $(NAME) tags
	@make fclean -s -C $(BFL_DIR)
	$(FCLEAN_MSG)

re:
	@make -s fclean
	@make -s all

debug:
	@make debug -C $(BFL_DIR)
	@make -s WITH_DEBUG=1

tags:
	@$(shell ctags $$(find . -name "*.[ch]"))

bonus:
	@make -s -C bonus_part

.PHONY: all bonus clean debug fclean re tags
