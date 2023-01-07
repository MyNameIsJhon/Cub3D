CC =gcc
CFLAGS =-I/usr/include -Imlx_linux -O3 
LDFLAGS =-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
EXEC =Cub3D

INCLUDES = -I ./Libft -I ./List -I ./Basic_graph -I ./Events

SRC = ./Libft/libft.c \
		./List/list.c \
		./ft_printf/ft_printf.c \
		./Basic_graph/minilib_colors.c \
		./Basic_graph/minilib_draw.c \
		./Events/mlx_events.c \
		./Cub3D.c
HEADS = ./Libft/libft.h \
		./List/list.h \
		./Basic_graph/mlx_graph.h \
		./Events/mlx_events.h
OBJ = $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : $(OBJ) 
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC) 

$(OBJ) : $(HEADS)

%.o :%.c  $(HEADS)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<
	

.PHONY : clean mrproper

clean : 
	rm -rf $(OBJ)

mrproper : clean
	rm -rf $(EXEC)

