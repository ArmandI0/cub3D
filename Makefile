# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aranger <aranger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/31 17:54:43 by nledent           #+#    #+#              #
#    Updated: 2024/04/09 14:02:34 by aranger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-PATH FILES-#

SRC_DIR			= src
OBJ_DIR			= obj

#-LIBFT-#

LIBFT			= lib/libft
LIBFT_A			= lib/libft/libft.a

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
					game/main.c \
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
					manage_player/minimap_player.c \
					command/key_hook.c \

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

$(LIBFT_A) :
				@make -C $(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				$(D_OBJS)
				$(CC) $(CFLAGS)  -c -o $@ $< 

$(NAME): 		$(OBJS)  $(LIBFT_A) 
				@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME) -lreadline

clean:
				@$(RMR) $(OBJ_DIR)
				@make -C $(LIBFT) clean

fclean: 		clean
				@$(RM) $(NAME)
				@make -C $(LIBFT) fclean

re:				fclean all

.PHONY : 		all clean fclean re