#include <sys/types.h>
#include <sys/stat.h>

#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

void print(char **str) {
    int i = 0;
    while (str[i] != NULL) {
        printf("%s\t", str[i]);
        i++;
    }
    printf("\n");
}

void get_sorted_files() {
    
}


void get_all_files(char *c) {
    DIR *dir;
    struct dirent *entry;
    dir = opendir(c);
    char **str = malloc(sizeof(char *) * 100);
    int index = 0;

    if (dir == NULL) {
        printf("Unable to open directory");
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            str[index++] = strdup(entry->d_name);
        }
    }
    print(str);

    closedir(dir);
    free(str);
    // printf("Print all files\n");
}

void flag_a(char *c) {     // print_all_files_by_dot
    DIR *dir;
    struct dirent *entry;
    dir = opendir(c);
    char **str = malloc(sizeof(char *) * 100);
    int index = 0;

    if (dir == NULL) {
        printf("Unable to open directory");
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        str[index++] = strdup(entry->d_name);
    }
    print(str);

    closedir(dir);
    free(str);
    // printf("Flag -a\n");
}

void flag_t(char *c) {     // print_all_files_by_time
    DIR *dir;
    struct dirent *entry;
    dir = opendir(c);
    char **str = malloc(sizeof(char *) * 100);
    int index = 0;

    if (dir == NULL) {
        printf("Unable to open directory");
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            str[index++] = strdup(entry->d_name);
        }
    }
    print(str);

    closedir(dir);
    free(str);
    // printf("Flag -t\n");
}

void flag_at(char *c) {    // print_all_files_by_time_and_by_dot
    printf("Flag -at\n");
}

void get_flag(int ac, char** av) {
    int index = 0;
    int index_flag_a = 0;
    int index_flag_t = 0;
    int index_flag_at = 0;
    char *c = ".";

    while(index < ac) {
        if(strcmp("-at", av[index]) == 0 || strcmp("-ta", av[index]) == 0) {
            index_flag_at = 1;
        } else if(strcmp("-a", av[index]) == 0) {
            index_flag_a = 1;
        } else if(strcmp("-t", av[index]) == 0) {
            index_flag_t = 1;
        } else {
            c = av[index];
        }
        index += 1;
    }

    if((index_flag_a == 1 && index_flag_t == 1) || index_flag_at == 1) {
        flag_at(c);
    } else if(index_flag_a == 1 && index_flag_t == 0) {
        flag_a(c);
    } else if(index_flag_t == 1 && index_flag_a == 0) {
        flag_t(c);
    } else {
        get_all_files(c);
    }
}

int main(int ac, char** av) {

    get_flag(ac, av);

    return 0;
}