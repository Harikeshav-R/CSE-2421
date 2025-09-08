# BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED
# TO THE TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH
# RESPECT TO THIS ASSIGNMENT.

# comments in a Makefile start with sharp 
gcc_opt =  -std=c99 -pedantic -Wimplicit-function-declaration -Wreturn-type -Wformat -g -c

# target all means all targets currently defined in this file (project1.zip and project1)
all: project1.zip project1

# this target is the .zip file that must be submitted to Carmen
# this target depends upon 3 items: Makefile project1.c and LAB1README
project1.zip: Makefile project1.c project1_func.c  local_file.h PROJECT1README project1.input1 project1.input2 
#this is the linux command we want make to execute
#if Makefile project1.c or PROJECT1README has changed
	zip project1.zip Makefile project1.c project1_func.c local_file.h  PROJECT1README project1.input1 project1.input2 
# this target is for the project1 executable 
# the project1 target gets recreated if project1.o has changed
project1: project1.o project1_func.o
#this is the linux command we want make to execute
#if project1.o has changed, note that we only use the -o option here
	gcc project1.o project1_func.o -o project1

# this target is the dependency for project1.o
# the project1.o target gets recreated if project1.c has changed
project1.o: project1.c local_file.h


# this is the linux command we want make to execute
# if project1.c has changed, note that this is where most of the
# gcc options are and there is now a -c option used
# -c option means that we stop compiling after we create a .o
# file.  We don't compile all the way to the end creating an 
# executable.
	gcc $(gcc_opt) project1.c

# this target is the dependency for project1_func.o
# the project1_func.o target gets recreated if project1_func.c has changed
project1_func.o: project1_func.c local_file.h
	gcc $(gcc_opt) project1_func.c

# this target deletes all files produced from the Makefile
# so that a completely new compile of all items is required
clean:
	rm -rf *.o project1 project1.zip
	rmdir testdir


test:
	echo "files in project1 directory"
	ls
	mkdir testdir
	cp project1.zip testdir
	unzip project1.zip -d testdir
	make -C testdir project1
	echo "files in testdir directory"
	ls testdir
	rm -rf testdir/*

