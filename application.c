#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "mafile.h"

#define PRIX_TICKET 7.99

int saisie_ticket(MA_FILE *file)
{
    ELEMENT e;
    int nbSeance, nbClient, nbTicket, nbTotal, i, j;

    do
    {
        printf("Combien y a t'il eu de seances aujourd'hui : ");
        scanf("%d", &nbSeance);
        if(nbSeance < 0)
        {
            printf("Erreur de saisie \n");
        }
    } while (nbSeance < 0);
    
    // Autant de saisie que de composants
    for ( i = 0; i < nbSeance; i++)
    {

        printf("Séance  n°%d : \n ", i+1);

        do
        {
            printf("Veuillez saisir le nombre de clients : ");
            scanf("%d", &nbClient);
            if(nbClient < 0)
            {
                printf("Erreur de saisie \n");
            }
        } while (nbClient < 0);


        for (j = 0; j < nbClient; j++)
        {

            do
            {
                printf("Combien de ticket à prix le client n°%d ?", j+1);
                scanf("%d", &nbTicket);
                if(nbTicket < 0)
                {
                    printf("Erreur de saisie \n");
                }
            } while (nbTicket < 0);

            affect_ELEMENT(&e, nbTicket);
            enFILE(file, e);

            nbTotal++;
        }
    }
    return nbTotal;
}

void calcul_total_journee(MA_FILE *file, int nbTotal, int *totalTicket, float *total)
{
    ELEMENT e;
    int i;

    *totalTicket = 0;
    *total = 0;

    for (i = 0; i < nbTotal; i++)
    {
        deFILE(file, &e);
        *totalTicket = (*totalTicket) + e;
        *total = (*total) + (e * PRIX_TICKET);
    }
}

void affichage_bilan(int totalTicket, float total)
{
    printf("Bilan de la journée ! \n");
    printf("Il y a eu %d ticket(s) vendu(s) \n", totalTicket);
    printf("Le total des ventes est de : %.2f € \n", total);

}

int main(int argc, char const *argv[])
{
    int nbTotal, nbTotalTickets;
    float totalVente;

    MA_FILE file;

    file = init_FILE();

    printf("Bienvenue dans notre cinéma !\n");
    printf("Un seul film est disponible\n");
    printf("Le prix du ticket est de %.2f€ !\n", PRIX_TICKET);

    nbTotal = saisie_ticket(&file);

    printf("Liste du nombre de tickets : \n");
    affiche_FILE(file);

    calcul_total_journee(&file, nbTotal, &nbTotalTickets, &totalVente);

    affichage_bilan(nbTotalTickets, totalVente);

    return 0;
}
