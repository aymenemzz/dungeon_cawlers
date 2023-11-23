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
#include "dungeon.h"
#include <time.h>

//--------------------------------------------------------------------------------

#define l 1// n est la largeur des couloirs, ici ils seront définis à 1, mais c'est tout a fait possible d'avoir une largeur personalisée
int main(){
    int check_response = 1;
    char response[5];
    a_dungeon current_dungeon = NULL;

    do {
        printf("BINEVENUE DANS LE DUNGEON CRAWLER CREATOR\n "
               "\nQue souhaitez vous faire ?\n"
               "    - Charger un donjon (L)\n"
               "    - Creer un donjon (C)\n"
               "    - Supprimer un donjon (D)\n"
        );
        fgets(response, 2, stdin);
        switch (response[0]) {
            case ('L'):
                //REORIENT2 VERS LA FONCTION DE CHARGEMENT DES DONJONS
                //PAS PRETE
                check_response = 0;
                break;
            case ('C'):
                current_dungeon = init_dungeon();
                check_response = 0;
                break;
            case ('D'):
                //REORIENT2 VERS LA FONCTION DE SUPPRESSION DES DONJONS
                //PAS PRETE
                check_response = 0;
                break;
            default:
                printf("Le caractere n'as pas ete reconnu ou n'est pas dans la selection veuillez réessayer");

        }
    } while (check_response != 0);

    return 0;
}

//--------------------------------------------------------------------------------
// end file
//--------------------------------------------------------------------------------
