# Makefile

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Directories
SRC_DIR = .
LIB_DIR = lib
OBJ_DIR = obj

# Sources and objects
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/pet.cpp $(LIB_DIR)/clock.cpp
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o) $(SOURCES:$(LIB_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Target executable
TARGET = spacepet

# Build rules
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and binaries
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Phony targets
.PHONY: all clean
