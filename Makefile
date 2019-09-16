# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/19 19:52:14 by fsmith            #+#    #+#              #
#    Updated: 2019/07/28 15:59:53 by fsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			fractol

override G +=
SRC_PATH :=		src/
INC_PATH :=		includes/
LIB_PATH :=		libft/
MLX_PATH :=		minilibx/
OBJ_PATH :=		.obj/

CC :=			clang
CFLAGS :=		-g -Wall -Wextra -Werror
IFLAGS :=		-I $(INC_PATH) -I $(LIB_PATH)
LFLAGS :=		-lft -L $(LIB_PATH)
MLXFLAGS :=		-lmlx -framework OpenGL -framework AppKit

HFILES :=		fr_fractol
FILES :=		main fr_calculate fr_close fr_color_solid fr_colors\
				fr_evaluate fr_fractol fr_info fr_keyboard\
				fr_mouse fr_plot_image fr_read fr_threads

LIB :=			$(LIB_PATH)libft.a
MLX :=			$(MLX_PATH)libmlx.a

HDRS :=			$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS :=			$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS :=			$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS) $(MLX)
	@ $(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) -o $(NAME) $(MLX) $(MLXFLAGS)
$(LIB):
	@ $(MAKE) -C $(dir $@) $(notdir $@)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)
$(OBJ_PATH)%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: mclean
	make clean -C $(LIB_PATH)
fclean: mfclean
	make fclean -C $(LIB_PATH)
re: fclean all

mclean:
	rm -f $(OBJS) $(DEPS)
mfclean:
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)
mre: mfclean all

git:
	git add .
	git commit -am "$(G)"
	git push

.PHONY: $(LIB) all clean fclean re mclean mfclean mre
