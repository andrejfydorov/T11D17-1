# A makefile consists of targets and commands that need to be executed to reach the target.


all: FORCE

door_struct: dmanager_module.c
	gcc dmanager_module.c -o ..\build\Quest_1

list_test: list_test.c
	gcc dmanager_module.c -o ..\build\Quest_2

#.PHONY:rebuild clean all

rebuild: clean all

clean:
	rm -rf *.o ..\..\build\

FORCE:

