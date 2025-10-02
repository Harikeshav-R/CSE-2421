/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 * TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 * THIS ASSIGNMENT.
 */

#include "project3.h"

/* Reads each ingredient from input and populates the array. */
static void populate_ingredients(char** ingredients, const int count)
{
    printf("Enter the %d ingredients one to a line:\n", count);
    for (int i = 0; i < count; i++)
    {
        *(ingredients + i) = get_item();
    }
}

/* Gets the list of available ingredients from the user. */
void get_ingredients(char*** ingredients, int* count)
{
    printf("How many available pizza ingredients do we have today? ");
    scanf("%d", count);
    getchar();

    *ingredients = malloc(*count * sizeof(char*));
    if (*ingredients == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    populate_ingredients(*ingredients, *count);
}
