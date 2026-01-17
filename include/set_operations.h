#ifndef SET_OPERATIONS_H
#define SET_OPERATIONS_H

// Prototypes des fonctions
/**
 * @brief Extrait les éléments uniques d'un tableau.
 * @return Le nombre d'éléments uniques (nouvelle taille logique).
 */
int extraireUnique(int tableau[], int taille_tableau);
/**
 * @brief Calcule l'intersection de deux tableaux.
 * @return Le nombre d'éléments communs trouvés.
 */
int extraireIntersection(int tab1[], int taille1, int tab2[], int taille2, int resultat[]);

#endif