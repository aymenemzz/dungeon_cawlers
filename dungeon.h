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
    char* name_of_file;
    a_coordinate coordinate;
    struct s_node* next;
}t_node;
typedef t_node* a_node;


typedef struct s_dungeon {
    int height;
    int width;
    int entrance;
    int exit;
    char name[TAILLE_NAME];
    a_node contain;
}t_dungeon;
typedef t_dungeon* a_dungeon;

// CREATION D'UN DONJON -----------------------
void init_dungeon();
a_node create_node(t_typeElement element, char* name_of_file, int x_coordinate, int y_coordinate);
void free_dungeon_ram(a_dungeon this);

// AJOUT DANS UN DONJON
void add_corridor(a_dungeon this);
void add_room(a_dungeon this);
void add_entrance_exit(a_dungeon this);
void add_node_to_contain(a_node);

// SAUVEGARDE D'UN DONJON DANS UN FICHIER .txt
void save_dungeon(a_dungeon this);
FILE* find_or_create_dungeon_file(a_dungeon this);
void general_write_on_dungeon(a_dungeon this, FILE* dungeon_file);
void node_write_on_dungeon(a_node this, FILE* dungeon_file);

//AFFICHAGE------------------------
void print_dungeon(a_dungeon this);
void print_list_dungeon();
void print_list_room();
void print_list_corridor();

// recuperation et affichage d'un donjon
FILE* load_dungeon_by_id();

#endif //DUNGEON_CAWLERS_DUNGEON_H
