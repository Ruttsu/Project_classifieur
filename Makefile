CXX = g++
CXXFLAGS = -Wall -std=c++11
INC_DIR = include
SRC_DIR = src
OBJ_DIR = build/objs

# Récupère la liste des fichiers .cpp dans le dossier src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Génère la liste des fichiers .o dans le dossier build/objs
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Exécutable final
EXECUTABLE = myprogram

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c -o $@ $<

clean:
	-del $(subst /,\,$(OBJ_DIR)\*.o)
	-del $(EXECUTABLE).exe

