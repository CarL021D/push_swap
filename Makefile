# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caboudar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 20:02:33 by caboudar          #+#    #+#              #
#    Updated: 2022/09/26 20:02:37 by caboudar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;91m
GREEN=\033[0;32m
RESET=\033[0m

# ################################## #
#               COMMAND              #
# ################################## #
CC			= gcc
MKDIR		= mkdir -p
RM			= rm -rf

# ################################## #
#              EXEC NAME             #
# ################################## #
NAME		= push_swap

# ################################## #
#               SOURCES              #
# ################################## #
C_DIR		= srcs
C_FILES		=	push_swap.c \
				check_args.c \
				create_stack.c \
				ft_free.c \
				init_data_struct.c \
				init_stack.c init_stack_values.c \
				instructions.c \
				push_swap_utils.c \
				set_node_cost.c \
				sort_2_and_3.c \
				sort_4_and_above.c \
				sort_4_and_above_utils_2.c \
				sort_4_and_above_utils.c

SRCS		= $(patsubst %, $(C_DIR)/%, $(C_FILES))

# ################################## #
#               OBJECTS              #
# ################################## #
O_DIR		= objs
O_FILES		= $(C_FILES:.c=.o)
OBJS		= $(patsubst %, $(O_DIR)/%, $(O_FILES))

# ################################## #
#                FLAGS               #
# ################################## #
CFLAGS		= -Wall -Wextra -Werror -g

CINCLUDES	= -I ./inc \

# ################################## #
#                RULES               #
# ################################## #

all:		$(NAME)

$(NAME):	$(O_DIR) $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $@
			@echo "${GREEN}- compiling push_swap executable${RESET}"

$(O_DIR)/%.o: $(C_DIR)/%.c
			@$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

$(O_DIR):
			@$(MKDIR) $(O_DIR)
			@echo "${GREEN}- creating push_swap objects directory${RESET}"

# ################################## #
#                CLEAN               #
# ################################## #

clean:
			@$(RM) $(O_DIR)
			@echo "${RED}- deleting push_swap objects${RESET}"

fclean:		clean
			@$(RM) $(NAME)
			@echo "${RED}- delete push_swap executable${RESET}"

re:			fclean all

.PHONY: all check clean fclean re
