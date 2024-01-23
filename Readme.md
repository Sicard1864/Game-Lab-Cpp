Arthur SICARD

# Compilation avec SDL2
g++ myProgram.cpp -o myProgram `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

# Compilation simple





find / -name "libSDL2.*" 2>/dev/null

# Makefile

# ... Autres sections du Makefile ...

# Chemin vers les fichiers d'en-tête SDL2
INC_SDL_PATH = -I./lib/SDL2/include

# Chemin vers la bibliothèque SDL2
LIB_SDL_PATH = -L./lib/SDL2/lib -lSDL2

# Flags for compilation
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror $(INC_SDL_PATH)

# Flags for linking
LDFLAGS = $(LIB_SDL_PATH)

# ... Autres sections du Makefile ...


changer la structure du projet
