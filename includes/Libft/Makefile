# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbras <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 17:17:43 by tbras             #+#    #+#              #
#    Updated: 2023/12/20 17:17:44 by tbras            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MY_SOURCES = ft_atoi.c ft_isalpha.c ft_memchr.c \
            ft_memset.c ft_strlcpy.c ft_strrchr.c \
            ft_bzero.c ft_isascii.c ft_memcmp.c \
            ft_strchr.c ft_strlen.c ft_tolower.c \
            ft_calloc.c ft_isdigit.c ft_memcpy.c \
            ft_strdup.c ft_strncmp.c ft_toupper.c \
            ft_isalnum.c ft_isprint.c ft_memmove.c \
            ft_strlcat.c ft_strnstr.c ft_putchar_fd.c \
            ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
            ft_substr.c ft_strjoin.c ft_itoa.c \
            ft_strtrim.c ft_split.c ft_strmapi.c \
            ft_striteri.c get_next_line.c get_next_line_utils.c \

SOURCES_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
                ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
                ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

HEADER = 	libft.h \
			get_next_line.h \

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	@ar -rcs $(NAME) $(MY_OBJECTS)

bonus: all $(OBJECTS_BONUS)
	@ar -rcs $(NAME) $(OBJECTS_BONUS)

clean: 
	rm -f $(MY_OBJECTS)

fclean: 
	rm -f $(NAME) $(MY_OBJECTS) $(OBJECTS_BONUS)

re: fclean all

.PHONY: fclean clean all re
