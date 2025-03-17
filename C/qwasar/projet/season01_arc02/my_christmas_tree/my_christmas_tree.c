#include <stdio.h>
#include <stdlib.h>

// void *space(int nbr) {}

// void *stars(int nbr) {}

// void *trunk(int nbr) {}

void my_christmas_tree(int nbr_of_section, int nbr_of_space_max) {
    char trunk = '|';
    char stars = '*';
    char space = ' ';

    int column_max = 3;
    int nbr_of_stars_max = 1;
    int count_section = 2;
    int index = 1;
    int space_for_trunk = nbr_of_space_max - nbr_of_section;

    for(int section = 0; section < nbr_of_section; section++) {
        for(int column = 0; column < column_max; column++) {
            for(int space = 0;space < nbr_of_space_max; space++) {
                printf("%c", space);
            }

            for(int i = 0; i < nbr_of_stars_max; i++) {
                printf("%c", stars);
            }

            printf("\n");

            nbr_of_stars_max += 2;
            nbr_of_space_max -= 1;
            column++;
        }
        
        if(count_section == 0) {
            count_section = 2;
            index += 1;
        }
        count_section--;
        nbr_of_stars_max -= index;
        nbr_of_space_max += index;
        section++;
        column_max++;
    }

    for(int i = 0; i < nbr_of_section; i++) {
        for(int i = 0; i < space_for_trunk; i++) {
            printf("%c", space);
        }

        for(int i = 0; i < nbr_of_section; i++) {
            printf("%c", trunk);
        }
        printf("\n");
    }

}

int get_size(int nbr) {
    int size = 1;
    int section = 0;
    int column = 0;
    int column_max = 3;
    int count_section = 2;
    int less_size = 1;

    while(section < nbr) {
        while(column < column_max) {
            size += 2;
            column++;
        }
        if(count_section == 0) {
            count_section = 2;
            less_size += 1;
        }
        size -= less_size;

        count_section--;
        column_max++;
        section++;
    }

    return (size -1) / 2;
}

int main(int ac, char **av) {
    if(ac > 2 || atoi(av[1]) == 0) {
        return 0;
    }

    int nbr_of_section = atoi(av[1]);

    int nbr_space = get_size(nbr_of_section);

    my_christmas_tree(nbr_of_section, nbr_space);

    return 0;
}