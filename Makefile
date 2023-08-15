NAME = cub3D

SRC = first_file.c

OBJ = ${SRC :%.c=%.o}

CC = clang

MLX =-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CFLAGS = -I/usr/include -Imlx_linux -O3 #-Wall -Wextra -Werror 

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