COLOR_RESET = \033[0m
COLOR_RED = \033[91m
COLOR_GREEN = \033[92m
COLOR_YELLOW = \033[93m
COLOR_BOLD = \033[1m
MAKEFLAGS += --no-print-directory


NAME	:= so_long

SRC_DIR	:= src
OBJ_DIR	:= obj
SRCS	= $(PATH_LIBFT) $(GET_NEXT_LINE_PATH) $(SO_LONG_PATH)
# libft
PATH_LIBFT	= $(libft:%=src/libft/%)
libft		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
			ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
			ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\

GET_NEXT_LINE_PATH	= $(get_next_line:%=src/gnl/%)
get_next_line		= get_next_line.c get_next_line_utils.c

SO_LONG_PATH	= $(so_long:%=src/so_long/%)
so_long			= so_long.c init_maps.c ft_maps_valide.c flood_fill.c key_mlx.c image.c\
				is_key.c
				
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS		:= -Wall -Wextra -Werror
CFLAGS		+= -g3
CCFLAGS		:= -I include

RM		:= rm -rf
DIR_DUP	= mkdir -p $(@D)

all: $(NAME)


$(NAME): $(OBJS)
		@make -C minilibx/
		@$(CC) $(OBJS) minilibx/libmlx_Linux.a -L mlx -lXext -lX11 -lm  -o $(NAME)
		@echo "$(COLOR_GREEN)$(COLOR_BOLD)Compilation faite 👍 $(COLOR_RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/libft.h include/so_long.h include/get_next_line.h
		@$(DIR_DUP)
		@$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(OBJ_DIR) $(NAME)
	

re:
	@$(MAKE) fclean
	@$(MAKE) all