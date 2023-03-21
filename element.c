#include <stdio.h>
#include "element.h"
#include <stdio.h>
#include "element.h"

//fonctions

void affiche_ELEMENT(ELEMENT e) {
    printf("%d",e);
}

void saisir_ELEMENT(ELEMENT* e) {
    printf("Entrer la valeur: ");
    scanf("%d", &(*e));
}

void affect_ELEMENT(ELEMENT *e, int valeur){
	*e = valeur;
}

int compare_ELEMENT(ELEMENT e1, ELEMENT e2) {
    if (e1 ==e2)
    {
    	return 1;
    }
    else
        return 0;
}




