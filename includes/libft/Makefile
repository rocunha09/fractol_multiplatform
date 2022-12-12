# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: big <rafade-o@student.42.rio>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 01:43:11 by big               #+#    #+#              #
#    Updated: 2022/06/11 15:16:30 by rafade-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#	libft	&&  ft_printf	&& get_next_line	#
SRCS	=	ft_isalpha.c		ft_isdigit.c			ft_isalnum.c    	\
			ft_isascii.c		ft_isprint.c			ft_toupper.c    	\
			ft_tolower.c		ft_atoi.c				ft_strncmp.c    	\
			ft_bzero.c			ft_memset.c				ft_memcpy.c     	\
			ft_memmove.c		ft_memchr.c				ft_calloc.c     	\
			ft_strchr.c			ft_strrchr.c			ft_strnstr.c    	\
			ft_strdup.c			ft_strlen.c				ft_strlcat.c    	\
			ft_strlcpy.c		ft_striteri.c			ft_putchar_fd.c 	\
			ft_putstr_fd.c		ft_putendl_fd.c			ft_putnbr_fd.c  	\
			ft_substr.c			ft_strjoin.c			ft_strtrim.c   		\
			ft_split.c			ft_itoa.c				ft_strmapi.c    	\
			ft_memcmp.c														\
			ft_lstnew.c			ft_lstadd_front.c		ft_lstsize.c   		\
			ft_lstlast.c 		ft_lstadd_back.c 		ft_lstdelone.c  	\
			ft_lstclear.c								   					\
			ft_printf.c			ft_put_hex.c			ft_put_number.c		\
			ft_put_pointer.c	ft_put_toupper_hex.c	ft_put_u_number.c	\
			ft_ul_number_len.c	ft_ul_parse_to_hexa.c	ft_print_char.c		\
			ft_print_str.c													\
			get_next_line.c													\

OBJS	= $(SRCS:.c=.o)

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror 

NAME	= libft.a

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
