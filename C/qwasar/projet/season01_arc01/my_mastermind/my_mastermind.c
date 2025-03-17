#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void user_input( char* try ){
    int error = 0;
    int pass = 0;
    int count = 0;
    int char_used[255] = {0};

    while ( pass < 1 ) {        // in case there are any problem with the user input like if the character is not between 0 & 8 or if there are duplicate 
        read(0, try, 5); 
        try[4] = '\0';
        if( strcmp(try, "\0") == 0) {
                exit(0);
            }

        int length = strlen( try );

        for(int index = 0;  index  < length ; index++) { 
            if (try[ index ] < '0' || try [ index ] > '8' ) {
                error = 1;
            }
            int temp = try[index];
            char_used[ temp ] += 1;
            count++; 
        }
        if ( ( count > 4 || count < 4 ) ){
            error = 1;
        }
        count = 0;
        for(int index = 0; index < 255; index++) {
            if ( char_used[index] > 1 ) {
                error = 1;
            }
            char_used[index] = 0;
        }
        
        if ( error == 1 ) {
                printf("wrong input !\n");
                pass = 0;
                error = 0;
            }
            else { 
                pass = 1;
            }
    }
}

 void my_mastermind(char* code, int attempt){
    int index = 0;
    int wellplaced = 0;
    int misplaced = 0;

    char *try = malloc( 5 );
    try[4] = '\0';

    // printf("%s %d\n", code, attempt);       //just in case you want to have the number of attempt and the code 
    printf("Will you find the secret code?\nPlease enter a valid guess\n---\n");

    while( index < attempt ) {
        printf("Round %d\n", index);   

        user_input( try );   // the user input ...

        if ( strcmp(code, try) == 0 ) {   // compare the code and the user input 
            printf("Congratz! You did it!\n");
            free(try);
            return;
        }

        wellplaced = 0; 
        misplaced = 0; 
        for (int i = 0; i < 4; i++) { 
            if (code[i] == try[i]) { 
                wellplaced++; 
            } 
            else if (strchr(code, try[i])) { 
                misplaced++;
            }
        }

        printf("Well placed pieces: %d\nMisplaced pieces: %d\n---\n", wellplaced, misplaced);

        index++;
    }
    free(try);
    return;
 }


char *generate_my_code(char *code) {
    int index = 0;
    const char nbr[] = "012345678";
    srand(time(NULL));   // set the seed at time NULL so the code that we get is different all the time we use it 

    int nbr_used[9] = {0};   // for the duplicate 
    
    while (index < 4) {
        int rand_index = rand() %9;  // get a random number between 0 & 8

        if( nbr_used[rand_index] == 0 ) {   // if the number has been already use then get another random number 
            code[index] = nbr[rand_index];
            nbr_used[rand_index] = 1;
            index++;
        }
        
    }
    code[4] = '\0';
    return code;
}


int get_attempt(int argc, char **argv){
    int index = 0;

    while( index < argc ) {
        if( (strcmp("-t", argv[index]) == 0) ) {
            if ( (index + 1 >= argc) ) {
                return 10;
            }
            int attempt = atoi ( argv[index + 1] );   
            return attempt;
        }
        index += 1;
    }

    return 10;
}

char *get_code(int argc, char **argv){
    int index = 0;
    char *code = malloc(5);
    code[4] = '\0';

    while (index < argc) {

        if (( strcmp( "-c", argv[ index ] ) == 0) ) {   

            if ((index + 1 >= argc) || (strlen(argv[index + 1]) != 4)) {

                if( index + 1 >= argc || strcmp( "-t", argv[ index + 1 ] ) == 0 ) {
                    return generate_my_code(code);
                }

                printf("usage: my_masterind [-c \"code\"] where code size == 4\n");
                exit(0);
            }
            return argv[index + 1];
        }
        index += 1;
    }
    return generate_my_code(code);

}
 
int main(int argc, char** argv){
    char *code = get_code(argc, argv);  
    int attempt = get_attempt(argc, argv);

    my_mastermind(code, attempt);
    return 0;
}