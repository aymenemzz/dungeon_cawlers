//
// Created by ay-93 on 10/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dungeon.h"

//Variable statique pour maintenir le dernier identifiant attribué
static int dernierIdAttribue_dungeon = 0;

void init_dungeon()
{
    // Allocation de la memoire pour le donjon
    a_dungeon the_dungeon = malloc(sizeof(t_dungeon));


    // initialisation des variable. Les variables commencant par "input_" sont destiner a recuperer des information de la part de l'utilisateur
    int input_height;
    int input_width;
    char input_name[11];

    const int id = dernierIdAttribue_dungeon++;



    // definition du nom, le fichier s'appellera "Dungeon_[id]-[input_name]
    printf("Vous avez choisi de creer un donjon !\n"
           "Quel nom souhaitez-vous lui donner ? (10 caractere maximum)\n"
           "name : ");
    scanf("%s", input_name);
    snprintf(the_dungeon->name, TAILLE_NAME, "Dungeon_%d-%s", id, input_name);


    //demande de dimension
    printf("\nEntrez la hauteur souhaite pour votre donjon (maximum 99).\n"
           "Hauteur : ");
    scanf("%d", &input_height);
    the_dungeon->height = input_height;


    printf("\nEntrez la hauteur souhaite pour votre donjon (maximum 99).\n"
           "Hauteur : ");
    scanf("%d", &input_width);
    the_dungeon->width = input_width;

    // pour l'instant il n'y a riend dans le donjons donc on place les node container a NULL
    the_dungeon->contain = NULL;

    //appelle de la fonction pour afficher le donjons
    print_dungeon(the_dungeon);

    // Ouverture vers les autres fonction
    int option;
    int quit = 1;
    do {

        printf("/!\\ VOTRE DONJON N'EST PAS ENREGISTRE /!\\ \n "
               "Que souhaitez-vous faire avec votre donjon ?\n"
               "\t1)Enregistrer le donjon %s\n"
               "\t2)Ajouter une salle\n"
               "\t3)Ajouter un couloir\n"
               "\t4)Ajouter l'entrée et la sortie\n\n\n"
               "\t5)Quitter", the_dungeon->name
        );
        switch (option) {
            case 1:
                save_dungeon(the_dungeon);
                break;
            case 2:
                add_room(the_dungeon);
                //PAS PRET
                break;
            case 3:
                add_corridor(the_dungeon);
                //PAS PRET
                break;
            case 4:
                add_entrance_exit(the_dungeon);
            case 5:
                quit = 0;
                break;
            default:
                printf("L'option choisis n'est pas reconnu ou n'est pas dans la selection. Veuillez réessayer !");
                break;
        }
    }while (quit != 0);
}

void free_dungeon_ram(a_dungeon this)
{
    free(this);
}


// PRINT PARTS
// affichage d'un donjon (doit etre present en memoire vive, l'extraction depuis les fichier se fais avec la fonction load_dungeon)
void print_dungeon(a_dungeon this)
{
    // d'abord il faut creer les murs exterieurs du donjon

    for(int i = 0; i < this->height; i++){
        for(int j = 0; j < this->width; j++){
            if (j == this->width-1)
            {
                printf("#\n");
            }
            else if (i == 0 || j == 0 || i == this->height-1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
    }
}


// SAVE PARTS

FILE* save_dungeon(a_dungeon this){

}





