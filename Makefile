NAME = so_long

# Compilation settings
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Detect the operating system
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    MLX_PATH = includes/MinilibX
    MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
    OS_FLAGS = -DOS_MAC
else
    MLX_PATH = includes/MinilibX
    MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz
    OS_FLAGS = -DOS_LINUX
endif

# Library paths and names
LIBFT_PATH = includes/Libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)/$(LIBFT_NAME)

PRINTF_PATH = includes/Printf
PRINTF_NAME = libftprintf.a
PRINTF = $(PRINTF_PATH)/$(PRINTF_NAME)

# Source and object files
SRC_PATH = ./srcs
UTILS_PATH = ./utils
SRC =                                                           \
                $(SRC_PATH)/choice.c           \
                $(SRC_PATH)/events.c            \
                $(SRC_PATH)/game.c            \
                $(SRC_PATH)/main.c                      \
                $(SRC_PATH)/maps.c                      \
                $(SRC_PATH)/menu.c                      \
                $(SRC_PATH)/moves.c                     \
                $(SRC_PATH)/parsing.c           \
                $(SRC_PATH)/render.c                    \
                $(UTILS_PATH)/event_utils.c             \
                $(UTILS_PATH)/mlx_utils.c             \
                $(UTILS_PATH)/map_utils.c               \
                $(UTILS_PATH)/render_utils.c             \

OBJ = $(SRC:.c=.o)

# Include paths
INCLUDES = -Iincludes -I$(MLX_PATH) -I$(LIBFT_PATH) -I$(PRINTF_PATH)

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "En bonne voie"
%.o: %.c
	@$(CC) $(CFLAGS) $(OS_FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(PRINTF):
	@make -C $(PRINTF_PATH)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_PATH) clean
	@make -C $(PRINTF_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
