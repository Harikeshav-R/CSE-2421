/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 * TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 * THIS ASSIGNMENT.
 */

#include "project3.h"

/*
 * Frees all dynamically allocated memory used in the program.
 */
void free_dmem(char** ingredients, const int num_ingredients, char*** this_pizza)
{
    /* Free each ingredient string */
    for (int i = 0; i < num_ingredients; i++)
    {
        free(*(ingredients + i));
    }

    /* Free the array of ingredient pointers */
    free(ingredients);

    /* Free the array of pointers for the pizza order */
    free(this_pizza);
}
