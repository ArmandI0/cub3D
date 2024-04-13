# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aranger <aranger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 17:54:43 by nledent           #+#    #+#              #
#    Updated: 2024/04/13 19:20:38 by aranger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

SRCS			= 	\
					map_parsing/parsing.c \
					map_parsing/extract_textures_path.c \
					map_parsing/extract_colors_data.c \
					map_parsing/extract_file.c \
					map_parsing/extract_map.c \
					map_parsing/rgb_to_int.c \
					map_parsing/map_to_tab.c \
					map_parsing/check_walls.c \
					raycasting/raycasting.c \
					utils/check_args.c \
					utils/print_errors.c \
					utils/free_functions.c \
					utils/colors.c \
					utils/utils.c \
					utils/utils_lst.c \
					main.c \
					fct_hook.c \
					REPLACE_parsing.c \
					print_map/draw_minimap.c \
					print_map/utils.c \
					print_map/minimap_player.c \
					command/keyboard.c \
					raycasting/init_player.c \
					command/mouse.c \
					command/command.c \
					utils/exit_fct.c \
					command/move_player.c \
				
SRC				= $(addprefix src/, $(SRCS))
OBJS			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
D_OBJS			= mkdir -p $(@D)

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