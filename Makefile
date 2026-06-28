EXE_NAME = run
#LIB_NAME = calc.a

SOURCES= main.c cubo.c arquivo.c 
#SOURCES_LIB=calculadora.c
FLAGS=-Wall -Werror -I. -fsanitize=leak
BUILD_DIR=build


#$(CC)=gcc
#$(CC_FLAGS)=-Wall -Werror -Iinclude
#$(LL_FLAGS)=-lcalc


run:
	./$(BUILD_DIR)/$(EXE_NAME)

compile:
	mkdir -p $(BUILD_DIR)
	gcc -o $(BUILD_DIR)/$(EXE_NAME) $(SOURCES) $(FLAGS)

all:
	gcc -c main.c -o calc.exe -o minha_lib -Iinclude


clean:
	rm -rf $(BUILD_DIR)/calc



