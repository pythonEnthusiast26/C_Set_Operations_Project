#include <stdio.h>
#include "set_operations.h"


void afficherTableau(int tab[], int taille) {
    printf("[");
    for (int i = 0; i < taille; i++) {
        // Display the number, followed by a comma if it's not the last element
        printf("%d%s", tab[i], (i < taille - 1) ? "," : ""); 
    }
    printf("]\n");
}

int main() {
    
    // Test datasets for set intersection
    int tableau1[] = {1, 2, 1, 3, 5, 5};
    int tableau2[] = {2, 3, 1, 4, 1};
    
    int intersection[10];
    
    int taille1 = 6;
    int taille2 = 5;

    printf("Original Array 1: "); afficherTableau(tableau1, taille1);
    printf("Original Array 2: "); afficherTableau(tableau2, taille2);
    
    // Get the logical size of the array containing unique common elements
    int taille_inter = extraireIntersection(tableau1, taille1, tableau2, taille2, intersection); 
    
    printf("\n--- S&D Result ---\n");
    printf("Unique intersection: "); afficherTableau(intersection, taille_inter);
    printf("Number of common elements: %d\n", taille_inter);

    return 0;
}