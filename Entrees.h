#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Signs.h"

// FONCTION LIRE SECURSER-------------------------------------------------------------------------------------------------
int lire(char *chaine, int longueur)
{
    char *position = NULL;
    if(fgets(chaine, longueur, stdin) != NULL)
    {
        position = strchr(chaine, '\n');
        if(position != NULL)
            *position = '\0';
        else
            viderbuffer();

        return 1;
    }
    else
    {
        viderbuffer();
        return 0;
    }
}
//************************************************************************************************************************
// FONCTIONS D'AIDE-------------------------------------------------------------------------------------------------------
void viderbuffer(void)
{
    int c=0;
    while(c!='\n' && c!=EOF) c=getchar();
}
