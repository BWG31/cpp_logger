NAME	=	liblogger.a

SRC		=	LogEntry ErrorLogEntry Logger LogManager \
			Font Printer

INC_DIR		:=	inc/
SRC_DIR		:=	src/
OBJ_DIR		:=	obj/
DEP_DIR 	:=	dep/

CC			:=	g++
CFLAGS		:=	-Wall -Wextra -Werror
DFLAGS		:=	-MMD -MF
DEP_FILE	=	$(DEP_DIR)$*.d
RM			:=	rm -rf
AR			:=	ar -rc

SRCS	:=	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC)))
OBJS	:=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))
DEPS	:=	$(addprefix $(DEP_DIR), $(addsuffix .d, $(SRC)))

INCLUDES	=	-I $(INC_DIR)

RESET		=	\033[0m
GREEN		=	\033[32m

MAKEFLAGS	:=	--no-print-directory

all:			$(NAME)

-include $(DEPS)

$(NAME):		$(OBJS)
				$(AR) $@ $(OBJS)
				@printf "Created archive: $(GREEN)$(NAME)$(RESET)\n"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp | $(DEP_DIR) $(OBJ_DIR)
				$(CC) $(CFLAGS) $(DFLAGS) $(DEP_FILE) $(INCLUDES) -c $< -o $@

$(DEP_DIR) $(OBJ_DIR):
				@mkdir -p $@

clean:
				$(RM) $(OBJ_DIR) $(DEP_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean
				@$(MAKE) all

debug:			clean
				@$(MAKE) CFLAGS="$(CFLAGS) -g" all

.PHONY: all clean fclean re debug
