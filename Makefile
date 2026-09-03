# @--------------------------------------------------------------------------@ #
# |                                 Macros                                   | #
# @--------------------------------------------------------------------------@ #

ifdef WITH_BONUS
	NAME = cub3d_bonus
else
	NAME = cub3d
endif

INCLUDE_DIR = include/
MLX42_DIR = $(INCLUDE_DIR)MLX42/
OBJ_DIR = obj/
BFL_DIR = $(INCLUDE_DIR)BFL/
SRC_DIR = src/
LOG_DIR = $(SRC_DIR)log/
UTILS_DIR = utils/
V2_DIR = $(UTILS_DIR)v2/
COLORS_DIR = $(UTILS_DIR)colors/
SCREEN_DIR = $(UTILS_DIR)screen/

INCLUDE_FILES = cub3d.h\
				 cub_log.h\
				 utils.h\
				 v2.h\
				 colors.h

SRC_FILES = main.c\
			 error.c\
			 parser.c\
			 parser_2.c\
			 parser_3.c\
			 parser_4.c\
			 parser_5.c\
			 parser_6.c\

LOG_FILES = cub_log.c\
			 log_info.c\
			 log_error.c\


UTILS_FILES = utils.c\
			   calculate_step.c\
			   texture.c\
			   render2.c\
			   draw.c\
			   logic.c\
			   move.c\
			   player.c\
			   rotate.c\
			   map.c\
			   hook.c\
			   cub_resources.c\
			   ray.c\
			   wall.c\
			   collision.c\

ifdef WITH_BONUS
	UTILS_FILES += minimap_bonus.c
else
	UTILS_FILES += render.c
endif

V2_FILES = v2add.c\
			v2create.c\
			v2div.c\
			v2mult.c\
			v2sub.c\
			v2zero.c\
			v2equals.c\

COLORS_FILES = black.c\
				blue.c\
				darkgray.c\
				get_color.c\
				gray.c\
				green.c\
				lighblue.c\
				lightgreen.c\
				lightred.c\
				lightyellow.c\
				red.c\
				white.c\
				yellow.c\

SCREEN_FILES = create_screen.c\

BONUS_FILES = minimap_bonus.c\

INCLUDE = $(addprefix $(INCLUDE_DIR), $(INCLUDE_FILES))
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
LOG = $(addprefix $(LOG_DIR), $(LOG_FILES))
WEAPON = $(addprefix $(WEAPON_DIR), $(WEAPON_FILES))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))
V2 = $(addprefix $(V2_DIR), $(V2_FILES))
COLORS = $(addprefix $(COLORS_DIR), $(COLORS_FILES))
SCREEN = $(addprefix $(SCREEN_DIR), $(SCREEN_FILES))

VPATH = $(SRC_DIR)\
			 $(UTILS_DIR)\
			 $(LOG_DIR)\
			 $(WEAPON_DIR)\
			 $(V2_DIR)\
			 $(COLORS_DIR)\
			 $(SCREEN_DIR)\

LIBMLX42 = $(MLX42_DIR)build/libmlx42.a
LIBBFL = $(BFL_DIR)libBFL.a

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC)) \
	$(patsubst $(UTILS_DIR)%.c, $(OBJ_DIR)%.o, $(UTILS)) \
	$(patsubst $(LOG_DIR)%.c, $(OBJ_DIR)%.o, $(LOG)) \
	$(patsubst $(WEAPON_DIR)%.c, $(OBJ_DIR)%.o, $(WEAPON)) \
	$(patsubst $(V2_DIR)%.c, $(OBJ_DIR)%.o, $(V2)) \
	$(patsubst $(COLORS_DIR)%.c, $(OBJ_DIR)%.o, $(COLORS)) \
	$(patsubst $(SCREEN_DIR)%.c, $(OBJ_DIR)%.o, $(SCREEN))

CC = clang
CFLAGS = -Wall -Wextra -Werror -MMD -MP -O3
ifdef WITH_DEBUG
	CFLAGS += -gdwarf-2
endif
CPPFLAGS = -I $(INCLUDE_DIR) -I $(BFL_DIR)include -I $(MLX42_DIR)include/MLX42
LDFLAGS = -L $(BFL_DIR) -L $(MLX42_DIR)build
LDLIBS = -lBFL -lmlx42 -lglfw -pthread -lm -ldl

RM := rm -rf

# @--------------------------------------------------------------------------@ #
# |                                 Targets                                  | #
# @--------------------------------------------------------------------------@ #

all: $(NAME)

clean:
	@$(RM) $(OBJ_DIR)
	@make -s clean -C $(BFL_DIR)
	$(CLEAN_MSG)
	@make -s clean -C $(MLX42_DIR)/build

fclean:
	@make -s clean
	@$(RM) $(NAME) $(NAME)_bonus tags
	@make -s fclean -C $(BFL_DIR)
	$(FCLEAN_MSG)

re:
	@make -s fclean
	@make -s all

debug:
	@make -s fclean
	@make -s WITH_DEBUG=1

tags:
	@$(shell ctags $$(find . -name "*.[ch]"))

bonus:
	@make -s all WITH_BONUS=1

.PHONY: all bonus clean debug fclean re tags

$(NAME): $(LIBBFL) $(LIBMLX42) $(OBJ_DIR) $(OBJ)
	$(OBJ_MSG)
	@$(CC) -o $@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	$(OUTPUT_MSG)

$(LIBMLX42): $(MLX42_DIR)
	@git submodule update --init --recursive
	@cmake -S include/MLX42 -B include/MLX42/build
	@cmake --build include/MLX42/build -j

ifdef WITH_DEBUG
$(LIBBFL):
	@make -j -s debug -C $(BFL_DIR)
else
$(LIBBFL):
	@make -j -s -C $(BFL_DIR)
endif

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(LIBMLX42)
	@$(COMPILE_MSG)
	@$(CC) -o $@ $(CFLAGS) $(CPPFLAGS) -c $<

-include $(OBJ:.o=.d)

# @--------------------------------------------------------------------------@ #
# |                                 Colors                                   | #
# @--------------------------------------------------------------------------@ #

T_BLACK = \033[30m
T_RED = \033[31m
T_GREEN = \033[32m
T_YELLOW = \033[33m
T_BLUE = \033[34m
T_MAGENTA = \033[35m
T_CYAN = \033[36m
T_WHITE = \033[37m

BOLD = \033[1m
ITALIC = \033[2m
UNDERLINE = \033[3m
STRIKETHROUGH = \033[4m

CLEAR_LINE = \033[1F\r\033[2K

RESET = \033[0m

# @--------------------------------------------------------------------------@ #
# |                                Messages                                  | #
# @--------------------------------------------------------------------------@ #

COMPILE_MSG = @echo "🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
OBJ_MSG = @echo "✅ 🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_GREEN)created successfully!$(RESET)"
OUTPUT_MSG = @echo "✅ 🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully!$(RESET)"
CLEAN_MSG = @echo "🗑️  🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_RED)destroyed successfully!$(RESET)"
FCLEAN_MSG = @echo "🗑️  🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_RED)destroyed successfully!$(RESET)"
