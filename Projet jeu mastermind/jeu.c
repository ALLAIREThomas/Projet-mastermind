#include "jeu.h"
#include "save.h"

void color(int t,int f)
{
    //Fonction trouvé sur internet pour ajouter de la couleurs a la règle du jeu (t correspond a la couleur du texte et f à la couleur du fond de la console)
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}


void reglesDuJeu()
{
    // Renvoie les règles du jeu ci-dessous
    printf("Mastermind est un jeu de reflexion ou le but est de deviner une combinaison secrete de couleurs.\n");
    printf("Les differentes couleurs du Mastermind sont : le bleu, le rouge, le jaune, le vert, le orange, le violet et le blanc.\n");
    color(12, 0); printf("le rouge (r)");
    color(10, 0); printf(", le jaune (y)");
    color(2,0); printf(", le vert (g)");
    color(5,0); printf(", le violet (p)");
    color(6,0); printf(", le orange (o)");
    color(15,0); printf(", le blanc (w)");
    color(9,0); printf(" et le bleu (b).\n");
    color (15, 0);
    printf("Chaque essai vous donne des indices pour vous rapprocher de la solution.\n");
    printf("Selon le niveau de difficulte, il y a aura plus ou moins d'indices.\n");
    printf("Pour plus d'information vous pouvez vous rendre sur ce site : https://fr.wikipedia.org/wiki/Mastermind.\n");
    printf("Appuyez sur enter pour revenir au menu principal.\n");
    getchar();  // Pour capturer le retour à la ligne après le choix
    getchar();  // Pour attendre l'appui d'une touche
    system("cls"); //Permet de supprimer toutes les lignes de la console
}


char afficherMenu()
{
    // Affiche le menu au début de la partie et les différents choix possibles
    char jeu;
    while (1)   //Faire une boucle infini permet d'afficher le menu en permanence même si le charactère jeu est différent de 1, 2, 3, 4, ou 5
    {
        printf("\n----- MENU PRINCIPAL -----\n");
        printf("1  Nouvelle Partie\n");
        printf("2  Charger Partie\n");
        printf("3  Regles du Jeu\n");
        printf("4  Statistiques\n");
        printf("5  Quitter\n");
        scanf(" %c", &jeu);
        system("cls");
        if (jeu == '1')
        {
            printf("----- Nouvelle Partie -----\n");
            return jeu;
        }
        if (jeu == '2')
        {
            printf("----- Chargement Partie -----\n");
            return jeu;
        }
        if (jeu == '3')
        {
            printf("----- Regles du jeu -----\n");
            return jeu;
        }
        if (jeu == '4')
        {
            printf("----- Statistiques -----\n");
            return jeu;
        }
        if (jeu == '5')
        {
            printf("----- A plus tard -----\n");
            return jeu;
        }
        else
        {
            printf("Reessayer ! \n");
        }
    }
}

char niveaudifficulte()
{
    //Permet de choisir une difficulté par rapport au nombre d'essais, et à la complexité du code couleur
    char diff;
    while (1)
    {
        printf("Choisissez la difficulte: \n");
        printf("1  Facile\n");
        printf("2  Normal\n");
        printf("3  Difficile\n");
        scanf(" %c", &diff);
        if (diff == '1')
        {
            printf("----- Difficulte facile -----\n");
            return diff;
        }
        if (diff == '2')
        {
            printf("----- Difficulte Normale -----\n");
            return diff;
        }
        if (diff == '3')
        {
            printf("----- Difficulte Difficile -----\n");
            return diff;
        }
        else
        {
            system("cls");
            printf("Mauvais choix de difficulte\n");
        }
    }
}

char modejeu()
{
    // Permet de choisir entre 2 modes de jeu
    char jeu = 0;
    while (1)
    {
        printf("Choisissez votre mode de jeu :\n");
        printf("1  Deviner le code de l'ordinateur\n");
        printf("2  L'ordinateur devine le code\n");
        scanf(" %c", &jeu);
        system("cls");
        if (jeu == '1')
        {
            printf("------    Vous avez choisi de deviner le code de l'ordinateur.    -----\n");
            return jeu;
        }
        if (jeu == '2')
        {
            printf("-----    L'ordinateur va deviner votre code.    -----\n");
            return jeu;
        }
        else
        {
            printf("Reessayer\n");
        }
    }
}

