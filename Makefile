#/* ************************************************************************** */
#/*                                                                            */
#/*                                                        :::      ::::::::   */
#/*   Makefile                                           :+:      :+:    :+:   */
#/*                                                    +:+ +:+         +:+     */
#/*   By: big <rafade-o@student.42.rio>              +#+  +:+       +#+        */
#/*                                                +#+#+#+#+#+   +#+           */
#/*   Created: 2022/10/23 21:07:56 by big               #+#    #+#             */
#/*   Updated: 2022/10/23 17:48:02 by big              ###   ########.fr       */
#/*                                                                            */
#/* ************************************************************************** */

SRCS			= 	./sources/fractol.c 							\
					./sources/drawing/draw_scene.c 					\
					./sources/interaction/keyboard.c 				\
					./sources/interaction/mouse.c 					\
					./sources/helpers/create_img.c 					\
					./sources/helpers/calculate_color_trgb.c		\
					./sources/helpers/mlx_pixel_put.c				\
					./sources/helpers/complex_calc.c				\
					./sources/helpers/validate_args.c				

#Detection OS to select Library
OS			= $(shell uname)

# MiniLibX
ifeq ($(OS), Linux)
	MLX			= ./includes/mlx_linux
	MLX_MAKE	= cd ./includes/mlx_linux/ && make
	MINI		= ./includes/mlx_linux/libmlx.a
	MLX_FLAGS	= -L $(MLX) -l mlx -lXext -lX11
	EXPORT		= $(shell cp ./includes/mlx_linux/mlx.h ./includes/)
else
	MLX			= ./includes/mlx_mac
	MLX_MAKE	= cd ./includes/mlx_mac/ && make
	MINI		= ./includes/mlx_mac/libmlx.a
	MLX_FLAGS	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit
	EXPORT		= $(shell cp ./includes/mlx_mac/mlx.h ./includes/)
endif

# libft
LIBFT		=	cd ./includes/libft && make
LIB		=	./includes/libft/libft.a

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

FLAGS		=	-Wall -Wextra -g

INCLUDE		=	-I include

NAME		=	fractol

all:	libft mlx $(NAME)
	
libft:
	@$(LIBFT)

mlx:
	@$(MLX) $(EXPORT)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(MINI) $(MLX_FLAGS)  -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@cd ./includes/libft && make clean
	@$(MLX) && make clean
	@rm  ./includes/mlx.h

fclean: clean
	@rm -rf $(NAME)
	@cd ./includes/libft && make fclean

re:	fclean all

.PHONY: all libft fractol mlx clean fclean re
