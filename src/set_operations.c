#include "set_operations.h"

int extraireUnique(int tableau[], int taille_tableau) {
    if (taille_tableau == 0) return 0;
    int indice_unique = 1, estDoublon = 0; /*estDoublon : flag indiquant si l'élément courant a déjà été rencontré dans le tableau d'unicité.
    indice_unique : pointeur de position et compteur du nombre d'éléments uniques insérés.*/ 

    for (int i=1;i<taille_tableau;i++) {
        estDoublon = 0;
        for (int j=0;j<indice_unique;j++) {
            if (tableau[i]==tableau[j]) { 
                estDoublon=1;
                break; // interruption de la vérification dès qu'un doublon est détecté.
            }
        }
        if (estDoublon==0) { /*Validation de l'unicité : Si estDoublon == 0, l'élément est nouveau, il est donc inséré à l'emplacement libre (indice_unique), 
            puis le pointeur est décalé vers la droite pour la prochaine insertion*/ 
            tableau[indice_unique]=tableau[i];
            indice_unique++;
        }
    }
    return indice_unique;
}

int extraireIntersection(int tab1[],int taille1,int tab2[],int taille2,int resultat[]){
    int indice_resultat=0;
    // Suppression des doublons via un loop d'unicité pour guarantir l'unicité de tous les éléments et ajustement de la taille du tableau.
    int n1 = extraireUnique(tab1, taille1);
    int n2 = extraireUnique(tab2, taille2);

    for (int i = 0; i < n1; i++) {
        int estCommun = 0; // flag indiquant si l'élément pointé appartient à l'intersection des deux tableaux.
        for (int j = 0; j < n2; j++) { 
            if (tab1[i] == tab2[j]) { // On compare l'élément actuel au contenu du deuxième tableau. Si une correspondance est trouvée (flag = 1), on valide sa présence dans l'intersection.
                estCommun = 1;
                break;
            }
        }
        if (estCommun == 1) {
            resultat[indice_resultat] = tab1[i];
            indice_resultat++;
        }
        /* Après la fin du loop de vérification :
   - Si le flag vaut 1 : l'élément est confirmé comme appartenant à l'intersection.
   - On l'insère dans le tableau de résultat à la position 'indice_resultat'.
   - On incrémente 'indice_resultat' pour préparer le prochain emplacement.
   - Sinon (flag = 0) : l'élément n'est pas commun, on continue avec l'élément suivant.
*/
    }
    return indice_resultat;
}