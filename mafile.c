#include <stdio.h>
#include <stdlib.h>
#include "mafile.h"
#include "element.h"

MA_FILE init_FILE()
{
  MA_FILE f;
  f.tete = NULL;
  f.queue = NULL;
  return f;
}

void affiche_FILE(MA_FILE file)
{

  CELLULE *cell;

  if (FILE_est_vide(file))
  {
    printf("la pile est vide");
  }
  else
  {
    cell = file.tete;
    
    printf("[");
    while (cell != NULL)
    {
      affiche_ELEMENT(cell->eCell);
      cell = cell->cellSuiv;
      if (cell != NULL)
      {
        printf(",");
      }
    }
    printf("] \n");
  }

  
}

int FILE_est_vide(MA_FILE file)
{
  return (file.tete == NULL);
}

void enFILE(MA_FILE *file, ELEMENT e)
{
  CELLULE *cell;
  cell = (CELLULE *)malloc(sizeof(CELLULE));

  if (cell != NULL)
  {
    cell->eCell = e;
    cell->cellSuiv = NULL;
    if (FILE_est_vide(*file))
    {
      file->queue = cell;
      file->tete = cell;
    }
    else
    {
      file->queue->cellSuiv = cell;
      file->queue = cell;
    }
  }
}

void deFILE(MA_FILE *f, ELEMENT *e)
{
  CELLULE *cell;

  if (!FILE_est_vide(*f)){
    cell = f->tete;
    *e = cell->eCell;
    f->tete = cell->cellSuiv;

    free(cell);

    if (FILE_est_vide(*f))
      f->queue = f->tete;
  }
}

MA_FILE saisir_FILE()
{
  MA_FILE file;
  int nb, i;
  ELEMENT e;

  file = init_FILE();

  printf("Nombre d'élements à inserer : ");
  scanf("%i", &nb);
  for (i = 0; i < nb; i++)
  {
    printf("Saisissez un element de la file : \n");

    saisir_ELEMENT(&e);
    enFILE(&file, e);
  }
  return file;
}
