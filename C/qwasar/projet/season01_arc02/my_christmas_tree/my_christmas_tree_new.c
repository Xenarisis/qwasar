#include <stdlib.h>
#include <stdio.h>

void space(int nbr) {
    for(int i = 0; i < nbr; i++) { 
        printf(" ");
    }
}

void stars(int nbr) {
    for(int i = 0; i < nbr; i++) {  
        printf("*");
    }
}

void trunk(int nbr) {
    for(int i = 0; i < nbr; i++) {  
        printf("|");
    }
}

int my_christmas_tree_section(int section, int nbr_of_column, int nbr_of_space, int nbr_of_stars) {
    for(int column = 0; column < nbr_of_column; column++) {
        space(nbr_of_space);
        stars(nbr_of_stars);
        printf("\n");
        nbr_of_stars += 2;
        nbr_of_space--;
    }
    return nbr_of_stars - 2;
}

void my_christmas_tree_trunk(int nbr_of_trunk, int nbr_of_column, int nbr_of_space) {
    for(int column = 0; column < nbr_of_column; column++) {
        space(nbr_of_space);
        trunk(nbr_of_trunk);
        printf("\n");
    }
}

void my_christmas_tree(int nbr_of_section, int nbr_of_space) {
    int count_section = 2;
    int nbr_of_column = 4;
    int stars = 1;
    int index_stars = 2;
    int index_space = 2;
    int last_column;
    for(int section = 0; section < nbr_of_section; section++) {
        if(count_section == 0) {
            count_section = 2;
            index_stars += 2;
            index_space--;
        }

        if(nbr_of_section == 1) {
            last_column = my_christmas_tree_section(section, nbr_of_column, nbr_of_space + 1, stars);
        } else {
            last_column = my_christmas_tree_section(section, nbr_of_column, nbr_of_space, stars);
        }
        nbr_of_column++;
        last_column -= index_stars;
        stars = last_column;
        nbr_of_space -= index_space;
        index_space += 1;
        count_section--;
        if(stars <= 3) {
            stars += 2;
        }
    }

    int trunk_space = nbr_of_space + (stars - nbr_of_section) / 2;
    if(nbr_of_section <= 4 && nbr_of_section != 3) {
        trunk_space++;
    }
    my_christmas_tree_trunk(nbr_of_section, nbr_of_section, trunk_space);
}

int get_size(int nbr) {
    int size = 1;
    for (int section = 0; section < nbr; section++) {
        size += 1 * (section + 1);
    }
    return size + nbr;
}

int get_less_space(int nbr) {
    int less_space = 0;
    int index_space = 1;
    int count = 0;
 
    for(int n = 3; n < nbr; n++) {
        if(count == 2) {
            count = 0;
            index_space++;
        }
        
        less_space += index_space;
        
        count++;
    }

    return less_space;
}

int main(int ac, char **av) {
    if(ac != 2 || atoi(av[1]) <= 0) {
        return 0;
    }

    int nbr_of_section = atoi(av[1]);
    int nbr_space = get_size(nbr_of_section) ;
    if(nbr_of_section == 1 || nbr_of_section == 4){
        nbr_space--;
    } else if(nbr_of_section >= 5) {
        nbr_space -= get_less_space(nbr_of_section);
    }

    my_christmas_tree(nbr_of_section, nbr_space);

    return 0;
}