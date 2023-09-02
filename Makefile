NAME	=	cub3d
SRCS	=	\
			./parsing/get_next_line.c ./parsing/get_next_line_utils.c ./parsing/main.c ./parsing/map.c ./parsing/direction.c ./parsing/cub_utils.c ./parsing/cub_utils2.c ./parsing/parse_helper.c ./parsing/cub_map.c ./parsing/c_f.c\
			
OBJS	=	$(SRCS:.c=.o)


SRC = ./ray-casting/first_file.c ./ray-casting/the_movement.c ./ray-casting/display.c ./ray-casting/raycasting.c ./ray-casting/angle_ranges.c \
	./ray-casting/casting_utils.c ./ray-casting/keys_state.c ./ray-casting/trigonometric_form.c ./ray-casting/maths_utils.c

MLX =-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CFLAGS = -I/usr/include -Imlx_linux -O3 -fsanitize=address -g3 #-Wall -Wextra -Werror 

OBJ = ${SRC :%.c=%.o}

CC		=	clang

AR 		= ar rc


# LINKS = \
#     -I /usr/local/include -L /usr/local/lib \
#      -lmlx -framework OpenGL -framework AppKit


LIBFT = ./parsing/libft/libft.a

NONE	=	'\033[0m'
GREEN	=	'\033[32m'
RED		=	'\033[1;91m'
GRAY	=	'\033[2;37m'
ITALIC	=	'\033[3m'

.c.o	:
			@echo $(ITALIC)$(GRAY) "    Compiling $<" $(NONE)
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all		:	$(NAME)

$(NAME)	: 	 $(LIBFT) $(OBJS) $(OBJ)
			@echo $(GREEN) "Compiling $(NAME)..." $(NONE)
			@$(CC) $(CFLAGS) $(OBJS) ./parsing/libft/libft.a ${MLX} ${SRC} ${MLX} ${OBJ} -o $(NAME)
			@echo $(GREEN) "\n ~ Compiled !!" $(NONE)

#$(LIBFT) :
#			@echo $(GREEN) "Compiling libft..." $(NONE)
#			@make -C libft/

clean	:
#			@echo $(RED) "Removing libft..." $(NONE)
#			@make clean -C libft/
			@echo $(RED) "Removing object files..." $(NONE)
			@rm -rf $(OBJS) $(OBJ)

fclean	:	clean
			@echo $(RED) "Removing $(NAME)..." $(NONE)
			@rm -f $(NAME) $(NAME)

re		:	fclean $(NAME)
