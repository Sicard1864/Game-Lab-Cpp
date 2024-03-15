# Makefile
CXX = g++

# Flags for compilation
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror `sdl2-config --cflags`

# Flags for linking
LDFLAGS = `sdl2-config --libs`

SRC_DIR = Src
TEST_DIR = Test
INCLUDE_DIR = Include
BUILD_DIR = Build
LIB_DIR = Lib
BIN_DIR = Bin

BUILD_DIR_SRC = $(BUILD_DIR)/Linux/$(SRC_DIR)
BUILD_DIR_TEST = $(BUILD_DIR)/Linux/$(TEST_DIR)

TARGET = $(BIN_DIR)/my_program
TEST_TARGET = $(BIN_DIR)/test_program

# Include and library paths
INC_SRC_PATHS = -I$(INCLUDE_DIR)/$(SRC_DIR)
INC_TEST_PATHS = -I$(INCLUDE_DIR)/$(TEST_DIR)
LIB_PATHS = $(LIB_PATHS)

# List of source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/**/*.cpp)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp) $(wildcard $(TEST_DIR)/**/*.cpp)

# List of object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR_SRC)/%.o, $(SRCS))
TEST_OBJS = $(filter-out $(BUILD_DIR_SRC)/main.o, $(OBJS)) $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR_TEST)/%.o, $(TEST_SRCS))


# Build main program
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Build test program
$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile source files
$(BUILD_DIR_SRC)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC_SRC_PATHS) -c -o $@ $<

# Compile test files
$(BUILD_DIR_TEST)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INC_SRC_PATHS) $(INC_TEST_PATHS) -c -o $@ $<
	
	
.DEFAULT_GOAL := default
.PHONY: c_all c c_test clean run_test run

default: c run

all: clean c_all run_all

def: clean c run

test: clean c_all run_test

run_all: run_test run

run: $(TARGET)
	@./$(TARGET)
	
run_test: $(TEST_TARGET)
	@./$(TEST_TARGET)

c_all: $(TARGET) $(TEST_TARGET)

c: $(TARGET)

c_test: $(TEST_TARGET)

clean:
	rm -rf $(BUILD_DIR_SRC)/**/*.o $(BUILD_DIR_SRC)/*.o $(BUILD_DIR_TEST)/**/*.o $(BUILD_DIR_TEST)/*.o $(BIN_DIR)/*
	
clean_build:
	rm -rf $(BUILD_DIR_SRC)/**/*.o $(BUILD_DIR_SRC)/*.o $(BUILD_DIR_TEST)/**/*.o $(BUILD_DIR_TEST)/*.o
