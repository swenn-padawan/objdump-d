#@Makefile######################################################################

#@Variables#####################################################################

NAME		:=	objdump-d

CC			:=	clang
CFLAGS		:=	-Wall -Wextra -Werror -MMD -MP

VERBOSE		?=	0
ifeq ($(VERBOSE), 1)
	CFLAGS	+=	-DVERBOSE
endif

LAZY		?= 	0
ifeq ($(LAZY), 1)
	CFLAGS	:=	-g -O0
endif

include 	sources.mk

INC_DIR		:=	include
IFLAGS		:=	-I$(INC_DIR)

SRC_DIR		:=	src
SRCS		:=	$(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR		:=	.build
OBJS		:=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

MAKEFLAGS	+=	--no-print-directory

RM			:=	rm -rf

DIR_UP		=	mkdir -p $(@D)

#@Rules#########################################################################

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@printf " $(GREEN)$(BOLD)$(ITALIC)■$(RESET)  building	$(GREEN)$(BOLD)$(ITALIC)$(NAME)$(RESET)\n"

$(OBJ_DIR)/%.o: %.c
	@$(DIR_UP)
	@printf " $(GRAY)$(BOLD)$(ITALIC)■$(RESET)  compiling	$(GRAY)$(BOLD)$(ITALIC)$^$(RESET)\n"
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ_DIR)
	@printf " $(RED)$(BOLD)$(ITALIC)■$(RESET)  deleting	$(RED)$(BOLD)$(ITALIC)$(OBJ_DIR)$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf " $(RED)$(BOLD)$(ITALIC)■$(RESET)  deleting	$(RED)$(BOLD)$(ITALIC)$(NAME)$(RESET)\n"

re: fclean all

-include	$(OBJS:.o=.d)

#@Colors#########################################################################

BLACK		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
GRAY		=	\033[90m

BOLD		=	\033[1m
ITALIC		=	\033[3m

RESET		=	\033[0m
LINE_CLR	=	\33[2K\r

################################################################################
