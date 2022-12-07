CC := g++
SRC_DIR := src
BIN_DIR := bin

EXE := $(BIN_DIR)/Program

SRC := $(wildcard $(SRC_DIR)/*.cpp)

OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

CPPFLAGS := -Iinclude -MMD -MP # -I is a preprocessor flag, not a compiler flag
CFLAGS   := -Wall              # some warnings about bad code
LDFLAGS  := -Llib              # -L is a linker flag
LDLIBS   := -lm -lSDL2 -lSDL2_image -lSDL2_ttf    # Left empty if no libs are needed

all: $(EXE) 

.PHONY: all clean

$(EXE): $(OBJ) | $(BIN_DIR)
	    $(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	    $(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	    mkdir -p $@

clean:
	    @$(RM) -rv $(BIN_DIR) $(OBJ_DIR)


$(BIN_DIR):
	    mkdir -p $@

		
