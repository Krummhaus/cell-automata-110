CC = clang
CFLAGS=-Wall -Wextra
GL_PKGS= glfw3 glew

all: cell viz

cell: main.c 
	$(CC) $(CFLAGS) -o cell main.c

viz: vizual.c 
	$(CC) $(CFLAGS) `pkg-config --cflags $(GL_PKGS)`-o vizual vizual.c `pkg-config --libs $(GL_PKGS)`
# old:  $(CC) $(CFLAGS) -o vizual vizual.c -lglfw

# Uses the 'pkg-config' tool to automatically retrieve the necessary compiler flags
# (--cflags) and linker flags (--libs) for the specified libraries.

# Instead of manually specifying the (-lglfw) flag, the new Makefile uses pkg-config
# to automatically fetch the necessary flags for both the compiler and linker for
# the libraries glfw3 and glew.
