// Created by ay-93 on 10/11/2023.
#ifndef DUNGEON_CAWLERS_DUNGEON_H
#define DUNGEON_CAWLERS_ DUNGEON_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "couloir.h"
#include "chambre.h"

#define TAILLE_NAME 25


// creation des different type et structure utuilise


typedef enum e_typeElement {
    DUNGEON = 0,
    ROOM = 1,
    CORRIDOR = 2,
    ENTITY = 3
}t_typeElement;

typedef struct s_coordinate{
    int x;
    int y;
}t_coordinate;
typedef t_coordinate* a_coordinate;


typedef struct s_node{
    t_typeElement element;
    int id;
    a_coordinate coordinate;
    struct s_node* previous;
    struct s_node* next;
}t_node;
typedef t_node* a_node;


typedef struct s_dungeon {
    int height;
    int width;
    char name[TAILLE_NAME];
    a_node contain;
}t_dungeon;
typedef t_dungeon* a_dungeon;

// CREATION D'UN DONJON -----------------------
void init_dungeon();
void free_dungeon_ram(a_dungeon this);

// AJOUT DANS UN DONJON
void add_corridor(a_dungeon);
void add_room(a_dungeon);
void add_entrance_exit(a_dungeon);

// SAUVEGARDE D'UN DONJON DANS UN FICHIER .txt
FILE* save_dungeon(a_dungeon this);

//AFFICHAGE------------------------
void print_dungeon(a_dungeon this);
void print_list_dungeon();

// recuperation et affichage d'un donjon
FILE* load_dungeon_by_id();

#endif //DUNGEON_CAWLERS_DUNGEON_H
