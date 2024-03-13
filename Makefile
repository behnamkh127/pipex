#Variables
NAME		:= pipex
SRC_DIR		:= src/
OBJ_DIR		:= obj/
CC			:= gcc
CFLAGS		 := -Wall -Werror -Wextra #-fsanitize=address -g
#FSANITIZE  := -fsanitize=address -g3
FSANITIZE   :=
NOFLAGS		:= -g
RM			:= rm -f
INC			:= inc/
LIB			:= lib/
PRINTF_DIR	:= $(LIB)ft_printf/
PRINTF		:= $(PRINTF_DIR)libftprintf.a
LIBFT_DIR	:= $(LIB)libft/
LIBFT		:= $(LIBFT_DIR)libft.a
HEADER		:= -I$(INC) -I$(PRINTF_DIR) -I$(LIBFT_DIR)
# Colors
DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
#Sources
SRC_FILES	=   main find_path do_fork init free
SRC			=   $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=   $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS        =   $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS        =   $(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
###
OBJF        =   .cache_exists
all:		makelibs
			@$(MAKE) $(NAME)
makelibs:
			@$(MAKE) -C $(PRINTF_DIR)
			@$(MAKE) -C $(LIBFT_DIR)
-include    ${DEPS}
$(NAME):    $(OBJ)
			@$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)
			@echo ":point_right: $(MAGENTA)$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(PRINTF) -o $(NAME)$(DEF_COLOR)"
			@echo "$(GREEN):hatching_chick: PIPEX compiled!$(DEF_COLOR)"
bonus:
			@$(MAKE) all
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) | $(OBJF)
				@echo ":fried_egg: $(CYAN)Compiling: $< $(DEF_COLOR)"
				$(CC) $(CFLAGS) -MMD -c $< -o $@
$(OBJF):
				@mkdir -p $(OBJ_DIR)
$(PRINTF):
			@make -C $(PRINTF_DIR)
			@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"
$(LIBFT):
			@make -C $(LIBFT_DIR)
clean:
			@make clean -sC $(PRINTF_DIR)
			@echo "$(CYAN)ft_printf object and dependency files cleaned.$(DEF_COLOR)"
			@make clean -sC $(LIBFT_DIR)
			@echo "$(CYAN)libft object and dependency files cleaned.$(DEF_COLOR)"
			$(RM) -rf $(OBJ_DIR)
			@echo "$(CYAN)PIPEX object files cleaned!$(DEF_COLOR)"
fclean:	 	clean
			$(RM) -f $(NAME)
			@echo "$(CYAN)PIPEX executable files cleaned!$(DEF_COLOR)"
			$(RM) -f $(PRINTF_DIR)libftprintf.a
			@echo "$(CYAN)libftprintf.a lib cleaned!$(DEF_COLOR)"
			$(RM) -f $(LIBFT_DIR)libft.a
			@echo "$(CYAN)libft.a lib cleaned!$(DEF_COLOR)"
re:			fclean
			@$(MAKE)
			@echo "$(GREEN)Cleaned and rebuilt everything for PIPEX!$(DEF_COLOR)"

.PHONY:     all clean fclean re
