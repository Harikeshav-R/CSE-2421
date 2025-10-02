/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 * TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 * THIS ASSIGNMENT.
 */

#include "project3.h"

/* Reads characters into buffer until newline or EOF. */
static void read_line(char* buffer, const int size)
{
    int i = 0;
    char c;
    while (i < size - 1 && (c = (char)getchar()) != '\n' && c != EOF)
    {
        *(buffer + i) = c;
        i++;
    }
    *(buffer + i) = '\0'; /* Null-terminate the string */
}

/* Allocates memory for and reads a single ingredient item. */
char* get_item(void)
{
    char* item = malloc(100 * sizeof(char));
    if (item == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    read_line(item, 100);
    return item;
}
