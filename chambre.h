#ifndef CHAMBRE_H
#define CHAMBRE_H

typedef struct salle{

char **enceinte ;
int largeur;
int longueur;
int id_salle;
}salle;

typedef salle* a_salle;

a_salle creer_salle(int largeur, int longueur);

void affiche_salle(salle *s);

int sauvegarder_salle(salle *s);

a_salle recup_salle(char* nom_fichier);




#endif



