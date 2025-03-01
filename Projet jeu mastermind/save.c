#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "save.h"
#include "jeu.h"

// Fonctions de gestion des sauvegardes pour le jeu Mastermind

void creersave(char nom[], char code[], int nbrcouleur, char difficulte)
{
    // Crée un fichier de sauvegarde avec le nom donné
    FILE * save = fopen(nom, "w");
    if (save == NULL) // En cas d'échec d'ouverture, affiche un message d'erreur et quitte
    {
        printf("Erreur d'ouverture de sauvegarde");
        return;
    }
    // Écrit les informations initiales
    fprintf(save,"Nouvelle Partie \n");
    fprintf(save,"Difficulte : %c \n", difficulte);
    fprintf(save,"Code secret : ");
    // Ajoute chaque caractère du code secret
    for (int i=0; i<nbrcouleur; i++)
    {
        fprintf(save, "%c", code[i]);
    }
    fprintf(save, "\n");
    fclose(save);
}

void modifsave(char nom[], char joueur[], int couleurbonne, int nbrcouleur, int tentative)
{
    // Ouvre le fichier de sauvegarde
    FILE * save = fopen(nom, "a");
    fprintf(save, "Tentative %d : ",tentative);
    for (int i=0; i<nbrcouleur; i++) // Enregistre le code proposé par le joueur
    {
        fprintf(save, "%c", joueur[i]);
    }
    fprintf(save, " dont %d couleurs bonnes", couleurbonne);
    fprintf(save, "\n");
    fclose(save);
}

void finsave(char nom[])
{
    // Ajoute une ligne indiquant la fin de la partie
    FILE * save = fopen(nom, "a");
    fprintf(save,"FIN");
    fclose(save);
}

void revisualisation(char nom[])
{
    // Permet de lire et afficher le contenu d'une sauvegarde
    FILE *save = fopen(nom, "r");
    if (save == NULL)
    {
        printf("Aucune sauvegarde trouvee.\n");
        return;
    }
    char ligne[1000]; char code[1000];
    int CptTentative = 0;
    printf("\n-----    Revisualisation de la Partie    -----\n");
    while (fgets(ligne, sizeof(ligne), save))
    {
        // affiche les tentatives enregistrées
        if (strstr(ligne, "Code secret") != NULL)
        {
            memcpy(code, ligne, 1000 * sizeof(char)); // Sauvegarde le code secret
        }
        if (strstr(ligne, "Tentative") != NULL)
        {
            printf("%s", ligne);
            CptTentative++;
        }
    }
    // Affiche le résumé final
    if (CptTentative == 0)
    {
        printf("Aucune tentative enregistree.\n");
    }
    if (ligne[0] == 'F')
    {
        printf("La partie est terminee, voici le %s\n", code);
    }
    if (ligne[0] != 'F')
    {
        printf("La partie n'est pas terminee, essayer de la terminee pour voir le code secret.\n");
    }
    fclose(save);
}

void chargementpartie(char nom[])
{
    // Charge une partie depuis un fichier de sauvegarde
    FILE *save = fopen(nom, "r");
    if (save == NULL)
    {
        printf("Aucune sauvegarde trouvee.\n");
        return;
    }
    char ligne[1000]; char code[5];
    int tentative = 0; char difficulte;
    while (fgets(ligne, sizeof(ligne), save))
    {
        // Récupère le code secret et la difficulté
        if (strstr(ligne, "Code secret") != NULL)
        {
            code[0] = ligne[14];
            code[1] = ligne[15];
            code[2] = ligne[16];
            code[3] = ligne[17];
        }
        if (strstr(ligne, "Difficulte") != NULL)
        {
            difficulte = ligne[13];
        }
        if (strstr(ligne, "Tentative") != NULL)
        {
            printf("%s", ligne);
            tentative++;
        }
    }
    if (ligne[0] == 'F')
    {
        // Si la partie est terminée, affiche le code secret
        printf("La partie est terminee voici le code secret : %s \n", code);
        return;
    }
    // Reprend la partie
    debutpartie();
    char joueur[5];
    int verif = 0;
    int tentativemax = difftentative(difficulte);
    while (verif != 1 && tentative <= tentativemax)
    {
        printf("Tentative numero : %d\n", tentative);
        printf("Entrez votre code : \n");
        scanf("%s", joueur);
        if (joueur[0] == 's' && joueur[1] == 't' && joueur[2] == 'o' && joueur[3] == 'p')
        {
            return;
        }
        int couleur = verificationcouleurbonne(joueur, code, 4, difficulte);
        verif = verificationposition(joueur, code, 4, difficulte);
        modifsave(nom, joueur, couleur, 4, tentative);
        tentative++;
    }
    if (tentative > tentativemax)
    {
        printf("Vous avez perdu ! Le code secret était :\n");
        affichercode(code);
        finsave(nom);
        return;
    }
    printf("Bravo vous avez trouve !\n");
    finsave(nom);
    printf("Appuyez sur enter pour revenir au menu principal.\n");
    getchar();  // Pour capturer le retour à la ligne après le choix
    getchar();  // Pour attendre l'appui d'une touche
    system("cls");
}

