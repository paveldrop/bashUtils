#include "s21_cat.h"

// typedef struct {
//     int b;
//     int e;
//     int s;
//     int t;
//     int n;
// } flags;

void FileReader(int argc, char *argv[]);
void GetOptions(int argc, char *argv[]);

// void ParseFlags(int argc, char* argv[], flags form);

int main(int argc, char* argv[]) {
    // int fl_b = 0;
    // int fl_e = 0;
    // int fl_s = 0;
    // int fl_t = 0;
    // int fl_n = 0;

    // const char *short_options = "bestn";

    GetOptions(argc, argv);
    FileReader(argc, argv);
    return 0;
}

void FileReader(int argc, char *argv[]) {
    fp = fopen(argv[argc - 1], "r+");
    if (fp == NULL) {
        printf("Такого файла не существует!");
    }
    char text1[1024];
    while (fgets(text1, 1024, fp) != NULL) {
        printf("%s", text1);
    }
    fclose(fp);
}

void GetOptions(int argc, char **argv) {

    extern char *optarg;
    int total = getopt(argc, argv, "be::s::t::n:");

    while (total != -1) {
        switch (total)
        {
        case 'b':
            printf("found argument \"b = %s\".\n", optarg);
            break;
        case 'e':
            printf("found argument \"e = %s\".\n", optarg);
            break;
        case 's':
            printf("found argument \"s = %s\".\n", optarg);
            break;
        case 't':
            printf("found argument \"t = %s\".\n", optarg);
            break;
        case 'n':
            printf("found argument \"n = %s\".\n", optarg);
            break;
        default:
            break;
        }
    }
}