#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    time_t mtime;
} file_info;

int compare_mtime(const void *a, const void *b) {
    return ((file_info*)b)->mtime - ((file_info*)a)->mtime;
}

void print_files(file_info *files, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\n", files[i].name);
    }
}

void get_print_all_files() {
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            printf("%s\n", entry->d_name);
        }
    }
    closedir(dir);
}

void flag_a() {
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

void flag_t() {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    file_info *files = NULL;
    int count = 0;

    dir = opendir(".");
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            stat(entry->d_name, &st);
            files = realloc(files, (count + 1) * sizeof(file_info));
            files[count].name = strdup(entry->d_name);
            files[count].mtime = st.st_mtime;
            count++;
        }
    }
    closedir(dir);

    qsort(files, count, sizeof(file_info), compare_mtime);
    print_files(files, count);

    for (int i = 0; i < count; i++) {
        free(files[i].name);
    }
    free(files);
}

void flag_at() {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    file_info *files = NULL;
    int count = 0;

    dir = opendir(".");
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        stat(entry->d_name, &st);
        files = realloc(files, (count + 1) * sizeof(file_info));
        files[count].name = strdup(entry->d_name);
        files[count].mtime = st.st_mtime;
        count++;
    }
    closedir(dir);

    qsort(files, count, sizeof(file_info), compare_mtime);
    print_files(files, count);

    for (int i = 0; i < count; i++) {
        free(files[i].name);
    }
    free(files);
}

// ... rest of your code (get_flag and main functions) remains the same