#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Création et modification des sauvegardes

void creersave(char nom[], char joueur2[], int nbrcouleur, char difficulte);

void modifsave(char nom[], char joueur1[],int couleurbonne, int nbrcouleur, int tentative);

void finsave(char nom[]);

//Chargement et revisualisation des parties

void revisualisation(char nom[]);

void chargementpartie(char nom[]);

//Statistiques des joueurs

int lirestatistique(char * nom);

void creerstat(char nom[]);

typedef struct {
    int victoire;
    int defaite;
    double tentativemoy;
    double tempsmoy;
} stats;

stats retour(char nom[]);

void modifstatistique(char nom[], int vicdef, double temps, double tentative);
