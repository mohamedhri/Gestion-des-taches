#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TACHES 100

struct Tache {
    char description[100];
    char dateEcheance[20];
};

struct Tache taches[MAX_TACHES];
int nbTaches = 0;

void ajouterTache() {}

void afficherListeTaches() {}

void modifierTache() {}

void supprimerTache() {}

void trierTaches() {}

int main() {
    int choix;

    while (1) {
        printf("\nGestionnaire de taches\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher la liste des taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Supprimer une tache\n");
        printf("5. Trier les taches\n");
        printf("6. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterTache();
                break;
            case 2:
                afficherListeTaches();
                break;
            case 3:
                modifierTache();
                break;
            case 4:
                supprimerTache();
                break;
            case 5:
                trierTaches();
                break;
            case 6:
                printf("Merci d'avoir utilise le gestionnaire de taches.\n");
                return 0;
            default:
                printf("Choix invalide.\n");
                break;
        }
    }

    return 0;
}
