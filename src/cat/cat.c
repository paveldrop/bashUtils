#include "s21_cat.h"

// struct fl {
//     int b = 0;
//     int e ;
//     int s;
//     int t;
//     int n;
// } flags;

    struct option long_options[] =
{
    {"b", required_argument, b, 1},
    {"e", required_argument, e, 2},
    {"s", required_argument, s, 3},
    {"t", required_argument, t, 4},
    {"n", required_argument, n, 5},
    {NULL, 0, NULL, 0}
};



void FileReader(int argc, char *argv[]);
void GetOptions(int argc, char *argv[], struct option flags);

// void ParseFlags(int argc, char* argv[], flags form);

int main(int argc, char* argv[]) {
    
    int b = 0;
    int e = 0;
    int s = 0;
    int t = 0;
    int n = 0;

    struct option flags;

    GetOptions(argc, argv, flags);
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

void GetOptions(int argc, char **argv, struct option flags) {

    extern char *optarg;
    int total = getopt_long(argc, argv, "b:e:s:t:n:", long_options, NULL);

    while (total != -1) {
        switch (total)
        {
        case 'b':
            flags.b = optarg;
            printf("found argument \"b = %s\".\n", optarg);
            break;
        case 'e':
            flags.e = optarg;
            printf("found argument \"e = %s\".\n", optarg);
            break;
        case 's':
            flags.s = optarg;
            printf("found argument \"s = %s\".\n", optarg);
            break;
        case 't':
            flags.t = optarg;
            printf("found argument \"t = %s\".\n", optarg);
            break;
        case 'n':
            flags.n = optarg;
            printf("found argument \"n = %s\".\n", optarg);
            break;
        }
    }
}
