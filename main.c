#define MAX_Taille 200
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include "fonction.h"
#include "Entrees.h"
#define TEST
#define PLAY

int main(int argc, char *argv[])
{
    #ifdef TEST
    // VARIABLES DECLARATION
    int cmp=11,cmp2=0, i, *testtab=NULL, modeChoix=0, joueurindice=1;
    char charac, chain[MAX_Taille], *savechain=NULL, choix;
    int chaine_longue = motAleatoire(chain), fun=0;
    //UTILISATION D ALLOCATION DYNAMIQUE
    savechain = (char*)malloc((chaine_longue+1)*sizeof(char));
    testtab = malloc(chaine_longue*sizeof(int));
    if(testtab == NULL || savechain == NULL) exit(0);
    printf("######################## BIENVENUE ###########################\n");
    printf("--------------------------------------------------------------\n");
    printf("######################## JEU PENDU ###########################\n");
    printf("--------------------------------------------------------------\n");
    do
    {
        printf(" * Mode de jeu : \n\t0-UN JOUEUR\n\t1-DEUX JOUEURS\nTapez 0 ou 1 pour choisir le mode : ");
        scanf("%d", &modeChoix);
        if(modeChoix)
        {
            printf("----------------> Entrer le nom du joueur qui va ajouter le mot :");
            scanf("%s", chain);
            printf("le premier joueur doit entrer le secret mot :");
            scanf("%s", chain);
            for(i=0 ; i < strlen(chain) ; i++) chain[i]=toupper(chain[i]);
            //printf("%s\n", chain);
            chaine_longue = strlen(chain);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nCommencons donc ! :)\n\n");
        }
    printf("\n\tMot chercher : ");
    for(i=0 ; i < chaine_longue ; i++) printf("  *");
    printf("\n");
    printf("--------------------------------------------------------------\n");
    //#else
    //INITIALISER LE TEST TABLEAU A 0
    if(chain != NULL)
    {
    initialiser_table(testtab, chaine_longue);
    //BOUCLE POUR TESTER LE CHARACTERE
    do {
    if(cmp<11) printf("\n-------------Vous avez %d coups---------------\n", cmp);
    else printf("\n---------------Great Job---------------\n");
    if(joueurindice)
    {
        printf("---------------> Entrer le nom du joueur qui teste : ");
        joueurindice=0;
    }
    else printf("------------------------------------------------> Entrer un caractere : ");
    charac = lire_caractere();
    //AFFECTATION DES VALEURS BOOLEANS
    for(i=0 ; i < chaine_longue ; i++)
    {
        if(charac == chain[i]){
                printf("Bien ^^ \n");
        testtab[i] = 1;
        cmp2++;
        cmp++;
        }
    }
    if(fun)
    {
    printf("Lettre trouver %d fois :)\n", cmp2);
    printf("Bonus +%d\n", cmp2);
    }
    cmp2=0;
    fun=1;
    //ENREGISTREMENT DES CHARACTERES TROUVER
    for(i=0 ; i < chaine_longue ; i++)
    {
        if(testtab[i]) savechain[i] = chain[i];
        else savechain[i] = '*';
    }
    //AFFICHAGE DU MOT SECRET
    printf("\n\t\t");
    for(i=0 ; i < chaine_longue ; i++)
    {
        printf("%c  ", savechain[i]);
    }
    printf("\n");
    cmp--;
    } while(cmp>0 && gagne(testtab, chaine_longue)!=1);
    //AFFICHAGE DU RESULTAT DU PARTIE
    if(gagne(testtab, chaine_longue)) printf("\n########################  :)\nBravo vous-avez trouver le mot \"%s\"\n", chain);
    else printf("\n########################  :(\nVous-avez perdu ! :(");
    //REQUEST POUR UNE NOUVELLE PARTIE
    printf("\nVoulez-vous une nouvelle partie ? (Y/N) : ");
    choix=lire_caractere();
    choix=toupper(choix);
    }
    cmp=11;
    joueurindice=1;
    chaine_longue=motAleatoire(chain);
    #endif // TEST
    } while(choix!='N');
    // NETWAYAGE DU MEMOIRE
    free(testtab);
    free(savechain);
    return 0;
}
