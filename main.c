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
#include <time.h>

//--------------------------------------------------------------------------------

#define l 1// n est la largeur des couloirs, ici ils seront définis à 1, mais c'est tout a fait possible d'avoir une largeur personalisée
int main(){

a_salle s1 = creer_salle(10,22);
affiche_salle(s1);
sauvegarder_salle(s1);

/*
a_salle s2 = creer_salle(43,16);
affiche_salle(s2);
sauvegarder_salle(s2);

a_couloir c1 = creer_couloir(2,"SSSSSEEEESSS");
affiche_couloir(c1);
sauvegarder_couloir(c1);

a_couloir c2 = creer_couloir(2,"NNNNNNNWWWWW");
affiche_couloir(c2);
sauvegarder_couloir(c2);*/

a_salle s3 = recup_salle("chambres/salle1.txt");
//printf("%d\n%d\n",s3->largeur,s3->longueur);
affiche_salle(s3);
sauvegarder_salle(s3);
printf("%d\n",s3->id_salle);
//free(c1);
//free(s2);
free(s3);
free(s1);
return 0;
}

//--------------------------------------------------------------------------------
// end file
//--------------------------------------------------------------------------------
