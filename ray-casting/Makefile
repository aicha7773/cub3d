NAME = cub3D

SRC = first_file.c the_movement.c display.c raycasting.c angle_ranges.c \
	casting_utils.c keys_state.c trigonometric_form.c maths_utils.c main_ray.c

OBJ = ${SRC :%.c=%.o}

CC = clang

MLX =-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CFLAGS = -I/usr/include -Imlx_linux -O3 -fsanitize=address -g3 #-Wall -Wextra -Werror 

all : ${NAME}

${NAME} : ${OBJ} ${SRC}
	${CC} ${CFLAGS} ${MLX} ${SRC} ${MLX} ${OBJ} -o ${NAME}

clean :
	rm -f ${OBG}

fclean : clean
	rm -f ${NAME}
make re : fclean all

push :
	git add . && git commit -m "push" && git push