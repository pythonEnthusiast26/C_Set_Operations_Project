#include <stdio.h>
#include "set_operations.h"

void afficherTableau(int tab[],int taille){
    printf("[");
    for(int i=0;i<taille;i++){
        printf("%d%s", tab[i], (i<taille-1) ? "," : ""); // Afficher le nombre, suivi d'une virgule s'il n'est pas le dernier élément
    }
    printf("]\n");
}

int main(){
    
    int tableau1[]={1,2,1,3,5,5};
    int tableau2[]={2,3,1,4,1};
    
    int intersection[10];
    
    int taille1=6;
    int taille2=5;

    printf("Le tableau 1 original: "); afficherTableau(tableau1,taille1);
    printf("Le tableau 2 original: "); afficherTableau(tableau2,taille2);
    
    int taille_inter=extraireIntersection(tableau1, taille1, tableau2, taille2, intersection); // la taille propre du tableau content les éléments communs uniques
    
    printf("\n---Resultat S&D---\n");
    printf("l'intersection unique est: ");afficherTableau(intersection,taille_inter);
    printf("le nombre d'éléments communs est: %d",taille_inter);

    
    return 0;
}