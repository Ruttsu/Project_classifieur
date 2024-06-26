CXX = g++
CXXFLAGS = -Wall -std=c++17
INC_DIR = include
SRC_DIR = src
OBJ_DIR = build/objs

# Récupère la liste des fichiers .cpp dans le dossier src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Génère la liste des fichiers .o dans le dossier build/objs
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Exe final
EXECUTABLE = myprogram

all: $(OBJ_DIR) $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c -o $@ $<

#pour windows, remove le subst si linux
$(OBJ_DIR):
	mkdir $(subst /,\,$(OBJ_DIR)) 

# Clean fonctionnel uniquement sur windows env
clean:
	-del $(subst /,\,$(OBJ_DIR)\*.o)
	-del $(EXECUTABLE).exe