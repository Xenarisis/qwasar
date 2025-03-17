#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av){

    if (ac < 3) {
        return 0; 
    }

    int x = atoi(av[1]);
    int y = atoi(av[2]);
    int index = 0;
    int indey = 0;
    int i = 0;
    char rond = 'o';
    char verticale = '|';
    char horizon = '-';

    if( av[1] == NULL || av[2] == NULL || x == '\0' || y == '\0' ){
        return 0;
    }
    else{
    while( indey < y + 1 ){

        if( indey == 0 || indey == y - 1){
            while( index < x +1 ){
                if( index == 0 || index == x - 1 ){
                    printf("%c", rond);
                    index++;
                }
            
                if ( index > 0 && index < x - 1) {
                    printf("%c", horizon);
                    index++;
                }

                if( index == x ){
                    printf("\n");
                    index++;
                }
            }
            index = 0;
            indey++;

        }

        if( y > 2){
            if( indey > 0 && indey < y - 1){

                if( i == 0 || i == x - 1 ){
                    printf("%c", verticale);
                    i++;
                }

                if( i > 0 && i < x ){
                    while( i > 0 && i < x - 1 ){
                        printf(" ");
                        i++;
                    }
                }
        
                if( i == x ){
                    printf("\n");
                    i = 0;
                    indey++;
                }

            }
        }
        if( indey == y ){
            return 0;
        }
        
    }
    }

}