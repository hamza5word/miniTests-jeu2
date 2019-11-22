#define MAX_Taille 200
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char lire_caractere()
{
    char caractere = getchar();
    caractere = toupper(caractere);
    while(getchar()!='\n');
    return caractere;
}

int gagne(int tab[], int N)
{
    int bien, i;
    for(i=0; i < N ; i++)
    {
        if(tab[i]) bien = 1;
        else return 0;

    }
    return bien;
}

void initialiser_table(int tab[], int N)
{
    int i;
    for(i=0 ; i < N ; i++)
    {
        tab[i]=0;
    }
}

int hazard(int nombre)
{
    srand(time(NULL));
    return (rand() % nombre);
}

int motAleatoire(char *chain)
{
    int nombre_mots=0, caractereLu=0, motAleatoir=0, chainlongue=0;
//FICHIER MOTS ACCESS
    FILE *fichier = NULL;
    fichier = fopen("mots.txt", "r");
    if(fichier==NULL)
    {
    printf("erreur");
    return 0;
    }
    do
    {
        caractereLu = fgetc(fichier);
        if(caractereLu=='\n') nombre_mots++;
    }while(caractereLu != EOF);
    //printf("Le nombre de mots dans le texte est %d\n", nombre_mots+1);
    motAleatoir = hazard(nombre_mots);
    //printf("Le numero du mot aleatoire tiree soit %d\n", motAleatoir+1);
    //printf("La position du curseur est %d\n", ftell(fichier));
    rewind(fichier);
    //printf("La position du curseur est %d\n", ftell(fichier));

    // NOW WE GO INTO THE WORD LINE
    while(motAleatoir>0)
    {
        caractereLu = fgetc(fichier);
        if(caractereLu=='\n') motAleatoir--;
    }
    //printf("La position du curseur est %d\n", ftell(fichier));
    fgets(chain, MAX_Taille, fichier);
    chain[strlen(chain)-1]='\0';
    //printf("le mot est %s\n", chain);
    chainlongue= strlen(chain);
    fclose(fichier);
    return chainlongue;
}
