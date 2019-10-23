#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 512

int main() {
    DIR *dirp = opendir("tmp");
    if (dirp == NULL) return -1;

    struct dirent *dp;
    while ((dp = readdir(dirp)) != NULL) { // scan tmp directory
        struct stat st;
        char path[SIZE] = "tmp/";
        strcat(path, dp->d_name);
        if (stat(path, &st) == -1)  {
            return -1;
        } else {
            if (st.st_nlink > 1) { // if the number of hard links is more than 1
                printf("File: %s\nHard links:\n", dp->d_name);
                DIR *dirp2 = opendir("tmp");
                if (dirp2 == NULL) return -1;
                struct dirent *dp2;
                while ((dp2 = readdir(dirp2)) != NULL) {
                    struct stat st2;
                    char path2[SIZE] = "tmp/";
                    strcat(path2, dp2->d_name);
                    if (stat(path2, &st2) == -1)  {
                        return -1;
                    } else {
                        if (st.st_ino == st2.st_ino)
                            printf("%s\n", dp2->d_name);
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}