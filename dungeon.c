//
// Created by ay-93 on 10/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dungeon.h"

//Variable statique pour maintenir le dernier identifiant attribué
static int dernierIdAttribue_dungeon = 0;

a_dungeon init_dungeon()
{
    // Allocation de la memoire pour le donjon
    a_dungeon the_dungeon = malloc(sizeof(t_dungeon));


    // initialisation des variable. Les variables commencant par "input_" sont destiner a recuperer des information de la part de l'utilisateur
    char input_height[3];
    char input_width[3];
    char input_name[11];

    int choosen_height;
    int choosen_width;
    const int id = dernierIdAttribue_dungeon++;



    // definition du nom, le fichier s'appellera "Dungeon_[id]-[input_name]
    printf("Vous avez choisis de creer un donjon !\n"
           "Quel nom souhaitez-vous lui donner ? (10 caractere maximum)\n"
           "name : ");
    fgets(input_name, 11, stdin);
    input_name[strcspn(input_name, "\n")] = '\0';
    snprintf(the_dungeon->name, TAILLE_NAME, "Dungeon_%d-%s", id, input_name);


    //demande de dimension
    printf("Entrez la hauteur souhaite pour votre donjon (maximum 99).\n"
           "Hauteur : ");
    fgets(input_height, 3, stdin);
    choosen_height = atoi(input_height);
    the_dungeon->height = choosen_height;


    printf("Entrez la hauteur souhaite pour votre donjon (maximum 99).\n"
           "Hauteur : ");
    fgets(input_width, 3, stdin);
    choosen_width = atoi(input_width);
    the_dungeon->width = choosen_width;

    // pour l'instant il n'y a riend dans le donjons donc on place les node container a NULL
    the_dungeon->contain = NULL;

    // afficher le donjon ?
    char response[5];
    int check = 1;
    do {
        printf("Voulez vous afficher votre donjon ? (Y/N)\n");
        fgets(response, 2, stdin);

        switch (response[0]) {
            case 'Y':
                print_dungeon(the_dungeon);
                check = 0;
                break;
            case 'N':
                printf("Vous avez choisis de ne pas afficher votre donjon\n");
                check = 0;
                break;
            default:
                printf("Votre reponse n'a pas ete reconnu veuillez reessayer");
                break;
        }
    } while (check == 0);
    return the_dungeon;
}
void free_dungeon_ram(a_dungeon this)
{
    free(this);
}
FILE* save_dungeon(a_dungeon this){

}


// affichage d'un donjon (doit etre present en memoire vive, l'extraction depuis les fichier se fais avec la fonction load_dungeon)
void print_dungeon(a_dungeon this)
{
    // d'abord il faut creer les murs exterieurs du donjon

    for(int i = 0; i < this->height; i++){
        for(int j = 0; j < this->width; j++){
            if (i == 0 || j == 0)
            {
                printf("#");
            }
            else if (i == this->height-1 || j == this->width-1)
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