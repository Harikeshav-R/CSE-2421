# comments in a Makefile start with sharp 
gcc_opt = -std=c99 -pedantic -Wimplicit-function-declaration -Wreturn-type -Wformat -g -c

# all is a required target in every makefile
# target all means all targets currently defined in this file
all: project2.zip bit_decode1 bit_decode2

# this target is the .zip file that must be submitted to Carmen
# dependents are any file that you want to go in to the .zip
# so you pretty much duplicate the files on both lines
project2.zip: Makefile bit_decode.c PROJECT2README
	zip project2.zip Makefile bit_decode.c PROJECT2README

# this target is the bit cipher executable that does not prompt for data
bit_decode1: bit_decode1.o
	gcc bit_decode1.o -o bit_decode1

# this target is the dependency for bit_decode1
bit_decode1.o: bit_decode.c
	gcc $(gcc_opt) -D PROMPT -o bit_decode1.o bit_decode.c

# this target is the bit cipher executable that prompts for input from the keyboard
bit_decode2: bit_decode2.o
	gcc bit_decode2.o -o bit_decode2

# this target is the dependency for bit_decode2
# notice that this target's command uses -D PROMPT on the command line so that
# lines of code that prompt for keyboard data and print data out compile
bit_decode2.o: bit_decode.c
	gcc $(gcc_opt) -o bit_decode2.o bit_decode.c

# this target deletes all files produced from the Makefile
# so that a completely new compile of all items is required
clean:
	rm -rf *.o bit_decode1 bit_decode2 project2.zip
