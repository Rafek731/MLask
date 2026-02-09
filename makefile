CXX = g++
FLAGS = -Wall -Wextra
OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src
TEST_DIR = test
LIB_DIR = lib

LIB_NAME = MLask
LIB = $(LIB_DIR)/$(LIB_NAME).a
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/%.test.o, $(TEST_SOURCES))
TEST_BINARIES = $(patsubst $(TEST_DIR)/%.cpp, $(BIN_DIR)/%.test, $(TEST_SOURCES))

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

.PHONY: dir test clean all lib

all: dir $(LIB) test
dir: 
	mkdir -p $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)
lib: $(LIB)

$(OBJECTS): $(SOURCES)
	$(CXX) $(FLAGS) -c $< -o $@

$(LIB): $(OBJECTS)
	ar rcs $@ $^

$(TEST_OBJECTS): $(TEST_SOURCES)
	$(CXX) $(FLAGS) -c $< -o $@

$(TEST_BINARIES): $(TEST_OBJECTS)
	$(CXX) $(FLAGS) $^ -L./$(LIB_DIR) -l:$(LIB_NAME).a -o $@

test: $(TEST_BINARIES)
	./$^

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(BIN_DIR)/*.test
	rm -f $(LIB)
	