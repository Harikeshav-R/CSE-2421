# BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
# TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
# THIS ASSIGNMENT.

# Makefile for CSE 2421 Project 3

CC = gcc
CFLAGS = -std=c99 -pedantic -Wimplicit-function-declaration -Wreturn-type -Wformat -g

SRCS = project3main.c get_ingredients.c get_item.c get_thispizza.c save_info.c free_dmem.c
OBJS = project3main.o get_ingredients.o get_item.o get_thispizza.o save_info.o free_dmem.o
EXEC = project3

ZIP_FILE = project3.zip
ZIP_CONTENT = $(SRCS) project3.h Makefile PROJECT3README input.txt

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

project3main.o: project3main.c project3.h
	$(CC) $(CFLAGS) -c project3main.c -o project3main.o

get_ingredients.o: get_ingredients.c project3.h
	$(CC) $(CFLAGS) -c get_ingredients.c -o get_ingredients.o

get_item.o: get_item.c project3.h
	$(CC) $(CFLAGS) -c get_item.c -o get_item.o

get_thispizza.o: get_thispizza.c project3.h
	$(CC) $(CFLAGS) -c get_thispizza.c -o get_thispizza.o

save_info.o: save_info.c project3.h
	$(CC) $(CFLAGS) -c save_info.c -o save_info.o

free_dmem.o: free_dmem.c project3.h
	$(CC) $(CFLAGS) -c free_dmem.c -o free_dmem.o

project3.zip:
	zip $(ZIP_FILE) $(ZIP_CONTENT)

clean:
	rm -f $(OBJS) $(EXEC) $(ZIP_FILE)

test_console:
	./$(EXEC)

test_file:
	./$(EXEC) < input.txt