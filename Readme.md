## ToDo List

### Développer la branche :
Gameplay
- movement avancer
- collition
- carte de jeu
- test

Réseaux
- coop
- serveur client lan

- menu
- menu pause
- ennemis et système d'entité
- barre de vie

## Makefile

Ce Makefile propose plusieurs cibles pour simplifier le processus de compilation, de test et d'exécution du programme.

### Cibles principales

#### `default`
La cible par défaut est `default`. En utilisant simplement la commande `make`, cette cible sera exécutée. Elle déclenche les cibles `c` (pour compiler) et `run` (pour exécuter).

#### `all`
La cible `all` nettoie le répertoire de construction, compile tous les fichiers nécessaires avec `c_all`, puis exécute le programme avec `run_all`.

#### `c_all`
Compile les fichiers sources nécessaires pour le programme principal et les tests.

#### `c`
Compile les fichiers sources nécessaires pour le programme principal.

#### `c_test`
Compile les fichiers sources nécessaires pour les tests.

#### `run_all`
Exécute le programme principal et les tests avec `run` et `run_test` respectivement.

#### `run`
Exécute le programme principal.

#### `run_test`
Exécute les tests.

#### `clean`
Supprime tous les fichiers objets générés lors de la compilation et les fichiers binaires.

#### `clean_build`
Supprime seulement les fichiers objets générés lors de la compilation, laissant les fichiers binaires intacts.



##### Chemin vers les fichiers d'en-tête SDL2

INC_SDL_PATH = -I./lib/SDL2/include

##### Chemin vers la bibliothèque SDL2

LIB_SDL_PATH = -L./lib/SDL2/lib -lSDL2

##### Flags for compilation

CXXFLAGS = -std=c++17 -Wall -Wextra -Werror $(INC_SDL_PATH)

##### Flags for linking

LDFLAGS = $(LIB_SDL_PATH)
