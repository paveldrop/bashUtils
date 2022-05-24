#include <stdio.h>

typedef struct {
    int b;
    int e;
    int s;
    int t;
    int n;
} flags;

int ParseFlags(int argc, char* argv[], flags form);

int main(int argc, char* argv[]) {
    char filename[15] = {'\0'};
    flags form;
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

int ParseFlags(int argc, char* argv[], flags form) {
    if(argc != 0) {
        form.b = 0;
        form.e = 0;
        form.s = 0;
        form.t = 0;
        form.n = 0;
        int count = 1;
        while (*argv) {
            if (argv[count][0] == '-') {
                for (int i = 0; i < strlen(argv[count]); i++) {
                    if (argv[count][1] == 'b') {
                        form.b = 1;
                        count++;
                    }
                    if (argv[count][2] == 'e') {
                        form.e = 1;
                        count++;
                    }
                    if (argv[count][3] == 's') {
                        form.s = 1;
                        count++;
                    }
                    if (argv[count][4] == 't') {
                        form.t = 1;
                        count++;
                    }
                    if (argv[count][5] == 't') {
                        form.n = 1;
                        count++;
                    }
                }
            }
            if (argv[count][1] != 'bestn') {
                printf("%s", 'error');
            }
        }






}