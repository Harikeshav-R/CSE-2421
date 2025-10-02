/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 * TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 * THIS ASSIGNMENT.
 */

#include "project3.h"

static void write_available_ingredients(FILE* file, char** ingredients, const int count)
{
    fprintf(file, "Available Pizza Ingredients today:\n");
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d. %s\n", i + 1, *(ingredients + i));
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

static void write_receipt_to_file(FILE* file, char*** this_pizza, const int count, const int size)
{
    double base, per_item;
    char* size_str;
    get_pizza_details(size, &base, &per_item, &size_str);

    double total = base;
    fprintf(file, "\nHere is your receipt:\n");
    fprintf(file, "%-15s $%5.2f\n", size_str, base);
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d. %-13s $%5.2f\n", i + 1, **(this_pizza + i), per_item);
        total += per_item;
    }
    fprintf(file, "\nTotal Due:        $%5.2f\n", total);
}

void save_info(char** ingredients, const int num_ingredients, char*** this_pizza, const int num_pizza_ingredients,
               const int pizza_size)
{
    char filename[100];
    printf("What file name do you want to use? ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }

    write_available_ingredients(file, ingredients, num_ingredients);
    write_receipt_to_file(file, this_pizza, num_pizza_ingredients, pizza_size);
    fclose(file);
    printf("Today's Receipt has been saved to the file %s.\n", filename);
}
