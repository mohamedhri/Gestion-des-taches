#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TACHES 100

struct Tache {
    char description[100];
    char dateEcheance[20];
    int priorite;
};

struct Tache taches[MAX_TACHES];
int nbTaches = 0;

void ajouterTache() {
    if (nbTaches >= MAX_TACHES) {
        printf("La liste des taches est pleine.\n");
        return;
    }

    struct Tache nouvelleTache;

    printf("Description de la tache : ");
    scanf(" %[^\n]", nouvelleTache.description);

    printf("Date d'echeance : ");
    scanf(" %[^\n]", nouvelleTache.dateEcheance);

    printf("Priorite : ");
    scanf("%d", &nouvelleTache.priorite);

    taches[nbTaches++] = nouvelleTache;

    printf("Tache ajoutee avec succes.\n");
}

void afficherListeTaches() {
    if (nbTaches == 0) {
        printf("La liste des taches est vide.\n");
        return;
    }

    printf("Liste des taches :\n");
    for (int i = 0; i < nbTaches; i++) {
        struct Tache tache = taches[i];
        printf("Tache %d :\n", i + 1);
        printf("Description : %s\n", tache.description);
        printf("Date d'echeance : %s\n", tache.dateEcheance);
        printf("Priorite : %d\n", tache.priorite);
        printf("--------------------\n");
    }
}

void modifierTache() {
    if (nbTaches == 0) {
        printf("La liste des taches est vide.\n");
        return;
    }

    int indexTache;
    printf("Entrez le numero de la tache a modifier : ");
    scanf("%d", &indexTache);

    if (indexTache < 1 || indexTache > nbTaches) {
        printf("Numero de tache invalide.\n");
        return;
    }

    struct Tache *tache = &taches[indexTache - 1];

    printf("Nouvelle description : ");
    scanf(" %[^\n]", tache->description);

    printf("Nouvelle date d'echeance : ");
    scanf(" %[^\n]", tache->dateEcheance);

    printf("Nouvelle priorite : ");
    scanf("%d", &tache->priorite);

    printf("Tache modifiee avec succes.\n");
}

void supprimerTache() {
    if (nbTaches == 0) {
        printf("La liste des taches est vide.\n");
        return;
    }

    int indexTache;
    printf("Entrez le numero de la tache a supprimer : ");
    scanf("%d", &indexTache);

    if (indexTache < 1 || indexTache > nbTaches) {
        printf("Numero de tache invalide.\n");
        return;
    }

    for (int i = indexTache - 1; i < nbTaches - 1; i++) {
        taches[i] = taches[i + 1];
    }

    nbTaches--;

    printf("Tache supprimee avec succes.\n");
}

void trierTaches() {
    if (nbTaches == 0) {
        printf("La liste des taches est vide.\n");
        return;
    }

    int choix;
    printf("Tri des taches :\n");
    printf("1. Tri croissant par priorite\n");
    printf("2. Tri decroissant par priorite\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    
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
