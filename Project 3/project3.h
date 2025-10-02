/*
 * BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE
 * TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY WITH RESPECT TO
 * THIS ASSIGNMENT.
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */

/*
 * Reads a single ingredient item from standard input, dynamically allocates
 * memory for it, and returns a pointer to the allocated string.
 */
char* get_item(void);

/*
 * Populates the list of available ingredients.
 * ingredients: Pointer to the array of ingredient strings.
 * count: Pointer to an integer to store the number of ingredients.
 */
void get_ingredients(char*** ingredients, int* count);

/*
 * Handles the customer's pizza order.
 * ingredients: The array of available ingredients.
 * ing_count: The total number of available ingredients.
 * this_pizza: Pointer to the array that will store the customer's chosen ingredients.
 * pizza_ing_count: Pointer to an integer to store the number of ingredients on the pizza.
 * pizza_size: Pointer to an integer to store the chosen pizza size.
 */
void get_thispizza(char** ingredients, int ing_count, char**** this_pizza, int* pizza_ing_count, int* pizza_size);

/*
 * Saves the receipt of the order to a file.
 * ingredients: The array of available ingredients.
 * num_ingredients: The total number of available ingredients.
 * this_pizza: The array representing the customer's pizza order.
 * num_pizza_ingredients: The number of ingredients on the customer's pizza.
 * pizza_size: The size of the pizza.
 */
void save_info(char** ingredients, int num_ingredients, char*** this_pizza, int num_pizza_ingredients, int pizza_size);

/*
 * Frees all dynamically allocated memory.
 * ingredients: The array of ingredient strings.
 * num_ingredients: The total number of ingredients.
 * this_pizza: The array for the customer's pizza order.
 */
void free_dmem(char** ingredients, int num_ingredients, char*** this_pizza);
