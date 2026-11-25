#include <stdio.h>

// ==========================================
// PROTOTYPES DES FONCTIONS
// ==========================================
void bonjour();
int produit(int a, int b);
int min2(int a, int b);
int min4(int a, int b, int c, int d);
void dessinerSapin(int etages);
void dessinerSapinBonus(int etages);

// ==========================================
// PROGRAMME PRINCIPAL (AVEC SÉLECTEUR)
// ==========================================
int main()
{
    int choix;

    do {
        printf("\n========================================\n");
        printf("        MENU - TP4 FONCTIONS EN C       \n");
        printf("========================================\n");
        printf("1. Exercice 1 : Fonction bonjour\n");
        printf("2. Exercice 2 : Produit de deux entiers\n");
        printf("3. Exercice 3 : Minimum de 2 entiers (min2)\n");
        printf("4. Exercice 4 : Minimum de 4 entiers (min4)\n");
        printf("5. Exercice 5 : Sapin de Noel (ASCII Art)\n");
        printf("6. Exercice 5 (Bonus) : Sapin avec grande etoile et boules\n");
        printf("0. Quitter le programme\n");
        printf("----------------------------------------\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        printf("\n");

        switch (choix) {
            case 1: {
                bonjour();
                break;
            }

            case 2: {
                int x, y;
                printf("Entrez le premier entier : ");
                scanf("%d", &x);
                printf("Entrez le second entier : ");
                scanf("%d", &y);

                int res = produit(x, y);
                printf("Le produit de %d et %d vaut : %d\n", x, y, res);
                break;
            }

            case 3: {
                int x, y;
                printf("Entrez le premier entier : ");
                scanf("%d", &x);
                printf("Entrez le second entier : ");
                scanf("%d", &y);

                printf("Le minimum entre %d et %d est : %d\n", x, y, min2(x, y));
                break;
            }

            case 4: {
                int n1, n2, n3, n4;
                printf("Entrez 4 entiers separes par des espaces : ");
                scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

                printf("Le minimum parmi ces 4 nombres est : %d\n", min4(n1, n2, n3, n4));
                break;
            }

            case 5: {
                int etages;
                do {
                    printf("Nombre d'etages du sapin (minimum 2) : ");
                    scanf("%d", &etages);
                    if (etages < 2) {
                        printf("Erreur : le sapin doit avoir au moins 2 etages.\n");
                    }
                } while (etages < 2);

                printf("\n");
                dessinerSapin(etages);
                break;
            }

            case 6: {
                int etages;
                do {
                    printf("Nombre d'etages du sapin bonus (minimum 2) : ");
                    scanf("%d", &etages);
                    if (etages < 2) {
                        printf("Erreur : le sapin doit avoir au moins 2 etages.\n");
                    }
                } while (etages < 2);

                printf("\n");
                dessinerSapinBonus(etages);
                break;
            }

            case 0:
                printf("Fermeture du programme. Au revoir !\n");
                break;

            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 0 et 6.\n");
                break;
        }

    } while (choix != 0);

    return 0;
}

// ==========================================
// DÉFINITION DES FONCTIONS DES EXERCICES
// ==========================================

// Exercice 1 : Affiche "Hello World"
void bonjour()
{
    printf("Hello World\n");
}

// Exercice 2 : Calcule et renvoie le produit de deux entiers
int produit(int a, int b)
{
    return a * b;
}

// Exercice 3 : Renvoie le plus petit de deux entiers
int min2(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

// Exercice 4 : Renvoie le plus petit de quatre entiers en utilisant min2
int min4(int a, int b, int c, int d)
{
    int minGauche = min2(a, b);
    int minDroite = min2(c, d);
    return min2(minGauche, minDroite);
}

// Exercice 5 : Dessine le sapin de Noël standard
void dessinerSapin(int etages)
{
    // 1. L'étoile au sommet (+) : centrée avec (etages - 1) espaces
    for (int i = 0; i < etages - 1; i++) {
        printf(" ");
    }
    printf("+\n");

    // 2. Les branches feuillues (*)
    for (int i = 0; i < etages; i++) {
        // Espaces avant les étoiles
        for (int j = 0; j < etages - 1 - i; j++) {
            printf(" ");
        }
        // Étoiles sur la ligne (1, 3, 5, 7...)
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // 3. Le tronc (#) : grossit tous les 2 étages
    int tailleTronc = etages / 2;         // Hauteur du tronc (1 pour 2-3 étages, 2 pour 4-5...)
    int largeurTronc = 2 * tailleTronc - 1; // Largeur impaire (1, 3, 5, 7...)
    int espacesTronc = etages - tailleTronc;

    for (int i = 0; i < tailleTronc; i++) {
        for (int j = 0; j < espacesTronc; j++) {
            printf(" ");
        }
        for (int j = 0; j < largeurTronc; j++) {
            printf("#");
        }
        printf("\n");
    }
}

// Exercice 5 (Bonus) : Grande étoile tous les 3 étages + boules espacées
void dessinerSapinBonus(int etages)
{
    // 1. Étoile qui grossit tous les 3 étages (losange de rayon k)
    int k = (etages - 2) / 3;
    for (int r = -k; r <= k; r++) {
        int distanceCentre = (r < 0) ? -r : r; // Valeur absolue de r
        int nbPlus = 2 * (k - distanceCentre) + 1;
        int espaces = (etages - 1) - (k - distanceCentre);

        for (int j = 0; j < espaces; j++) {
            printf(" ");
        }
        for (int j = 0; j < nbPlus; j++) {
            printf("+");
        }
        printf("\n");
    }

    // 2. Feuillage avec boules ('O' et 'o') espacées et absentes du bas
    for (int i = 0; i < etages; i++) {
        int largeurLigne = 2 * i + 1;

        for (int j = 0; j < etages - 1 - i; j++) {
            printf(" ");
        }

        for (int j = 0; j < largeurLigne; j++) {
            // Pas de boule sur la dernière ligne (i < etages - 1) ni sur les bords (j > 0 && j < largeurLigne - 1)
            // On place une boule une ligne sur deux (i % 2 == 1) avec un pas de 4 colonnes pour éviter qu'elles se touchent
            if (i < etages - 1 && i % 2 == 1 && j > 0 && j < largeurLigne - 1 && j % 4 == 2) {
                if ((i + j) % 2 == 0) {
                    printf("O");
                } else {
                    printf("o");
                }
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    // 3. Le tronc (#)
    int tailleTronc = etages / 2;
    int largeurTronc = 2 * tailleTronc - 1;
    int espacesTronc = etages - tailleTronc;

    for (int i = 0; i < tailleTronc; i++) {
        for (int j = 0; j < espacesTronc; j++) {
            printf(" ");
        }
        for (int j = 0; j < largeurTronc; j++) {
            printf("#");
        }
        printf("\n");
    }
}
