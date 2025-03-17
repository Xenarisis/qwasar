#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char* my_cat( char *av ) {
    FILE *fptr;
    fptr = fopen(av, "r" );
    if (fptr == NULL) {
        printf("Error: Could not open file %s\n", av);
        return 0;
    }

    fseek(fptr, 0, SEEK_END);
    long file_size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    if (file_size <= 0) {
        printf("la size est le problème.\n");
        fclose(fptr);
        return 0;
    }

    char *content = malloc( file_size + 1);
    if(content == NULL){
        printf("problème problème c'est un NULL");
        fclose(fptr);
        return 0;
    }

    size_t bytes_read = fread(content, 1, file_size, fptr);
    content[bytes_read] = '\0';

    printf("%s", content);

    free(content);
    fclose(fptr);
    return 0;
}

int main(int ac, char** agv){
    int index = 1;
    // int nmblim = atoi(*agv);

    while( index < ac ){
        my_cat(agv[index]);
        index++;
    }
    return 0;
}