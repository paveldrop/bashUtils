#include <stdio.h>

int main(int argc, char* argv[]) {
    char filename[15] = {'\0'};
    // fgets(filename, 15, 'readme.txt');
    FILE *fp = fopen(&filename, "r");
    if (fp == NULL) {
        return 1;
    }
    char text1[1024];
    while ((fgets(text1, 1024, fp) != NULL)) {
        printf("%s", text1);
    }
    fclose(fp);
    return 0;
}