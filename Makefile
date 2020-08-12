# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 14:56:19 by julnolle          #+#    #+#              #
#    Updated: 2020/08/12 10:59:52 by julnolle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libasm.a
EXEC	= libasm
# ---------------- CC ---------------- #

CC	= clang
ASM	= nasm

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	NFLASG	 	= -f elf64
else
	NFLASG	 	= -f macho64
endif

# ---------------- SRC --------------- #

# Main Sources
MAIN += main.c

# ASM Sources
SRCS += ft_strlen.s
SRCS += ft_write.s
SRCS += ft_read.s
SRCS += ft_strcpy.s
SRCS += ft_strcmp.s
SRCS += ft_strdup.s

# vpath %.c ./
# vpath %.s ./

# ---------------- INC --------------- #

INCLUDES 	=	./
HEAD 		= $(INCLUDES)libasm.h

# ---------------- OBJ --------------- #

DIR_OBJS	= ./objs/
OBJS		= $(patsubst %.s, $(DIR_OBJS)%.o, $(SRCS))

# --------- Compilation Rules -------- #

all: $(NAME)

# nasm -f elf64 ft_strlen.s
# gcc ft_strlen.o main.c -L./ -lasm

$(NAME):	$(OBJS) $(MAIN)
			ar rcs $@ $^
			$(CC) -g $^ -L./ -lasm -o $(EXEC)

$(OBJS): 	$(DIR_OBJS)%.o: %.s $(HEAD) Makefile | $(DIR_OBJS)
			$(ASM) $(NFLASG) $< -o $@

$(DIR_OBJS):
	mkdir -p $@

clean:
	$(RM) -R $(DIR_OBJS)
	@echo "$(_BOLD)$(_RED)-> $@ made$(_END)"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(EXEC)
	@echo "$(_BOLD)$(_RED)-> $@ made$(_END)"

re: fclean
	$(MAKE)

.PHONY:		all exec clean fclean re bonus
# .SILENT:	$(OBJS) $(DIR_OBJS) $(NAME) $(LIBFT) compmlx
