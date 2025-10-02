/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 * TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 * THIS ASSIGNMENT.
 */

#include "project3.h"

/* Asks user if they want to save the receipt and acts accordingly. */
static void handle_save_receipt(char** ing, const int num_ing, char*** pizza, const int num_piz_ing, const int size)
{
    int choice = 0;
    printf("\nDo you want to save this receipt? (1=yes, 2=no): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        save_info(ing, num_ing, pizza, num_piz_ing, size);
    }
}

int main(void)
{
    char** ingredients = NULL;
    char*** this_pizza = NULL;
    int num_ingredients = 0, num_pizza_ingredients = 0, pizza_size = 0;

    get_ingredients(&ingredients, &num_ingredients);
    get_thispizza(ingredients, num_ingredients, &this_pizza, &num_pizza_ingredients, &pizza_size);
    handle_save_receipt(ingredients, num_ingredients, this_pizza, num_pizza_ingredients, pizza_size);
    free_dmem(ingredients, num_ingredients, this_pizza);

    return 0;
}
