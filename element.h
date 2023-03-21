#ifndef ELEMENT_H 
#define ELEMENT_H


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int ELEMENT;

void affiche_ELEMENT(ELEMENT e);

void saisir_ELEMENT(ELEMENT* e);

void affect_ELEMENT(ELEMENT *e, int valeur);

int compare_ELEMENT(ELEMENT e1, ELEMENT e2);

#endif