void debutpartie()
{
    printf("Commencons la partie \n");
    printf("Pour que l'experience soit rapide, notez les couleurs comme ceci : \n");
    color(12, 0); printf("-Rouge : r\n");
    color(14, 0); printf("-Jaune : y\n");
    color(2,0); printf("-Vert : g\n");
    color(5,0); printf("-Violet : p\n");
    color(6,0); printf("-Orange : o\n");
    color(15,0); printf("-Blanc : w\n");
    color(9,0); printf("-Bleu : b\n");
    color (15, 0);
    printf("Pour quitter a tout moment le jeu ecrivez stop.\n");
    printf("C'est parti ! \n");
}

char choixchargement()
{
    char mode;
    while (1)
    {
        printf("Choisissez un menu :\n");
        printf("1  Charger une partie\n");
        printf("2  Revisualiser une partie\n");
        scanf(" %c", &mode);
        system("cls");
        if (mode == '1')
        {
            printf("------    Vous avez choisi de charger une partie.    -----\n");
            return mode;
        }
        if (mode == '2')
        {
            printf("------    Vous avez choisi de revisualiser une partie.    -----\n");
            return mode;
        }
        else
        {
            printf("Reesayer");
        }
    }
}


        /* Définition des fonctions joueur - ordi */




int verificationposition(char joueur1[], char joueur2[], int nbrcouleur, char niveaudifficulte)
{
    int verif = 0;
    int compt=0;
    for (int i=0;i<nbrcouleur;i++)  //La boucle permet de connaître le nombre de couleurs bonne qui sont au bon endroit
    {
        if (joueur1[i] == joueur2[i])
        {
            compt++;
        }
    }
    if (compt == nbrcouleur)    //Si il y a autant de couleurs bonnes bien placé que le nombre couleurs à deviner, alors on renvoie 1 qui correspond
    {                           //au fait que le joueur ait trouvé la bonne combinaison
        return 1;
    }
    if (niveaudifficulte == '1')    //Selon la difficulte, le code affichera différents indices
    {
        for (int i=0; i<nbrcouleur; i++)
        {
            if (joueur1[i] != joueur2[i])   //Fait en sorte d'afficher si la couleur est à la bonne place pour la difficulte facile
            {
                printf("La couleur a la place %d n'est pas la bonne \n", i+1);
            }
            else
            {
                printf("La couleur a la place %d est la bonne couleur \n", i+1);
            }
        }
    }
    else
    {
        int i=0;
        int compteurmauvais=0;
        int compteurbon=0;
        while (i<nbrcouleur)
        {
            if (joueur1[i] != joueur2[i])   //Compte le nombre de couleurs qui ne sont pas bien placé
            {
                compteurmauvais++;
                verif=0;
            }
            else    //Compte le nombre de couleurs qui sont bien placé
            {
                compteurbon++;
            }
            i++;
        }
        printf("Il y a %d couleurs mal place et %d couleurs bien place. \n", compteurmauvais, compteurbon); //Affiche les couleurs bien et mal placé pour la difficulté normale et difficile
    }
    return verif;
}


int estDejaCompte(char compte[], char c)    //La fonction vérifie si le caractère c est dans la liste compte
{
    for (int i = 0; i<16; i++)
    {
        if (compte[i] == c)
        {
            return 1;
        }
    }
    return 0;
}

char * estcouleur(char c)
{
    // Retourne la bonne couleur selon le charactère entrée en argument
    if (c == 'r')
    {
        return "rouge";
    }
    if (c == 'g')
    {
        return "vert";
    }
    if (c == 'b')
    {
        return "bleu";
    }
    if (c == 'y')
    {
        return "jaune";
    }
    if (c == 'p')
    {
        return "violet";
    }
    if (c == 'w')
    {
        return "blanc";
    }
    if (c == 'o')
    {
        return "orange";
    }
}

int verificationcouleurbonne(char joueur1[], char joueur2[], int nbrcouleur, char niveaudifficulte)
{
    //Renvoie le nombre de bonne couleur et affiche des indices selon le niveau de difficulté
    char dejaCompte[4] = "";
    int compteur = 0;
    for (int i = 0; i<nbrcouleur; i++) //Boucle permetant de connaitre le nombre de bonne couleurs
    {
        for (int j = 0; j<nbrcouleur; j++)
        {
            if (joueur1[i] == joueur2[j])
            {
                if (!estDejaCompte(dejaCompte, joueur1[i])) {
                    dejaCompte[compteur++] = joueur1[i];
                }
                break;
            }
        }
    }
    if (niveaudifficulte == '1' || niveaudifficulte == '2') // permet de donner les indices nécéssaires au joueurs en fonction de la difficulté choisie
    {
        printf("Il y a %d couleurs de bonnes.\n", compteur);
    }
    if (niveaudifficulte == '1' && compteur != 0)
    {
        printf("Les couleurs correctes sont : \n");
        for (int i=0; i<compteur; i++)
        {
            printf("%s ", estcouleur(dejaCompte[i]));
        }
    }
    printf("\n");
    return compteur;
}

