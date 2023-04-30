################################################################################
#                                                                              #
#                                                                              #
#    Makefile                                              by CanTale_Games    #
#                                                                              #
#                                                                              #
################################################################################

CC		=		g++
FLAGS		=		-Wall -Wextra -Werror
LINKER_FLAGS	=		-L/usr/include/SDL2 -lSDL2 -lSDL2main -lSDL2_image

NAME		=		demo

SRC		=		main.cpp \
				Game/Game.cpp \
				Time/Time.cpp \
				Renderer/Renderer.cpp \
				Map/Map.cpp \
				Player/Player.cpp \
				Raycaster/Raycaster.cpp \
				Keys/Keys.cpp \
				Editor/Editor.cpp \
				Editor/Button/Button.cpp \
				Texture/Texture.cpp

OBJ		=		$(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))
OBJDIR		=		obj




all: $(NAME)
	@echo Raycasting Engine succesfully compiled!

$(NAME): $(OBJ)
	$(CC) $^ -o $@ $(LINKER_FLAGS)

$(OBJ) : $(OBJDIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) -g $(FLAGS) -c $< -o $(addprefix $(OBJDIR)/, $(<:.cpp=.o))

clean:
	rm -rf $(OBJDIR)

fclean:
	rm $(NAME)

kill: clean fclean


re: kill
	make

play:
	make
	./demo

.PHONY: all clean fclean kill re demo
