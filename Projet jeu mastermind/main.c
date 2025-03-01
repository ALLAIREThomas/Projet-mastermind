#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "save.h"


int main()
{
    color(15, 0);
    char jeu;
    while (jeu != '5') // Boucle while pour le menu principal et si le chiffre 5 est entrez, alors le jeux se ferme
    {
        jeu = afficherMenu();
        if (jeu == '3') // Affichage des règles du jeu
        {
            reglesDuJeu();
        }
        if (jeu == '4') // Demander les statistiques d'un joueur précis
        {
            char nomjoueur[250];
            printf("Quel joueur voulez vous voir ?\n");
            scanf("%s", nomjoueur);
            lirestatistique(nomjoueur);
        }
        if (jeu == '1') // Lancement d'une nouvelle partie
        {
            char nomjoueur[250];
            printf("Quel joueur joue ?\n");
            scanf(" %s", nomjoueur);
            if (lirestatistique(nomjoueur) == 0) // Création des statistiques d'un joueur s'elles n'existent pas
            {
                creerstat(nomjoueur);
            }
            char mode;
            char diff;
            mode = modejeu();
            if (mode == '1') // Le joueur doit deviner le code secret
            {
                diff = niveaudifficulte(); // Selection de la difficultée du jeu
                debutpartie();
                nouvellepartiejoueurordi(diff, nomjoueur);
            }
            if (mode == '2') // L'ordinateur doit deviner le codesecret du joueur
            {
                nouvellepartieordijoueur();
            }
        }
        if (jeu == '2') // Chargement d'une partie
        {
            char mode;
            mode = choixchargement();
            if (mode == '2') //Revisualisation d'une partie
            {
                char save[250];
                printf("Entrez la sauvegarde que vous voulez revoir.\n");
                scanf(" %s", save);
                revisualisation(save);
            }
            if (mode == '1') // Chargement d'une partie non finie
            {
                char save[250];
                printf("Entrez la sauvegarde que vous voulez charger. \n");
                scanf(" %s", save);
                chargementpartie(save);
            }
        }
    }
}