void codealeatoire(char code[4], char diff, int nbrcol)
{
    // fonction génératrice d'un code couleur aléatoire
    srand(time(NULL)); // réinitialise la valeur aléatoire
    char couleurs[7] = {'r', 'y', 'g', 'o', 'w', 'p', 'b'};
    int indices[7] = {0, 1, 2, 3, 4, 5, 6};
    int max = 7;
    int alea;
    if(diff == '1' || diff == '2')
    {
        for (int i = 0; i < nbrcol; i++)
        {
            alea = rand() % max;
            code[i] = couleurs[indices[alea]];
            indices[alea] = indices[max - 1]; // permet de supprimer la couleur pour évité la répétition d'une couleur dans le code
            max--;
        }
    }
    else
    {
        for (int i = 0; i < nbrcol; i++)
        {
            alea = rand() % max;
            code[i] = couleurs[alea]; // pour la difficulté la plus dure, ce code permet d'obtenir plus fois la même couleur dans le code
        }
    }
}

int difftentative(char difficulte)
{
    // Renvoie le nombre de tentative maximale en fonction de la difficulté mise en argument
    int tentativemax;
    if (difficulte == '1')
    {
        tentativemax = 12;
    }
    else if (difficulte == '2')
    {
        tentativemax = 10;
    }
    else if (difficulte == '3')
    {
        tentativemax = 8;
    }
    return tentativemax;
}

void affichercode(char code[position])
{
    for(int g=0; g<4; g++)
    {
        printf("%c - ", code[g]);
    }
}

void nouvellepartiejoueurordi(char difficulte, char nomjoueur[])
{
    // déroulement de la partie en fonction des fonctions ci-dessus
    printf("Entrez le nom de votre sauvegarde :\n");
    char save[100];
    scanf("%s",save);
    int nbrcouleur = 4;
    char ordi[5];
    codealeatoire(ordi, difficulte, nbrcouleur); //créer le code aléatoire de la partie
    char joueur[5];
    creersave(save,ordi,nbrcouleur, difficulte);
    int verif = 0;
    int tentativemax = difftentative(difficulte);
    int tentative = 1;
    time_t debut, fin;
    // initialisation du chronomètre pour les statistiques du temps
    time(&debut);
    while (verif != 1 && tentative <= tentativemax)
    {
        printf("Tentative numero : %d\n", tentative);
        printf("Entrez votre code : \n");
        scanf("%s", joueur);
        if (joueur[0] == 's' && joueur[1] == 't' && joueur[2] == 'o' && joueur[3] == 'p')
        {
            time(&fin);
            return;
        }
        int couleur = verificationcouleurbonne(joueur, ordi, 4, difficulte);
        verif = verificationposition(joueur, ordi, 4, difficulte);
        modifsave(save, joueur, couleur, 4, tentative);
        tentative++;
    }
    // fin du chronomètre et calcul du temps
    time(&fin);
    double tempstot = difftime(fin, debut);
    int vicdef;
    if (tentative > tentativemax)
    {
        printf("Vous avez perdu ! Le code secret était :\n");
        affichercode(ordi);
        printf("\n");
        vicdef = 0;
    }
    if (tentative <= tentativemax)
    {
        printf("Bravo vous avez trouve !\n");
        vicdef = 1;
    }
    modifstatistique(nomjoueur, vicdef, tempstot, tentative);
    finsave(save);
    printf("Appuyez sur enter pour revenir au menu principal.\n");
    getchar();
    getchar();
    system("cls");
}




/*  Definition des fonctions Ordi - Joueur */




void allcombinaisons(char combinaisons[maxcombinaisons][position])
{
    // génère toute les combinaisons possible du code couleur
    char couleurs[8] = {'r', 'y', 'g', 'o', 'w', 'p', 'b'};
    int x = 0;
    for (int i = 0; i<7; i++)
    {
        for (int j = 0; j<7; j++)
        {
            for (int k = 0; k<7; k++)
            {
                for (int l = 0; l<7; l++)
                {
                    combinaisons[x][0] = couleurs[i];
                    combinaisons[x][1] = couleurs[j];
                    combinaisons[x][2] = couleurs[k];
                    combinaisons[x][3] = couleurs[l];
                    x++;
                }
            }
        }
    }
}

