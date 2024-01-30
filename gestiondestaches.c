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

    printf("Priorite (1-5) : ");
    scanf("%d", &nouvelleTache.priorite);

    if (nouvelleTache.priorite < 1 || nouvelleTache.priorite > 5) {
        printf("Priorite invalide. Veuillez choisir une priorite entre 1 et 5.\n");
        return;
    }

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

    printf("Nouvelle priorite (1-5) : ");
    scanf("%d", &tache->priorite);

    if (tache->priorite < 1 || tache->priorite > 5) {
        printf("Priorite invalide. Veuillez choisir une priorite entre 1 et 5.\n");
        return;
    }

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
    printf("3. Tri par date d'echeance croissante\n");
    printf("4. Tri par date d'echeance decroissante\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            // Tri croissant par priorite
            for (int i = 0; i < nbTaches - 1; i++) {
                for (int j = 0; j < nbTaches - i - 1; j++) {
                    if (taches[j].priorite > taches[j + 1].priorite) {
                        struct Tache temp = taches[j];
                        taches[j] = taches[j + 1];
                        taches[j + 1] = temp;
                    }
                }
            }
            printf("Taches triees par priorite en ordre croissant.\n");
            break;
        case 2:
            // Tri decroissant par priorite
            for (int i = 0; i < nbTaches - 1; i++) {
                for (int j = 0; j < nbTaches - i - 1; j++) {
                    if (taches[j].priorite < taches[j + 1].priorite) {
                        struct Tache temp = taches[j];
                        taches[j] = taches[j + 1];
                        taches[j + 1] = temp;
                    }
                }
            }
            printf("Taches triees par priorite en ordre decroissant.\n");
            break;
        case 3:
            // Tri par date d'echeance croissante
            for (int i = 0; i < nbTaches - 1; i++) {
                for (int j = 0; j < nbTaches - i - 1; j++) {
                    if (strcmp(taches[j].dateEcheance, taches[j + 1].dateEcheance) > 0) {
                        struct Tache temp = taches[j];
                        taches[j] = taches[j + 1];
                        taches[j + 1] = temp;
                    }
                }
            }
            printf("Taches triees par date d'echeance en ordre croissant.\n");
            break;
        case 4:
            // Tri par date d'echeance decroissante
            for (int i = 0; i < nbTaches - 1; i++) {
                for (int j = 0; j < nbTaches - i - 1; j++) {
                    if (strcmp(taches[j].dateEcheance, taches[j + 1].dateEcheance) < 0) {
                        struct Tache temp = taches[j];
                        taches[j] = taches[j + 1];
                        taches[j + 1] = temp;
                    }
                }
            }
            printf("Taches triees par date d'echeance en ordre decroissant.\n");
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }
}

void filtrerTachesParPriorite() {
    int prioriteFiltre;
    printf("Filtrer les taches par priorite (1-5) : ");
    scanf("%d", &prioriteFiltre);

    if (prioriteFiltre < 1 || prioriteFiltre > 5) {
        printf("Priorite invalide. Veuillez choisir une priorite entre 1 et 5.\n");
        return;
    }

    printf("Taches avec priorite %d :\n", prioriteFiltre);
    for (int i = 0; i < nbTaches; i++) {
        if (taches[i].priorite == prioriteFiltre) {
            printf("Description : %s\n", taches[i].description);
            printf("Date d'echeance : %s\n", taches[i].dateEcheance);
            printf("Priorite : %d\n", taches[i].priorite);
            printf("--------------------\n");
        }
    }
}

void filtrerTachesParDateProche() {
    char dateFiltre[20];
    printf("Filtrer les taches dont la date d'echeance est proche (format : YYYY-MM-DD) : ");
    scanf(" %[^\n]", dateFiltre);

    printf("Taches avec date d'echeance proche de %s :\n", dateFiltre);
    for (int i = 0; i < nbTaches; i++) {
        if (strcmp(taches[i].dateEcheance, dateFiltre) <= 0) {
            printf("Description : %s\n", taches[i].description);
            printf("Date d'echeance : %s\n", taches[i].dateEcheance);
            printf("Priorite : %d\n", taches[i].priorite);
            printf("--------------------\n");
        }
    }
}

int main() {
    int choix;

    while (1) {
        
         printf(" \t \t Gestionnaire des taches\n");
    printf("    *===================================================*\n");
    printf("    # 1. Ajouter une tache                              #\n");
    printf("    # 2. Afficher la liste des taches                   #\n");
    printf("    # 3. Modifier une tache                             #\n");
    printf("    # 4. Supprimer une tache                            #\n");
    printf("    # 5. Trier les taches                               #\n");
    printf("    # 6. Filtrer les taches par priorite                #\n");
    printf("    # 7. Filtrer les taches par date d'echeance proche  #\n");
    printf("    # 8. Quitter                                        #\n");
    printf("    *===================================================*\n");


        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1) {
            scanf("%*s");
            printf(" \n Entree non valide!  Veuillez entrer un nombre.\n");
            continue;
        }

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
                filtrerTachesParPriorite();
                break;
            case 7:
                filtrerTachesParDateProche();
                break;
            case 8:
                printf("Merci d'avoir utilise le gestionnaire de taches.\n");
                return 0;
            default:
                printf("Choix invalide.\n");
                break;
        }
    }

    return 0;
}
