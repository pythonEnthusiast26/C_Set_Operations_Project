#ifndef SET_OPERATIONS_H
#define SET_OPERATIONS_H

// Function prototypes

/**
 * @brief Extracts unique elements from an array.
 * @return The number of unique elements (new logical size).
 */
int extraireUnique(int tableau[], int taille_tableau);

/**
 * @brief Computes the intersection of two arrays.
 * @return The number of common elements found.
 */
int extraireIntersection(int tab1[], int taille1, int tab2[], int taille2, int resultat[]);

#endif