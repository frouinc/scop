# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 15:07:13 by cyrillef          #+#    #+#              #
#    Updated: 2018/01/19 16:53:34 by cyrillefrouin    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC					=	gcc

NAME				=	scop

SRCS_DIR			=	srcs/

SRCS				=	main.c \
						read_file.c

SRCS_FULL			=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS				=	$(SRCS_FULL:.c=.o)

CFLAGS				=	-Wall -Wextra -I./includes/ -I/usr/local/include/GLFW -I/usr/local/include

all:				$(NAME)

run:				$(NAME)
					./$(NAME)

%.o : %.c
					@gcc -g -o $@ -c $< $(CFLAGS)
					@echo "\033[K\033[34mScop :\033[0m [ Compiling :\033[33m $^\033[0m]\033[1A"

$(NAME):			$(OBJS)
					@$(GCC) $(OBJS) -o $(NAME) -lglfw -framework AppKit -framework OpenGL
					@echo "\033[K\033[32m=============SCOP================\033[0m"
					@echo "\033[34mCompiling\033[0m" [ $(NAME) ] "\033[K\033[32mSuccessful\033[00m"
					@echo "\033[32m=================================\033[00m"

clean:
					@rm -f $(OBJS)
					@echo "\033[K\033[31m=============SCOP=============\033[0m"
					@echo "\033[31mCleaning\033[00m  " [ "*.o" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m==============================\033[0m"

fclean:				clean
					@rm -f $(NAME)
					@echo "\033[K\033[31m=============SCOP=============\033[0m"
					@echo "\033[31mRemoving\033[00m  " [ "scop" ] "  \033[32mComplete\033[00m"
					@echo "\033[K\033[31m==============================\033[0m"

re:					fclean all

.PHONY:				all clean fclean re
