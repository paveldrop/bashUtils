#include <stdio.h>
#include <string.h>
#include <getopt.h>

typedef struct {
    int b = 0;
    int e = 0;
    int s = 0;
    int t = 0;
    int n = 0;
} flags;

FILE *fp;

#define no_argument            0  //  если НЕ имеем аргумент в командной строке
#define required_argument      1  //  если имеем аргумент в командной строке
#define optional_argument      2
// const struct option long_options[] = {
// 		{ "opt_b", no_argument, &flag_b, 1 },
// 		{ "opt_e", no_argument, &flag_e, 10 },
// 		{ "opt_s", no_argument, &flag_s, -121 },
//         { "opt_t", no_argument, &flag_t, -121 },
//         { "opt_n", no_argument, &flag_n, -121 },
// 		{ NULL, 0, NULL, 0}
// 	};


//  void FileReader(int argc, char *argv[]);
//  int getopt_long(int argc, char * const argv[], const char *optstring, const struct option *long_options, int *longindex);