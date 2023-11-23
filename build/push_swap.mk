# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 13:33:38 by ldulling          #+#    #+#              #
#    Updated: 2023/11/18 16:37:13 by ldulling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ****************************** PREPARATION ********************************* #

# Gets this file's name (without suffix) for automatic variable creation later.
FILENAME	:=	$(basename $(notdir $(lastword $(MAKEFILE_LIST))))

# Resets TMP to get rid of any old values from other .mk files.
TMP			:=

# ***************************** CONFIGURATION ******************************** #

# Dependencies - has to be the basename of the corresponding .mk file:
DEPS	:=

# Directory of source files in src/ directory:
DIR		:=	./

# Source files:
#  Main:
SUBDIR	:=	./
TMP		+=	$(addprefix $(DIR)$(SUBDIR), \
			00_push_swap.c \
)

#  Algorithm:
SUBDIR	:=	algorithm/
TMP		+=	$(addprefix $(DIR)$(SUBDIR), \
			sort_block_bottom_a.c \
			sort_block_bottom_b.c \
			sort_block_initial_top_a.c \
			sort_block_top_a.c \
			sort_block_top_b.c \
			sort_rest_bottom_a.c \
			sort_rest_bottom_b.c \
			sort_rest_top_a.c \
			sort_rest_top_b.c \
)

#  Checks:
SUBDIR	:=	checks/
TMP		+=	$(addprefix $(DIR)$(SUBDIR), \
			01_parsing.c \
			02_bigger_than_integer.c \
			check_duplicates.c \
)

#  LIFO:
SUBDIR	:=	lifo/
TMP		+=	$(addprefix $(DIR)$(SUBDIR), \
			lifo_lstadd_front.c \
			lifo_lstclear.c \
			lifo_lstclear_n.c \
			lifo_lstnew.c \
)

#  Operations:
SUBDIR	:=	operations/
TMP		+=	$(addprefix $(DIR)$(SUBDIR), \
			push.c \
			reverse_rotate.c \
			rotate.c \
			swap.c \
)

#  Utils:
SUBDIR	:=	utils/
TMP		+=	$(addprefix $(DIR)$(SUBDIR), \
			find_pos_sorted.c \
			function_pointers.c \
			is_n_amount_sorted.c \
			protocol.c \
)

# *************************** VARIABLE CREATION ****************************** #

# Creates a final SRC variable and assigns all the source files specified above.
$(eval SRC_$(FILENAME)		:=	$(TMP))

# Creates an OBJ variable for the dependency rule below.
$(eval OBJ_$(FILENAME)		:=	$(SRC_$(FILENAME):%.c=$O%.o))

# Makes this file's object files dependent on any DEPS specified above.
$(OBJ_$(FILENAME)):	$O%.o	:	$(foreach dep,$(DEPS),$(OBJ_$(dep)))

# *************************** MAKEFILE DEBUGGING ***************************** #

# Prints the values of the variable given after the minus.
print-%			:
	@				echo $* = $($*)