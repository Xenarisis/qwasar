#include <sys/types.h>
#include <sys/stat.h>

#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

void print(char **str) {
    int i = 0;
    while (str[i] != NULL) {
        printf("%s\n", str[i]);
        i++;
    }
    // printf("\n");
}

/*if(str[index][2] > str[index + 1][2]) {
            temp = str[index];
            str[index] = str[index + 1];
            str[index + 1] = temp;
        }*/

void get_sorted_files_by_character(char **str, int size) {
    int index = 0;
    char *temp;
    int n;

    while(str[index] != NULL) {
        n = '\0';
        for(int i = 0; i < size; i++) {
            if(str[i][2] > str[index][2]) {
                n = i;
            }
        }
        if(n != '\0') {
            temp = str[index];
            str[index] = str[n];
            str[n] = temp;
        }
        index++;
    }
    print(str);
}
// void get_sorted_files_by_times(char **str, int *times) {
// }

char **str_with_true_length(int size, char **str) {
    char **result = malloc(sizeof(char *) * size);
    for(int i = 0; i < size; i++) {
        result[i] = str[i];
    }

    return result;
}

void get_all_files() {
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    char **str = malloc(sizeof(char *) * 50);
    int index = 0;
    int count = 0;

    if (dir == NULL) {
        printf("Unable to open directory");
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            str[index++] = entry->d_name;
            count++;
        }
    }

    char **result = str_with_true_length(count, str);
    free(str);

    get_sorted_files_by_character(result, count);

    closedir(dir);
    // printf("Print all files\n");
}

void flag_a() {     // print_all_files_by_dot
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    char **str = malloc(sizeof(char *) * 50);
    int index = 0;
    int count = 0;

    if (dir == NULL) {
        printf("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        str[index++] = entry->d_name;
        count++;
    }

    char **result = str_with_true_length(count, str);
    free(str);

    get_sorted_files_by_character(result, count);

    closedir(dir);
    // printf("Flag -a\n");
}
void flag_t() {     // print_all_files_by_time
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    dir = opendir(".");
    char **str = malloc(sizeof(char *) * 50);
    int index = 0;

    if (dir == NULL) {
        printf("Unable to open directory");
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            stat(entry->d_name, &st);
            str[index++] = entry->d_name;
        }
    }
    print(str);

    closedir(dir);
    free(str);
    // printf("Flag -t\n");
}

void flag_at() {    // print_all_files_by_time_and_by_dot
    printf("Flag -at\n");
}

void get_flag(int ac, char** av) {
    int index = 0;
    int index_flag_a = 0;
    int index_flag_t = 0;
    int index_flag_at = 0;

    while(index < ac) {
        if(strcmp("-at", av[index]) == 0 || strcmp("-ta", av[index]) == 0) {
            index_flag_at = 1;
        } else if(strcmp("-a", av[index]) == 0) {
            index_flag_a = 1;
        } else if(strcmp("-t", av[index]) == 0) {
            index_flag_t = 1;
        }
        index += 1;
    }

    if((index_flag_a == 1 && index_flag_t == 1) || index_flag_at == 1) {
        flag_at();
    } else if(index_flag_a == 1 && index_flag_t == 0) {
        flag_a();
    } else if(index_flag_t == 1 && index_flag_a == 0) {
        flag_t();
    } else {
        get_all_files();
    }
}

int main(int ac, char** av) {

    get_flag(ac, av);

    return 0;
}