Feedback get_feedback(char combi[position], char code[position])
{
    Feedback fb = {0, 0};
    // liste des couleurs {r, g, b, p, w, y, o}
    int combi_count[7] = {0, 0, 0, 0, 0, 0, 0};
    int code_count[7] = {0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < position; i++)
    {
        if (combi[i] == code[i])
        {
            fb.noir++;
        }
        else
        {
            if (combi[i] == 'r')
            {
                combi_count[0]++;
            }
            if (combi[i] == 'g')
            {
                combi_count[1]++;
            }
            if (combi[i] == 'b')
            {
                combi_count[2]++;
            }
            if (combi[i] == 'p')
            {
                combi_count[3]++;
            }
            if (combi[i] == 'w')
            {
                combi_count[4]++;
            }
            if (combi[i] == 'y')
            {
                combi_count[5]++;
            }
            if (combi[i] == 'o')
            {
                combi_count[6]++;
            }
            if (code[i] == 'r')
            {
                code_count[0]++;
            }
            if (code[i] == 'g')
            {
                code_count[1]++;
            }
            if (code[i] == 'b')
            {
                code_count[2]++;
            }
            if (code[i] == 'p')
            {
                code_count[3]++;
            }
            if (code[i] == 'w')
            {
                code_count[4]++;
            }
            if (code[i] == 'y')
            {
                code_count[5]++;
            }
            if (code[i] == 'o')
            {
                code_count[6]++;
            }
        }
    }
    for (int i = 1; i < 7; i++)
        {
        if (combi_count[i] < code_count[i])
        {
            fb.blanc += combi_count[i];
        }
        else
        {
            fb.blanc += code_count[i];
        }
    }

    return fb;
}

int filtre_combinations(char combinations[maxcombinaisons][position], char combi[position], Feedback feedback, char filtrecombi[maxcombinaisons][position], int indice)
{
    int maxind = 0;
    for (int i = 0; i < indice; i++)
    {
        char temp[4] = {combinations[i][0], combinations[i][1], combinations[i][2], combinations[i][3]};
        Feedback fb = get_feedback(combi, temp);
        if (fb.noir == feedback.noir && fb.blanc == feedback.blanc)
        {
            filtrecombi[maxind][0] = temp[0];
            filtrecombi[maxind][1] = temp[1];
            filtrecombi[maxind][2] = temp[2];
            filtrecombi[maxind][3] = temp[3];
            maxind++;
        }
    }
    return maxind;
}

void couleurpossible()
{
    printf("Entrez les couleurs suivantes :\n");
    color(12, 0); printf("le rouge (r)");
    color(10, 0); printf(", le jaune (y)");
    color(2,0); printf(", le vert (g)");
    color(5,0); printf(", le violet (p)");
    color(6,0); printf(", le orange (o)");
    color(15,0); printf(", le blanc (w)");
    color(9,0); printf(" et le bleu (b).\n");
    color (15, 0);
}

void nouvellepartieordijoueur()
{
    // code du jeu du de l'ordi contre le joueur en fonction des fonctions définis ci-dessus
    char code[4];
    printf("Quelle est le code que vous souhaiter faire deviner ?\n");
    couleurpossible();
    scanf("%s", code);
    printf("L'ordinateur commence a trouver votre code (Il a 10 essais max pour trouver le code sinon il a perdu).\n");
    int nbressai = 1;
    char essai[position] = "rrgg";
    char toutecombi[maxcombinaisons][position];
    allcombinaisons(toutecombi);
    int maxind = maxcombinaisons;
    while (1)
    {
        if (nbressai > 10)
        {
            printf("Perdu");
            break;
        }
        printf("Essai %d :", nbressai);
        affichercode(essai); printf("\n");
        Feedback feedback = get_feedback(essai, code);
        printf("Il y a %d bonnes couleurs bien place et %d bonnes couleurs mal place. \n", feedback.noir, feedback.blanc);
        if (feedback.noir == position)
        {
            printf("\nL'ordinateur a trouve en %d essais !\n", nbressai);
            break;
        }
        char filtrecombi[maxcombinaisons][position];
        maxind = filtre_combinations(toutecombi, essai, feedback, filtrecombi, maxind);
        memcpy(toutecombi, filtrecombi, maxcombinaisons * position * sizeof(char));
        memcpy(essai, toutecombi[0], position * sizeof(char));
        nbressai++;
    }
    printf("Appuyez sur enter pour revenir au menu principal.\n");
    getchar();
    getchar();
    system("cls");
}
