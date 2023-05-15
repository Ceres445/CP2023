#include <stdio.h>

/**
 * @brief Returns the cost of the pizza base based on its type: Regular (R) or
 * Thin crust (T).
 *
 * @retval 100 base_cost('R')
 * @retval 120 base_cost('T')
 */
int base_cost(char base_type) {
    if (base_type == 'R')
        return 100;
    else if (base_type == 'T')
        return 120;
    return 0;
}

/**
 * @brief Returns the additional cost of the pizza based on its size:
 * Medium (M), Large (L), or Extra Large (X).
 *
 * @retval 0 size_cost('M')
 * @retval 30 size_cost('L')
 * @retval 50 size_cost('X')
 */
int size_cost(char size_type) {
    if (size_type == 'M')
        return 0;
    else if (size_type == 'L')
        return 30;
    else if (size_type == 'X')
        return 50;
    return 0;
}

/**
 * @brief Returns the additional cost for the selected toppings: Cheese (C),
 * Veggies (V), Meat (M)
 *
 * @retval 30 toppings_cost('C')
 * @retval 60 toppings_cost('V')
 * @retval 90 toppings_cost('M')
 */
int toppings_cost(char toppings_type) {
    if (toppings_type == 'C')
        return 30;
    else if (toppings_type == 'V')
        return 60;
    else if (toppings_type == 'M')
        return 90;
    return 0;
}

/**
 * @brief Computes the total cost of the pizza given the choice of base, size,
 * and toppings.
 *
 */
int pizza_cost(char base_type, char size_type, char toppings_type) {
    return base_cost(base_type) + size_cost(size_type) +
           toppings_cost(toppings_type);
}

int main() {
    printf("Choose pizza base ('R' or 'T'): ");
    char base_type;
    scanf("%c", &base_type);
    getchar(); // needed to handle the ENTER character

    printf("Choose pizza size ('M', 'L', or 'X'): ");
    char size_type;
    scanf("%c", &size_type);
    getchar(); // needed to handle the ENTER character

    printf("Choose your toppings ('C', 'V', or 'M'): ");
    char toppings_type;
    scanf("%c", &toppings_type);

    int total = pizza_cost(base_type, size_type, toppings_type);
    printf("Your bill for the %c%c%c pizza is Rs. %d\n", base_type, size_type,
           toppings_type, total);

    return 0;
}
