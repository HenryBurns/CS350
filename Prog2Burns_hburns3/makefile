CC = g++
CC_FLAGS = -std=c++14 -Wall -pedantic -g -Wextra
 
$ALL: progtree
	./progtree
 
progtree: progtree.o
	$(CC) progtree.o -o progtree
 
# To obtain object files
%.o: %.c
	$(CC) -c $(CC_FLAGS) $< -o $@
 
# Main target
 
# To remove generated files
clean:
	rm -f $(EXEC1) $(EXEC2) *.o
checkmem:
	valgrind ./$(EXEC)
