#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac,char** arg){
    if( ac < 1){
        return '\0';
    }

    int ngram[255] = {0}; 
    int index = 1;
    while( index < ac){
        int index2 = 0;
        char* str = arg[index];
        while(str[index2] != '\0'){
            ngram[ (unsigned char) str[index2]] += 1;
            index2++;
        }
        index++;
    }

    index = 0;
    while (index < 255){
        if(ngram[index] > 0){
            printf("%c:%d\n", index, ngram[index]);
        }
        index++;
    }
}