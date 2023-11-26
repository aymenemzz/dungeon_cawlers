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


    // demande d'ajout de l'entree et de la sortie
    add_entrance_exit(the_dungeon);


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
        scanf("%d", &option);
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
                if (i == this->entrance)
                {
                    printf("E");
                }
                else if (i == this->exit)
                {
                    printf("X");
                }
                else {
                    printf("#");
                }
            }
            else
            {
                printf(" ");
            }
        }
    }
}


// SAVE PARTS
void save_dungeon(a_dungeon this)
{
    FILE* dungeon_file = find_or_create_dungeon_file(this);
    if(dungeon_file == NULL)
    {
        printf("Impossible d'enregistrer votre donjon !");
        return;
    }

    general_write_on_dungeon(this, dungeon_file);
    fclose(dungeon_file);
}

FILE* find_or_create_dungeon_file(a_dungeon this)
{
    FILE* fichier = NULL;
    char name_with_extension[2*TAILLE_NAME];
    snprintf(name_with_extension, 2*TAILLE_NAME, "dungeon/%s.txt", this->name);
    fichier = fopen(name_with_extension, "w+");

    if (fichier == NULL)
    {
        printf("Impossible d'ouvrir ou de creer le fichier");
        return NULL;
    }
    else
    {
        return fichier;
    }
}

void general_write_on_dungeon(a_dungeon this, FILE* dungeon_file)
{
    fprintf(dungeon_file, "%d >> id\n"
                          "%d >> width\n"
                          "%d >> height\n\n"
                          "%d >> entrance\n"
                          "%d >> exit\n\n"
    );
    node_write_on_dungeon(this->contain, dungeon_file);

}
void node_write_on_dungeon(a_node this, FILE* dungeon_file)
{
    if(this->next == NULL)
    {
        fprintf(dungeon_file, "%d - %d %s\n",this->coordinate->x, this->coordinate->y, this->name_of_file);
        return;
    }
    else
    {
        node_write_on_dungeon(this->next, dungeon_file);
        fprintf(dungeon_file, "%d - %d %s\n",this->coordinate->x, this->coordinate->y, this->name_of_file);

    }
}

//ADD PARTS

void add_entrance_exit(a_dungeon this)
{
    printf("Veuillez saisir la coordonée X a laquelle vous souhaitez placer l'entrée de votre donjon (en commencant par 0)");
    scanf("%d", &this->entrance);
    printf("Veuillez saisir la coordonée X a laquelle vous souhaitez placer la sortie de votre donjon (en commencant par 0)");
    scanf("%d", &this->exit);
}




