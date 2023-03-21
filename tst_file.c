#include <stdio.h>
#include "mafile.h"

#define TOTALTEST 10

/**
Programme de test de la file TP FIFO
Julian TRANI 1A SRI
25/11
*/

// Test la fonction init_PILE
void test_init_FILE(int *nbTestOK, int *numTest)
{
  MA_FILE file;
  file = init_FILE();
  // Test que apres l'init la pile est bien vide donc la tete == NULL
  if (file.tete == NULL)
  {
    printf("TEST %d OK \n", *numTest);
    *nbTestOK += 1;
    *numTest += 1;
  }
  else
  {
    printf("TEST %d NOK \n", *numTest);
    *numTest += 1;
  }

  // Test que apres l'init la pile est bien vide donc la queue == NULL
  if (file.queue == NULL)
  {
    printf("TEST %d OK \n", *numTest);
    *nbTestOK += 1;
    *numTest += 1;
  }
  else
  {
    printf("TEST %d NOK \n", *numTest);
    *numTest += 1;
  }
}

void test_estVide(int *nbTestOK, int *numTest)
{
  MA_FILE file;
  file = init_FILE();

  // Test sans entier dans la pile (apres l'init)
  if (FILE_est_vide(file) == 1)
  {
    printf("TEST %d OK \n", *numTest);
    *nbTestOK += 1;
    *numTest += 1;
  }
  else
  {
    printf("TEST %d NOK \n", *numTest);
    *numTest += 1;
  }

  ELEMENT elem;
  affect_ELEMENT(&elem, 5);
  enFILE(&file, elem);

  // Test avec une pile pleine
  if (FILE_est_vide(file) == 0)
  {
    printf("TEST %d OK \n", *numTest);
    *nbTestOK += 1;
    *numTest += 1;
  }
  else
  {
    printf("TEST %d NOK \n", *numTest);
    *numTest += 1;
  }

  deFILE(&file, &elem);

  // Test avec une pile auquel on a enleve un element (donc elle est doit etre)
  if (FILE_est_vide(file) == 1)
  {
    printf("TEST %d OK \n", *numTest);
    *nbTestOK += 1;
    *numTest += 1;
  }
  else
  {
    printf("TEST %d NOK \n", *numTest);
    *numTest += 1;
  }
}

void test_enFILE(int *nbTestOK, int *numTest)
{
  MA_FILE file;
  file = init_FILE();

  // Remplissage de la file
  ELEMENT elem;
  affect_ELEMENT(&elem, 5);
  enFILE(&file, elem);

  // Test pour savoir si la tete est bien été mise à jour apres le enFILE
  if (file.queue != NULL)
  {
    printf("TEST %d OK \n", *numTest);
    *nbTestOK += 1;
    *numTest += 1;
  }
  else
  {
    printf("TEST %d NOK \n", *numTest);
    *numTest += 1;
  }

  // Test pour savoir si la queue est bien été mise à jour apres le enFILE
  if (file.tete != NULL)
  {
    printf("TEST %d OK \n", *numTest);
    *nbTestOK += 1;
    *numTest += 1;
  }
  else
  {
    printf("TEST %d NOK \n", *numTest);
    *numTest += 1;
  }
}

void test_deFILE(int *nbTestOK, int *numTest)
{
  MA_FILE file;
  file = init_FILE();

  // Remplissage de la file
  ELEMENT elem;
  affect_ELEMENT(&elem, 5);
  enFILE(&file, elem);

  // Enleve l'element saisie
  deFILE(&file, &elem);

  // Vérification que dans le deFILE, on récupere bien le bon ELEMENT
  if (elem == 5)
  {
    printf("TEST %d OK \n", *numTest);
    *nbTestOK += 1;
    *numTest += 1;
  }
  else
  {
    printf("TEST %d NOK \n", *numTest);
    *numTest += 1;
  }

  // Test pour savoir si la tete est bien été mise à jour apres le deFILE
  // La file est vide donc queue NULL
  if (file.queue == NULL)
  {
    printf("TEST %d OK \n", *numTest);
    *nbTestOK += 1;
    *numTest += 1;
  }
  else
  {
    printf("TEST %d NOK \n", *numTest);
    *numTest += 1;
  }

  // Test pour savoir si la queue est bien été mise à jour apres le deFILE
  if (file.tete == NULL)
  {
    printf("TEST %d OK \n", *numTest);
    *nbTestOK += 1;
    *numTest += 1;
  }
  else
  {
    printf("TEST %d NOK \n", *numTest);
    *numTest += 1;
  }

  // Enlève un ELEMENT alors que la file est vide
  // Erreur attendu
  printf("TEST deFILE une file vide => une erreur est attendu : \n");
  deFILE(&file, &elem);
}

int main(int argc, char const *argv[])
{
  int nbTestOK = 0;
  int numTest = 1;
  printf("=====================================\n");
  printf("Bienvenue dans le programme de test !\n");
  printf("=====================================\n");

  // Exécution des tests sur l'élément.

  // Exécution des tests sur la pile.
  printf("Test init_FILE : \n\n");
  test_init_FILE(&nbTestOK, &numTest);
  printf("\nTest FILE_est_vide : \n\n");
  test_estVide(&nbTestOK, &numTest);
  printf("\nTest enFILE : \n\n");
  test_enFILE(&nbTestOK, &numTest);
  printf("\nTest deFILE : \n\n");
  test_deFILE(&nbTestOK, &numTest);

  // Affichage du résultat des tests
  printf("\n=====================================\n");
  printf("Résultat : %d/%d \n", nbTestOK, TOTALTEST);
  printf("=====================================\n");
  return 0;
}
