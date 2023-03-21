#ifndef MAFILE_H
#define MAFILE_H

#include "element.h"

typedef struct Cellule
{
  ELEMENT eCell;
  struct Cellule * cellSuiv;
} CELLULE;

// Structure Pile definie
typedef struct File
{
  CELLULE *tete;
  CELLULE *queue;
} MA_FILE;

// Méthodes
MA_FILE init_FILE();

void affiche_FILE(MA_FILE file);

int FILE_est_vide(MA_FILE file);

void enFILE(MA_FILE *f, ELEMENT val); // Modification du int en ELEMENT (param)

void deFILE(MA_FILE *f, ELEMENT *val); // Modification du int en ELEMENT (param)

MA_FILE saisir_FILE();

#endif
