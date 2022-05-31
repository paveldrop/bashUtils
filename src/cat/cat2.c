#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include "s21_cat.h"

// FILE *fp;

// #define no_argument            0  //  если НЕ имеем аргумент в командной строке
// #define required_argument      1  //  если имеем аргумент в командной строке
// #define optional_argument      2

  


void FileReader(int argc, char *argv[]);
void GetOptions(int argc, char *argv[]);
void NumEveryString(int argc, char *argv[]);
void NumNonEmptyString(int argc, char *argv[]);
int IfFileNotRun(int argc, char *argv[]);
void IfFileFound(int argc, char *argv[]);
void AddDollar(int argc, char *argv[]);

int IfFileNotRun(int argc, char *argv[]) {
    int r;
    if (fp == NULL) {
        perror("Такого файла не существует!");
        r = -1;
    } else {
        r = 1;
    }
    return r;
}

void IfFileFound(int argc, char *argv[]) {
    fp = fopen(argv[argc - 1], "r+");
}

int main(int argc, char* argv[]) {
    fp = fopen(argv[argc - 1], "r+");
    if((IfFileNotRun(argc, argv)) == 1) {
            FileReader(argc, argv);
            GetOptions(argc, argv);
        }
    return 0;
}

void FileReader(int argc, char *argv[]) {
    fp = fopen(argv[argc - 1], "r+");
    char text1[1024];
    while (fgets(text1, 1024, fp) != NULL) {
        printf("%s", text1);
    }
    fclose(fp);
}

void GetOptions(int argc, char **argv) {
    flags opt;
    opt.b = 0;
    opt.e = 0;
    opt.s = 0;
    opt.t = 0;
    opt.n = 0;
    const char* short_options = "bestn";
    struct option long_options[] = {
		{ "number-nonblank", 0, 0, 'b'},
		{ "squeeze-blank", 0, 0, 's'},
        { "number", 0, 0, 'n'},
		{ NULL, 0, NULL, 0}
	};
    int long_index = 0;
    int total = getopt_long(argc, argv, short_options, long_options, &long_index);

    while (total != -1) {
        switch (total)
        {
        case 'b':
            printf("found argument \"b = %s\".\n", optarg);
            
            opt.b += 1;
            NumNonEmptyString(argc, argv);
            total = -1;
            break;
        case 'e':
            printf("found argument \"e = %s\".\n", optarg);
            opt.e += 1;
            AddDollar(argc, argv);
            total = -1;
            break;
        case 's':
            printf("found argument \"s = %s\".\n", optarg);
            opt.s += 1;
            break;
        case 't':
            printf("found argument \"t = %s\".\n", optarg);
            opt.t += 1;
            break;
        case 'n':
            opt.n += 1;
            NumEveryString(argc, argv);
            printf("found argument \"n = %s\".\n", optarg);
            total = -1;
            break;
        default:
            FileReader(argc, argv);
            printf("cat [OPTION] [FILE]...");
            break;
        }
    }
}


void NumEveryString(int argc,  char *argv[]) {
    IfFileNotRun(argc, argv);
    char text[2048];
    int n = 1;
    while(!feof(fp)) {
            fgets(text, 1000, fp);
            printf("%6d %s", n++, text);
        }
    fclose (fp);
}
void NumNonEmptyString(int argc, char *argv[]) {
    fp = fopen(argv[argc - 1], "r+");
    char text[2048];
    int n = 1;
    while(!feof(fp)) {
            fgets(text, 1000, fp);
            if(strlen(text) > 1) {
            printf("%6d %s", n++, text);
            } else {
                printf("%s", text);
            }
        }
    fclose (fp);

}

void AddDollar(int argc, char *argv[]) {
    fp = fopen(argv[argc - 1], "r+");
    char text[2048];
    while(!feof(fp)) {
            fgets(text, 1000, fp);
            strcat(text, "$___");
            printf("%s", text);
        }
    fclose (fp);
}


