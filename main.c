// C File standard
//--------------------------------------------------------------------------------
//  File main.c
// Date: 12 Nov 2023
//--------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "couloir.h"
#include "chambre.h"

//--------------------------------------------------------------------------------

#define l 1// n est la largeur des couloirs, ici ils seront définis à 1, mais c'est tout a fait possible d'avoir une largeur personalisée
int main(){

//couloir *c = malloc(sizeof(couloir));
//    if (c == NULL) {
//        printf("échec de l'allocation de mémoire");
//        return 1;
//    }
//
//init(c,2,"SSSSEEEESSSSS");
//affiche(c);
//free(c);

    int longueur = 6;
    int largeur = 28;
    a_salle la_salle = init_salle( longueur, largeur);

    affiche_salle(la_salle);

    return 0;
}

//--------------------------------------------------------------------------------
// end file
//--------------------------------------------------------------------------------