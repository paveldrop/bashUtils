#include <stdio.h>
#include <string.h>

typedef struct {
    int b;
    int e;
    int s;
    int t;
    int n;
} flags;

#define no_argument            0  //  если НЕ имеем аргумент в командной строке
#define required_argument      1  //  если имеем аргумент в командной строке
#define optional_argument      2

const struct option long_options[] = {
		{ "opt_b", no_argument, &flag_b, 1 },
		{ "opt_e", no_argument, &flag_e, 10 },
		{ "opt_s", no_argument, &flag_s, -121 },
        { "opt_t", no_argument, &flag_t, -121 },
        { "opt_n", no_argument, &flag_n, -121 },
		{ NULL, 0, NULL, 0}
	};

FILE *fp;
void FileReader(int argc, char *argv[]);
// void GetOptions(int argc, char *argv[]);

// void ParseFlags(int argc, char* argv[], flags form);

int main(int argc, char* argv[]) {
    // char filename[300] = {'\0'};
    // filename[300] = argv[argc][300];
    // printf("%s", argv[2]);
    int flag_b = 0;
    int flag_e = 0;
    int flag_s = 0;
    int flag_t = 0;
    int flag_n = 0;
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

// void ParseFlags(int argc, char* argv[], flags form) {
//     if(argc != 0) {
//         form.b = 0;
//         form.e = 0;
//         form.s = 0;
//         form.t = 0;
//         form.n = 0;
//         int count = 1;
//         while (*argv) {
//             if (argv[count][0] == '-') {
//                 for (int i = 0; i < strlen(argv[count]); i++) {
//                     if (argv[count][1] == 'b') {
//                         form.b = 1;
//                         count++;
//                     }
//                     if (argv[count][2] == 'e') {
//                         form.e = 1;
//                         count++;
//                     }
//                     if (argv[count][3] == 's') {
//                         form.s = 1;
//                         count++;
//                     }
//                     if (argv[count][4] == 't') {
//                         form.t = 1;
//                         count++;
//                     }
//                     if (argv[count][5] == 't') {
//                         form.n = 1;
//                         count++;
//                     }
//                 }
//             }
//             if (argv[count][1] != 'bestn') {
//                 printf("%s", 'error');
//             }
//         }
//     }
// }


// void GetOptions(int argc, char *argv[]) {

// }

int getopt_long(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex) {

}