SOURCE_FILE := quick_sort.c
EXECUTABLE := quick_sort 

$(EXECUTABLE): $(SOURCE_FILE)
	gcc $(SOURCE_FILE) -o $(EXECUTABLE)

run: $(EXECTUBALE)
	./$(EXECUTABLE)

# This is how I should remember Makefiles in the future
# target: dependency
# 	commands
#
# Target = what we want to create
# Dependency = what needs to already be created
# Command = command to run. This successfully runs because our dependency should be created
# Another thing to note, is that we start from the bottom, to the top. So the top instruction
# will be our final output. it builds on top of each other like a stack, with the bottom
# being the first steps, and the top vbeing the final executable

# My first Makefile! This is very simple, but in the future if we have to link multiple
# files together, then the syntax is more like this
# # Target: Create the executable (my_program)
#my_program: file1.o file2.o
#	gcc file1.o file2.o -o my_program
#
## Rule to create object file from file1.c
#file1.o: file1.c
#	gcc -c file1.c -o file1.o
#
## Rule to create object file from file2.c
#file2.o: file2.c
#	gcc -c file2.c -o file2.o
#
## Clean up object files and the executable
#clean:
#	rm -f *.o my_program

# Another thing, is this project is just a bunch of simple programs lumped together, so obviously
# this is probably not a standard thing to do, since I have to adjust this every time I work on 
# a different file, but it works for now and gives me a taste of Makefiles and how to use them
