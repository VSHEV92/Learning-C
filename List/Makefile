SRC := List.c 
INCFLAGS := 

SRC += $(addprefix tests/, $(notdir $(wildcard tests/*.c)))
INCFLAGS += -I$(shell pwd)
INCFLAGS += -I$(shell pwd)/tests

EXECUTABLE := tests.elf

CFLAGS := -g -O0 -Wall -Werror

all: clean $(EXECUTABLE) 
	./$(EXECUTABLE)

$(EXECUTABLE):
	gcc $(CFLAGS) $(INCFLAGS) $(SRC) -o $(EXECUTABLE)


valgrind: clean $(EXECUTABLE)
	valgrind --leak-check=yes ./$(EXECUTABLE)


clean:
	rm -rf $(EXECUTABLE)

.PHONY: clean $(EXECUTABLE) all valgrind
