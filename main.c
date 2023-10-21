#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @struct AtomicElement
 * @brief Structure to store information about an atomic element.
 */
typedef struct atomic_element
{
    char name[20];       /** Name of the atomic element */
    char symbol[3];      /** Atomic symbol of the element */
    double weight;       /** Atomic weight of the element */
    double density;      /** Density of the element (in g/cm^3) */
    struct atomic_element* next; /** Pointer to the next element in a linked list */
} atomic_element;


/**
 * @brief Prints a table of atomic element information to the console.
 *
 * This function takes a pointer to an atomic element and prints a table
 * displaying the atomic number, symbol, name, atomic weight, and density
 * of each element in a tabular format.
 *
 * @param element A pointer to the first atomic element in a linked list.
 */
void print_atomic_element(atomic_element* element)
{
    printf("------------------------------------------------------------------------------------------\n");
    printf("| Atomic Number |  Symbol  |       Name       | Atomic Weight (g/mol) | Density (g/cm3)  |\n");
    printf("------------------------------------------------------------------------------------------\n");
    int atomic_number = 0;
    while (element != NULL)
    {
        printf("|       %2d       |   %-2s    | %-15s |        %-10.3f        |    %-8.2f    |\n", atomic_number,element->symbol, element->name, element->weight, element->density);
        atomic_number += 1;
        element = element->next;
    }
    printf("------------------------------------------------------------------------------------------\n"); 
}
/**
 * @brief Creates an atomic element and returns a pointer to it.
 *
 * This function dynamically allocates memory for a new atomic element and initializes its
 * members with the provided values. It returns a pointer to the created atomic element.
 *
 * @param name    The name of the atomic element.
 * @param symbol  The atomic symbol of the element.
 * @param weight  The atomic weight of the element.
 * @param density The density of the element (in g/cm^3).
 *
 * @return A pointer to the created atomic element.
 */
atomic_element* create_atomic_elements(const char name[20], const char symbol[3], double weight, double density)
{
    atomic_element* head = (atomic_element*)malloc(sizeof(atomic_element));
    if (head != NULL)
    {
        strcpy(head->name, name);
        strcpy(head->symbol, symbol);
        head->weight = weight;
        head->density =density;
        head->next = NULL;
    }
    return head;
}

/**
 * @brief Frees the memory allocated for the linked list of atomic elements.
 *
 * This function traverses the linked list starting from the head and frees the memory
 * allocated for each atomic element. After calling this function, the linked list will
 * no longer be valid.
 *
 * @param head A pointer to the first element in the linked list.
 */
void free_atomic_elements(atomic_element* head)
{
    atomic_element* current = head;
    while (current != NULL) {
        atomic_element* next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    // Create atomic elements for the first ten elements in the periodic table
    atomic_element* hydrogen = create_atomic_elements("Hydrogen", "H", 1.008, 0.09);
    atomic_element* helium = create_atomic_elements("Helium", "He", 4.003, 0.18);
    atomic_element* lithium = create_atomic_elements("Lithium", "Li", 6.941, 0.53);
    atomic_element* beryllium = create_atomic_elements("Beryllium", "Be", 9.012, 1.085);
    atomic_element* boron = create_atomic_elements("Boron", "B", 10.811, 2.34);
    atomic_element* carbon = create_atomic_elements("Carbon", "C", 12.011, 2.26);
    atomic_element* nitrogen = create_atomic_elements("Nitrogen", "N", 14.007, 1.25);
    atomic_element* oxygen = create_atomic_elements("Oxygen", "O", 15.999, 1.43);
    atomic_element* fluorine = create_atomic_elements("Fluorine", "F", 18.998, 1.70);
    atomic_element* neon = create_atomic_elements("Neon", "Ne", 20.180, 0.90);

    // Link the elements together in a linked list
    hydrogen->next = helium;
    helium->next = lithium;
    lithium->next = beryllium;
    beryllium->next = boron;
    boron->next = carbon;
    carbon->next = nitrogen;
    nitrogen->next = oxygen;
    oxygen->next = fluorine;
    fluorine->next = neon;

    // Print the information of the atomic elements
    print_atomic_element(hydrogen);

    // Free the allocated memory
    free_atomic_elements(hydrogen);

    return 0;
}

/*After compiling my code. I got the result below:
*   $ ./main
*   ------------------------------------------------------------------------------------------
*   | Atomic Number |  Symbol  |       Name       | Atomic Weight (g/mol) | Density (g/cm3)  |
*   ------------------------------------------------------------------------------------------
*   |        0       |   H     | Hydrogen        |        1.008             |    0.09        |
*   |        1       |   He    | Helium          |        4.003             |    0.18        |
*   |        2       |   Li    | Lithium         |        6.941             |    0.53        |
*   |        3       |   Be    | Beryllium       |        9.012             |    1.08        |
*   |        4       |   B     | Boron           |        10.811            |    2.34        |
*   |        5       |   C     | Carbon          |        12.011            |    2.26        |
*   |        6       |   N     | Nitrogen        |        14.007            |    1.25        |
*   |        7       |   O     | Oxygen          |        15.999            |    1.43        |
*   |        8       |   F     | Fluorine        |        18.998            |    1.70        |
*   |        9       |   Ne    | Neon            |        20.180            |    0.90        |
*   ------------------------------------------------------------------------------------------
*                                       © AYARI Adel
*/