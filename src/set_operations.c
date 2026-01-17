#include "set_operations.h"

int extraireUnique(int tableau[], int taille_tableau) {
    if (taille_tableau == 0) return 0;
    
    /* isDuplicate: flag indicating if the current element has already been encountered.
       unique_index: position pointer and counter for the number of unique elements inserted. */
    int unique_index = 1, isDuplicate = 0; 

    for (int i = 1; i < taille_tableau; i++) {
        isDuplicate = 0;
        for (int j = 0; j < unique_index; j++) {
            if (tableau[i] == tableau[j]) { 
                isDuplicate = 1;
                break; // Stop checking as soon as a duplicate is detected.
            }
        }
        
        /* Uniqueness validation: If isDuplicate == 0, the element is new. 
           It is inserted at the free slot (unique_index), then the pointer 
           is moved to the right for the next insertion. */
        if (isDuplicate == 0) { 
            tableau[unique_index] = tableau[i];
            unique_index++;
        }
    }
    return unique_index;
}

int extraireIntersection(int tab1[], int taille1, int tab2[], int taille2, int resultat[]) {
    int result_index = 0;
    
    /* Removing duplicates via a loop to ensure uniqueness for all elements 
       and adjusting the logical size of the arrays. */
    int n1 = extraireUnique(tab1, taille1);
    int n2 = extraireUnique(tab2, taille2);

    for (int i = 0; i < n1; i++) {
        // isCommon: flag indicating if the pointed element belongs to the intersection.
        int isCommon = 0; 
        
        for (int j = 0; j < n2; j++) { 
            /* Compare current element with the second array's content. 
               If a match is found (flag = 1), its presence in the intersection is validated. */
            if (tab1[i] == tab2[j]) { 
                isCommon = 1;
                break;
            }
        }
        
        /* After the verification loop ends:
           - If flag is 1: the element is confirmed to be in the intersection.
           - Insert it into the result array at 'result_index'.
           - Increment 'result_index' for the next slot.
           - Otherwise (flag = 0): the element is not common, continue with the next one. */
        if (isCommon == 1) {
            resultat[result_index] = tab1[i];
            result_index++;
        }
    }
    return result_index;
}