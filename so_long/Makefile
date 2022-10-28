SRC = src/main.c \
		src/init.c \
		src/map_constraction.c \
		src/map_validation.c \
		src/utils.c \
		src/draw.c \
		src/pathfind.c \
		src/exit.c

OBJ = obj/*.o

NAME = so_long

ARG = maps/map4.ber

LIB = bin/minilibx_opengl_20191021
PRINTF = ./libs/ft_printf/libftprintf.a

FRAMEWORKS = -framework AppKit -framework OpenGL

INC = inc

all: $(NAME)

$(NAME): $(OBJDIR) $(LIB) $(PRINTF) $(OBJ)
	make -C $(LIB)
	gcc -o $(NAME) $(OBJ) $(FRAMEWORKS) $(LIB)/libmlx.a $(PRINTF) -g

$(OBJDIR):
	mkdir -p ./obj

$(PRINTF):
	make -C ./libs/ft_printf

$(OBJ): $(SRC)
	mkdir -p ./obj
	gcc -c $^ -I $(INC)
	mv *.o ./obj/

run: all
	./$(NAME) $(ARG)

clean:
	rm -rf obj/*.o

fclean: clean
	rm -rf $(NAME)
	make clean -C bin/minilibx_opengl_20191021

re: fclean all

.PHONY: all clean fclean re