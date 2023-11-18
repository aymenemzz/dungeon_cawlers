#ifndef CHAMBRE_H
#define CHAMBRE_H

typedef struct s_salle
{
    char **enceinte ;
    int largeur;
    int longueur;
    int id_salle;
}salle;

typedef salle* a_salle;

a_salle init_salle(int largeur, int longueur);

void affiche_salle(salle *s);

void sauvegarder_salle(salle *s);




#endif



