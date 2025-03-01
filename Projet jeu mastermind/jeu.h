#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

//Affichage des différents menus

void color(int t,int f);

void reglesDuJeu();

char afficherMenu();

char niveaudifficulte();

char modejeu();

void debutpartie();

char choixchargement();

//Jeu version Joueur-Ordi

#define position 4

int verificationposition(char joueur1[position], char joeur2[position], int nbrcouleur, char niveaudifficulte);

int estDejaCompte(char compte[], char c);

char * estcouleur(char c);

int verificationcouleurbonne(char joueur[position], char joueur2[position], int nbrcouleur, char niveaudifficulte);

void codealeatoire(char code[position], char diff, int nbrcol);

int difftentative(char difficulte);

void affichercode(char code[position]);

void nouvellepartiejoueurordi(char difficulte, char nomjoueur[]);

//Jeu version Ordi-joueur

#define maxcombinaisons 2401

void allcombinaisons(char combinaisons[maxcombinaisons][position]);

typedef struct {
    int noir;
    int blanc;
} Feedback;

Feedback get_feedback(char combi[position], char code[position]);

int filtre_combinations(char combinations[maxcombinaisons][position], char combi[position], Feedback feedback, char filtrecombi[maxcombinaisons][position], int indice);

void nouvellepartieordijoueur();
