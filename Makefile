# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafade-o <rafade-o@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 17:23:26 by rafade-o          #+#    #+#              #
#    Updated: 2023/01/09 17:23:29 by rafade-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 	./sources/fractol.c 									\
					./sources/drawing/draw_scene.c 							\
					./sources/drawing/fractols/julia.c						\
					./sources/drawing/fractols/mandelbrot.c					\
					./sources/drawing/fractols/burning_ship.c				\
					./sources/interaction/keyboard.c 						\
					./sources/interaction/mouse.c 							\
					./sources/helpers/helpers_mlx/create_img.c 				\
					./sources/helpers/helpers_mlx/calculate_color_trgb.c	\
					./sources/helpers/helpers_mlx/calculate_raw_color.c		\
					./sources/helpers/helpers_mlx/mlx_pixel_put.c			\
					./sources/helpers/validate_args.c						\
					./sources/helpers/help_information.c					\
					./sources/helpers/initialize_abstract_types.c			\
					./sources/helpers/parse_functions.c						\
					./sources/helpers/get_fractol.c


#Detection OS to select Library
OS					= $(shell uname)

# MiniLibX
ifeq ($(OS), Linux)
	MLX				= ./includes/mlx_linux
	MLX_MAKE		= cd ./includes/mlx_linux/ && make
	MINI			= ./includes/mlx_linux/libmlx.a
	MLX_FLAGS		= -L $(MLX) -l mlx -lXext -lX11
	CLEAN_FOLDER 	= mlx_linux
	EXPORT_MLX		= $(shell cp ./includes/mlx_linux/mlx.h ./includes/)
	EXPORT_KEYS		= $(shell cp ./includes/mlx_linux/keys.h ./includes/)
else
	MLX				= ./includes/mlx_mac
	MLX_MAKE		= cd ./includes/mlx_mac/ && make
	MINI			= ./includes/mlx_mac/libmlx.a
	MLX_FLAGS		= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
	CLEAN_FOLDER 	= mlx_mac
	EXPORT_MLX		= $(shell cp ./includes/mlx_mac/mlx.h ./includes/)
	EXPORT_KEYS		= $(shell cp ./includes/mlx_mac/keys.h ./includes/)
endif

# libft
LIBFT				=	cd ./includes/libft && make
LIB					=	./includes/libft/libft.a
OBJS				=	$(SRCS:.c=.o)
CC					=	gcc
FLAGS				=	-Wall -Wextra -g 
INCLUDE				=	-I include
NAME				=	fractol

all:	libft mlx $(NAME)
	
libft:
	@$(LIBFT)

mlx:
	@$(MLX_MAKE) $(EXPORT_MLX) $(EXPORT_KEYS)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIB) $(MINI) $(MLX_FLAGS)  -o $(NAME) -lm

clean:
	@rm -rf $(OBJS)
	@cd ./includes/libft && make clean
	@cd ./includes/$(CLEAN_FOLDER) && make clean

fclean: clean
	@rm -rf $(NAME)
	@cd ./includes/libft && make fclean
	$(shell if [ -f ./includes/mlx.h ];	 then	rm  ./includes/mlx.h;	fi)
	$(shell if [ -f ./includes/keys.h ]; then	rm  ./includes/keys.h;	fi)	

re:	fclean all

.PHONY: all libft fractol mlx clean fclean re
