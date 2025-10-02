/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 * TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 * THIS ASSIGNMENT.
 */

#include "project3.h"

static void display_menu(char** ingredients, const int ing_count)
{
    printf("\nWelcome to our Pizza ordering system!\n");
    printf("Today we have the following fresh ingredients available:\n");
    for (int i = 0; i < ing_count; i++)
    {
        printf("%d. %s\n", i + 1, *(ingredients + i));
    }
}

static void get_order_details(const int ing_count, int* pizza_size, int* pizza_ing_count)
{
    printf("\nWhat size pizza would you like to order:\n");
    printf("1) Small\n2) Medium\n3) Large\n");
    scanf("%d", pizza_size);

    printf("Of our %d available ingredients, how many do you plan to put on your pizza? ", ing_count);
    scanf("%d", pizza_ing_count);
}

static void select_ingredients(char** ingredients, char*** this_pizza, const int count)
{
    int choice;
    printf("Enter the number next to each ingredient you want on your pizza: ");
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &choice);
        *(this_pizza + i) = (ingredients + (choice - 1));
    }
}

static void get_pizza_details(const int size, double* base, double* per_item, char** size_str)
{
    if (size == 1)
    {
        *base = 5.00;
        *per_item = 1.00;
        *size_str = "Small Pizza";
    }
    else if (size == 2)
    {
        *base = 7.50;
        *per_item = 1.25;
        *size_str = "Medium Pizza";
    }
    else
    {
        *base = 10.00;
        *per_item = 1.50;
        *size_str = "Large Pizza";
    }
}

static void print_receipt(char*** this_pizza, const int count, const int size)
{
    double base, per_item;
    char* size_str;
    get_pizza_details(size, &base, &per_item, &size_str);

    double total = base;
    printf("\nHere is your receipt:\n");
    printf("%s $%5.2f\n", size_str, base);
    for (int i = 0; i < count; i++)
    {
        printf("%d. %-13s $%5.2f\n", i + 1, **(this_pizza + i), per_item);
        total += per_item;
    }
    printf("\nTotal Due:        $%5.2f\n", total);
}

void get_thispizza(char** ingredients, const int ing_count, char**** this_pizza, int* pizza_ing_count, int* pizza_size)
{
    display_menu(ingredients, ing_count);
    get_order_details(ing_count, pizza_size, pizza_ing_count);

    *this_pizza = malloc(*pizza_ing_count * sizeof(char**));
    if (*this_pizza == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    select_ingredients(ingredients, *this_pizza, *pizza_ing_count);
    print_receipt(*this_pizza, *pizza_ing_count, *pizza_size);
}
