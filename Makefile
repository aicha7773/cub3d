NAME = cub3D

SRC = first_file.c

OBG = ${SRC %.c=%.o}

CC = cc

MLX = -lmlx -framework OpenGL -framework AppKit

CFLAGS = #-Wall -Wextra -Werror 

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${MLX} ${SRC} -o ${NAME}

clean :
	rm -f ${OBG}

fclean : clean
	rm -f ${NAME}
make re : fclean all

push :
	git add . && git commit -m "push" && git push