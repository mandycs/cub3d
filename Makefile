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
LOG_DIR := $(SRC_DIR)/log/
WEAPON_DIR := $(SRC_DIR)/weapon/
UTILS_DIR := utils/
MLX42_DIR := $(INCLUDE_DIR)MLX42/
OBJ_DIR := obj/

INCLUDE_FILES := cub3d.h
SRC_FILES := cub3d.c parser.c parser_2.c parser_3.c parser_4.c parser_5.c error.c
LOG_FILES := cub_log.c log_info.c log_error.c
WEAPON_FILES := create_weapon.c attack.c switch_weapon.c reload_ammo.c create_toolbar.c
UTILS_FILES := utils.c v2add.c v2create.c v2div.c v2mult.c v2sub.c v2zero.c

INCLUDE = $(addprefix $(INCLUDE_DIR), $(INCLUDE_FILES))
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))
LOG = $(addprefix $(LOG_DIR), $(LOG_FILES))
WEAPON = $(addprefix $(WEAPON_DIR), $(WEAPON_FILES))

LIBMLX42 := $(MLX42_DIR)/build/libmlx42.a

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC)) \
	$(patsubst $(UTILS_DIR)%.c, $(OBJ_DIR)%.o, $(UTILS)) \
	$(patsubst $(LOG_DIR)%.c, $(OBJ_DIR)%.o, $(LOG)) \
	$(patsubst $(WEAPON_DIR)%.c, $(OBJ_DIR)%.o, $(WEAPON))

CC := clang

ifdef WITH_DEBUG
	CFLAGS := -Wall -Wextra -Werror -gdwarf-2 
else
	CFLAGS := -Wall -Wextra -Werror
endif

CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I $(INCLUDE_DIR) -I $(BFL_DIR)include -I $(MLX42_DIR)/include/MLX42
LDFLAGS := -L $(BFL_DIR) -L $(MLX42_DIR)/build
LDLIBS := -lBFL -lmlx42 -lglfw -pthread -lm -ldl

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

run: main
	./$(NAME)

main: build_mlx42
	make -j4 -s -C $(BFL_DIR)
	clang -o cub3d -g -Wall -Wextra -Werror src/main.c utils/*.c src/log/*.c src/weapon/*.c $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

all: build_mlx42 $(NAME)

ifdef WITH_DEBUG
$(NAME): $(LIBMLX42) $(OBJ_DIR) $(OBJ)
	$(OBJ_MSG)
	@make -j4 -s debug -C $(BFL_DIR)
	@$(CC) -o $@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	$(OUTPUT_MSG)
else
$(NAME): $(LIBMLX42) $(OBJ_DIR) $(OBJ)
	$(OBJ_MSG)
	@make -j4 -s -C $(BFL_DIR)
	@$(CC) -o $@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	$(OUTPUT_MSG)
endif

$(LIBMLX42): $(MLX42_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(LOG_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(WEAPON_DIR)%.c $(INCLUDE)
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

build_mlx42:
	@git submodule update --init --recursive
	@cmake -S include/MLX42 -B include/MLX42/build
	@cmake --build include/MLX42/build -j4

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -s -C $(BFL_DIR)
	$(CLEAN_MSG)
	@make clean -s -C $(MLX42_DIR)/build

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

# This will be removed later
norm_main:
	norminette src/main.c | grep -v "Too many" | grep -v "Forbidden control" | grep -v "Typedef declaration" | grep -v "Enum declaration" | grep -v "Struct declaration"

.PHONY: all bonus build_mlx42 clean debug fclean re tags
