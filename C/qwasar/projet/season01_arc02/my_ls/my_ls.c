#include <sys/types.h>
#include <sys/stat.h>

#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

void get_print_all_files() {
    DIR *dir;
    struct dirent *str;
    dir = opendir(".");
    if (dir == NULL) {
        printf("Unable to open directory");
        return;
    }
    while ((str = readdir(dir)) != NULL) {
        if (str->d_name[0] != '.') {
            printf("%s\t", str->d_name);
        }
    }
    printf("\n");
    closedir(dir);
    // printf("Print all files\n");
}

void flag_a() {     // print_all_files_by_dot
    DIR *dir;
    struct dirent *str;
    dir = opendir(".");
    if (dir == NULL) {
        printf("Unable to open directory");
        return;
    }
    while ((str = readdir(dir)) != NULL) {
        printf("%s\t", str->d_name);
    }
    printf("\n");
    closedir(dir);
    // printf("Flag -a\n");
}

void flag_t() {     // print_all_files_by_time
    DIR *dir;
    struct dirent *str;
    struct dirent *temp;
    dir = opendir(".");
    struct stat st;
    struct stat stemp;
    if (dir == NULL) {
        printf("Unable to open directory");
        return;
    }
    while ((str = readdir(dir)) != NULL) {
        stat(str->d_name, &st);
        stat(str->d_name, &stemp);
        while((temp = readdir(dir))!= NULL && (st.st_mtime < stemp.st_mtime)) {
            stemp.st_mtime = st.st_mtime;
            str = temp;
        }
        // printf("%s\t%ld\t", str->d_name, st.st_mtime);
        printf("%s\t", temp->d_name);
        // if (str->d_name[0] != '.') {
        //     printf("%s\t", str->d_name);
        // }
    }
    printf("\n");
    // printf("Flag -t\n");
}

void flag_at() {
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
        get_print_all_files();
    }
}

int main(int ac, char** av) {

    get_flag(ac, av);

    return 0;
}