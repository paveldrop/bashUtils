#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_
#include <string.h>
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

struct option_field{
    int e;
    int i;
    int v;
    int c;
    int l;
    int n;
    int cnt_file;
    int countFile;
};


 static struct option long_options[] = {
            {"ignore-case", 0, 0, 'i'},
            {"invert-match", 0, 0, 'v'},
            {"count", 0, 0, 'c'},
            {"files-with-matches", 0, 0, 'l'},
            {"line-number", 0, 0, 'n'},
            {NULL, 0, NULL, 0}
};

void StructToNull(struct option_field *opt);
void FlagPut(int argc, char**argv, struct option_field *opt, char *pat, struct option);
void Pat_E(int *counter, char *pattern, char *optarg);
void FileOpen(char argc, char**argv, struct option_field opt, char *pat);
void UseOptions(char argc, char **argv, FILE *fp, char *pat, struct option_field *opt);


#endif // SRC_GREP_S21_GREP_H_