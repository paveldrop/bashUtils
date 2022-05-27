#include <stdio.h>
#include <string.h>
#include <getopt.h>


FILE *fp;

#define no_argument            0  //  если НЕ имеем аргумент в командной строке
#define required_argument      1  //  если имеем аргумент в командной строке
#define optional_argument      2

  


void FileReader(int argc, char *argv[]);
void GetOptions(int argc, char *argv[]);


int main(int argc, char* argv[]) {

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
    int b = 0;
    int e = 0;
    int s = 0;
    int t = 0;
    int n = 0;
    const char* short_options = "b:e:s:t:n:";
    struct option long_options[] = {
		{ "opta", no_argument, &b, 1 },
		{ "optb", no_argument, &e, 10 },
		{ "optc", no_argument, &s, -121 },
        { "opt_t", no_argument, &t, -1000 },
        { "optn", no_argument, &n, -2000 },
		{ NULL, 0, NULL, 0}
	};
    int option_index;
    int total = getopt_long(argc, argv, short_options, long_options, &option_index);

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
            n = 1;
            printf("found argument \"n = %d\".\n", n);
            total = -1;
            break;
        }
    }
}
