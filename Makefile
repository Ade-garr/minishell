# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-garr <ade-garr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 10:29:31 by user42            #+#    #+#              #
#    Updated: 2021/03/29 10:50:52 by ade-garr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS += ./srcs/main.c
SRCS += ./srcs/ft_lstadd_back.c
SRCS += ./srcs/ft_lstlast.c
SRCS += ./srcs/ft_lstnew.c
SRCS += ./srcs/ft_lstclear.c
SRCS += ./srcs/ft_lstsize.c
SRCS += ./srcs/get_next_line.c
SRCS += ./srcs/get_next_line_utils.c
SRCS += ./srcs/execute.c
SRCS += ./srcs/utils.c
SRCS += ./srcs/utils2.c
SRCS += ./srcs/redirections.c
SRCS += ./srcs/terminal.c
SRCS += ./srcs/ft_isprint.c
SRCS += ./srcs/readline.c
SRCS += ./srcs/readline2.c
SRCS += ./srcs/readline3.c
SRCS += ./srcs/ft_strlen.c
SRCS += ./srcs/ft_strdup.c

OBJS	= ${SRCS:.c=.o}

NAME	= minishell

INCLUDES = ./includes/

CC		= clang

CFLAGS	+= -Wall
CFLAGS	+= -Wextra
CFLAGS	+= -Werror

HEADER = ${INCLUDES}minishell.h

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -I ${INCLUDES} ${OBJS} -o ${NAME} -lncurses
			printf "\033[32m$@ is ready ! \n\033[0m"

${OBJS}: %.o: %.c ${HEADER}
			${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@
			
clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
.SILENT: