#include <stdio.h>
#include <stdlib.h>

void my_christmas_tree(int nbr_of_section, int nbr_of_space_max) {
    char trunk = '|';
    char stars = '*';
    char space = ' ';

    int nbr_of_stars_max = 1;  // Nombre initial d'étoiles pour la première ligne
    int space_for_trunk = nbr_of_space_max / 2 - 2;  // Position du tronc (centré)

    // Boucle pour chaque section
    for (int section = 0; section < nbr_of_section; section++) {
        // Pour chaque ligne de la section
        for (int row = 0; row < section + 1; row++) {
            // Espaces avant les étoiles
            for (int i = 0; i < nbr_of_space_max - nbr_of_stars_max / 2; i++) {
                printf("%c", space);
            }

            // Affichage des étoiles
            for (int i = 0; i < nbr_of_stars_max; i++) {
                printf("%c", stars);
            }

            // Passage à la ligne suivante
            printf("\n");

            // Préparation pour la prochaine ligne
            nbr_of_stars_max += 2;  // Chaque ligne suivante a 2 étoiles en plus
        }

        // Réduction des espaces pour la prochaine section
        nbr_of_space_max--;
    }

    // Affichage du tronc
    for (int i = 0; i < nbr_of_section; i++) {
        // Espaces avant le tronc
        for (int i = 0; i < space_for_trunk; i++) {
            printf("%c", space);
        }

        // Tronc de l'arbre
        for (int i = 0; i < 5; i++) {  // Le tronc fait 5 caractères de large
            printf("%c", trunk);
        }
        printf("\n");
    }
}

int get_size(int nbr) {
    int size = 1;
    for (int section = 0; section < nbr; section++) {
        size += 2 * (section + 1);  // Chaque section a 2 étoiles supplémentaires par ligne
    }
    return size;  // Retourne la taille totale des espaces nécessaires
}

int main(int ac, char **av) {
    if (ac != 2 || atoi(av[1]) == 0) {
        return 0;
    }

    int nbr_of_section = atoi(av[1]);
    int nbr_space = get_size(nbr_of_section);

    my_christmas_tree(nbr_of_section, nbr_space);

    return 0;
}
