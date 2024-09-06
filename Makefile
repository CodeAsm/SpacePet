# Compiler
CXX = g++

# Directories
SRC_DIR = .
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = .

# Libraries
LIBS = -L$(LIB_DIR) #-lmylib # Replace mylib with actual libraries

# Compiler flags
CXXFLAGS = -Wall -I$(LIB_DIR) # -I for any custom include paths

# Source and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Target executable
TARGET = $(BIN_DIR)/spacepet

# Default rule
all: $(TARGET)

# Rule to link the final executable
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) -o $@ $^ $(LIBS)

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up object files and binaries
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

# Phony targets
.PHONY: all clean
