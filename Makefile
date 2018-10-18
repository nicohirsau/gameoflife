CC		:= g++ -g 
C_FLAGS := -std=c++11 -Wall -Wextra 

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=

EXECUTABLE_NAME := hmmm
ifeq ($(OS),Windows_NT)
EXECUTABLE	:= $(EXECUTABLE_NAME).exe
else
EXECUTABLE	:= $(EXECUTABLE_NAME)
endif

all: $(BIN)/$(EXECUTABLE)

clean:
	$(RM) $(BIN)/$(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp $(SRC)/backend/*.cpp $(SRC)/frontend/*.cpp
	$(CC) $(C_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)