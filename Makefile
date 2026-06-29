EXE_NAME = run
EXE_GUI_NAME = run_interface
EXE_GERADOR_NAME = gerador
SOURCES = main.c cubo.c arquivo.c 
SOURCES_GUI = interface.c cubo.c arquivo.c 
SOURCES_GERADOR = gerador.c cubo.c
FLAGS = -Wall -Werror -I. -fsanitize=leak
BUILD_DIR = build

run:
	./$(BUILD_DIR)/$(EXE_NAME)

run_interface:
	./$(BUILD_DIR)/$(EXE_GUI_NAME) cubo_exemplo.txt

compile:
	mkdir -p $(BUILD_DIR)
	gcc -o $(BUILD_DIR)/$(EXE_NAME) $(SOURCES) $(FLAGS)

compile_interface:
	mkdir -p $(BUILD_DIR)
	gcc -o $(BUILD_DIR)/$(EXE_GUI_NAME) $(SOURCES_GUI) $(FLAGS) -lncurses

compile_gerador:
	mkdir -p $(BUILD_DIR)
	gcc -o $(BUILD_DIR)/$(EXE_GERADOR_NAME) $(SOURCES_GERADOR) $(FLAGS)

all: compile compile_interface compile_gerador

clean:
	rm -rf $(BUILD_DIR)
