#-PATH FILES-#

SRC_DIR			= src
SRC_BONUS_DIR	= src_bonus
OBJ_DIR			= obj
OBJ_BONUS_DIR	= obj_bonus

#-LIBFT-#

LIBFT			= lib/libft
LIBFT_A			= lib/libft/libft.a

#-LIBMLX-#

LIBMLX			= lib/MLX42
LIBMLX_A		= $(LIBMLX)/build/libmlx42.a 
HEADERS			= -I ./include -I $(LIBMLX)/include

#-SRC-#

SRCS			= \
				main.c \
				fct_hook.c \
				REPLACE_parsing.c \
				print_map/draw_minimap.c \
				print_map/utils.c \
				manage_player/minimap_player.c \
				command/key_hook.c \

SRC				= $(addprefix src/, $(SRCS))
OBJS			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
D_OBJS			= mkdir -p $(@D)

#-BONUS-#

SRCS_BONUS		= \

SRC_BONUS		= $(addprefix src_bonus/, $(SRCS_BONUS))
OBJS_BONUS		= $(SRC_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)
D_OBJS_BONUS	= mkdir -p $(@D)

#-UTILS-#

CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror -Wunreachable-code -g
NAME 			= cub3D
RM 				= rm -f
RMR				= rm -rf

#-RULES-#

all:			$(NAME)

$(LIBMLX_A):
				@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT_A) :
				@make -C $(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				$(D_OBJS)
				$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
				$(D_OBJS_BONUS)
				$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): 		$(OBJS) $(LIBFT_A) $(LIBMLX_A)
				@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LIBMLX_A) -ldl -lglfw -pthread -lm $(HEADERS) -o $(NAME)
				
clean:
				@$(RMR) $(OBJ_DIR)
				@$(RMR) $(OBJ_BONUS_DIR)
				@$(RMR) $(LIBMLX)/build
				@make -C $(LIBFT) clean

fclean: 		clean
				@$(RM) $(NAME)
				@$(RM) $(NAME_BONUS)
				@make -C $(LIBFT) fclean

re:				fclean all

bonus :			$(LIBFT_A) $(LIBMLX_A) $(OBJS_BONUS)
				@$(RM) $(NAME)
				@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_A)  $(LIBMLX_A) -ldl -lglfw -pthread -lm $(HEADERS) -o $(NAME)

.PHONY : 		all clean fclean re bonus