int lirestatistique(char * nom)
{
    // Lit et affiche les statistiques d'un joueur
    char statistique[200] = "statistique";
    strcat(statistique, nom);
    FILE * stat = fopen(statistique,"r");
    if (stat == NULL)
    {
        fclose(stat);
        return 0;
    }
    char ligne[1000];
    while (fgets(ligne, 1000, stat) != NULL)
    {
        printf("%s", ligne);
    }
    fclose(stat);
    return 1;
}

void creerstat(char nom[])
{
    // Crée un fichier de statistiques pour un joueur
    char statistique[100] = "statistique";
    strcat(statistique, nom);
    FILE * stat = fopen(statistique, "w");
    fprintf(stat, "Nom : %s \n", nom);
    //Initialise toutes les variables à 0
    int victoire = 0; int defaite = 0; double temps = 0.0; double tentative = 0.0;
    fprintf(stat, "Victoire : %d \n", victoire);
    fprintf(stat, "Defaite : %d \n", defaite);
    fprintf(stat, "Temps moyen : %lf \n", temps);
    fprintf(stat, "Nombre de tentatives moyennes : %lf \n", tentative);
    fclose(stat);
}

stats retour(char nom[])
{
    // Retourne les statistiques d'un joueur
    stats stati;
    char statistique[200] = "statistique";
    strcat(statistique, nom);
    FILE * stat = fopen(statistique, "r");
    char ligne[1000];
    while (fgets(ligne, 1000, stat) != NULL)
    {
        if (strstr(ligne, "Victoire") != NULL)
        {
            stati.victoire = ligne[11] - '0'; //Recupere l'information l'entier sous sa forme ascii et pour avoir l'entier d'origine on enleve '0'
        }
        if (strstr(ligne, "Defaite") != NULL)
        {
            stati.defaite = ligne[10] - '0';
        }
        if (strstr(ligne, "Temps") != NULL)
        {
            fscanf(stat, "%lf", &stati.tentativemoy); //Copie un float sur la mémoire de stati.tentativemoy
        }
        if (strstr(ligne, "tentatives") != NULL)
        {
            fscanf(stat, "%lf", &stati.tentativemoy);
        }
    }
    fclose(stat);
    return stati;
}

void modifstatistique(char nom[], int vicdef, double temps, double tentative)
{
    // Modifie les statistiques d'un joueur
    char statistique[200] = "statistique";
    strcat(statistique, nom);
    //Recupère les informations du joueur mit en argument si il y en a
    FILE * stat = fopen(statistique,"r");
    if (stat == NULL)
    {
        printf("Il n'y a pas encore de statistique sur ce joueur.\n Commencez une partie pour avoir des statistique.\n");
        fclose(stat);
        return;
    }
    fclose(stat);
    stats ret = retour(nom);
    //Réécrie les statistiques modifié du joueur mit en argument
    FILE * stat2 = fopen(statistique, "w");
    fprintf(stat2, "Nom : %s \n", nom);
    int victoire = ret.victoire; int defaite = ret.defaite;
    int tot = victoire + defaite;
    if (vicdef == 1)
    {
        victoire++;
    }
    if (vicdef == 0)
    {
        defaite++;
    }
    float tpsmoy = (tot*ret.tempsmoy + temps)/(victoire + defaite) ;
    float tentativemoy = (tot*ret.tentativemoy + tentative)/(victoire + defaite);
    fprintf(stat2, "Victoire : %d \n", victoire);
    fprintf(stat2, "Defaite : %d \n", defaite);
    fprintf(stat2, "Temps moyen : %lf \n", tpsmoy);
    fprintf(stat2, "Nombre de tentatives moyennes : %lf \n", tentativemoy);
    fclose(stat2);
}

