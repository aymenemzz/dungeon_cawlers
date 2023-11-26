// C File standard
//--------------------------------------------------------------------------------
//  File main.c
// Date: 12 Nov 2023
//--------------------------------------------------------------------------------

#include "dungeon.h"

//--------------------------------------------------------------------------------

#define l 1// n est la largeur des couloirs, ici ils seront définis à 1, mais c'est tout a fait possible d'avoir une largeur personalisée
int main(){
    int check_response = 1;
    int option;
    a_dungeon current_dungeon = NULL;

    do {
        printf("BINEVENUE DANS LE DUNGEON CRAWLER CREATOR\n "
               "\nQue souhaitez vous faire ?\n"
               "\t1) Charger un donjon\n"
               "\t2) Creer un donjon\n"
               "\t3) Supprimer un donjon\n\n\n"
               "\t4) Quitter"
        );
        scanf("%c", &option);
        switch (option) {
            case (1):
                //REORIENT2 VERS LA FONCTION DE CHARGEMENT DES DONJONS
                //PAS PRETE
                break;
            case (2):
                current_dungeon = init_dungeon();
                break;
            case (3):
                //REORIENT2 VERS LA FONCTION DE SUPPRESSION DES DONJONS
                //PAS PRETE
                break;
            case (4):
                check_response = 0;
                break;
            default:
                printf("L'option choisis n'as pas ete reconnu ou n'est pas dans la selection veuillez réessayer");
                break;
        }
    } while (check_response != 0);

    return 0;
}

//--------------------------------------------------------------------------------
// end file
//--------------------------------------------------------------------------------
