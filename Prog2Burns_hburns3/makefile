CC = g++
CC_FLAGS = -std=c++14 -Wall -pedantic -g -Wextra
 
$ALL: prog2tree
	./prog2tree -N 2 -M 2 
 
prog2tree: prog2tree.o
	$(CC) prog2tree.o -o prog2tree
 
# To obtain object files
prog2tree.o: prog2tree.c
	$(CC) -c $(CC_FLAGS) prog2tree.c -o prog2tree.o
 
# Main target
 
# To remove generated files
clean:
	rm -f $(EXEC1) $(EXEC2) *.o
checkmem:
	valgrind ./$(EXEC)
