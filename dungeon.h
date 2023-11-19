// Created by ay-93 on 10/11/2023.
#ifndef DUNGEON_CAWLERS_DUNGEON_H
#define DUNGEON_CAWLERS_ DUNGEON_H

#include <stdlib.h>
#include <stdio.h>


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

a_dungeon init_dungeon();
void free_dungeon_ram(a_dungeon this);
FILE* save_dungeon(a_dungeon this);

//AFFICHAGE D'UN DONJON------------------------
void print_dungeon(a_dungeon this);



#endif //DUNGEON_CAWLERS_DUNGEON_H
