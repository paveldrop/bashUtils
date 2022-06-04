#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <string.h>
#include <getopt.h>


struct option_field{
    int b;
    int e;
    int s;
    int t;
    int n;
    int v;
};

static struct option long_options[] = {
            { "number-nonblank", 0, 0, 'b'},
            { "squeeze-blank", 0, 0, 's'},
            { "number", 0, 0, 'n'},
            { NULL, 0, NULL, 0}
};

void GetOptions(int argc, char *argv[], struct option_field *opt);
void StructToNull(struct option_field *opt);
// void GetOptions(int argc, char **argv, char future_char, struct option_field *opt, char chr, int print, FILE*fp);
void FlagsForRun(int argc, char **argv, struct option_field opt);
void FlagPut(char total, struct option_field *opt);
void EmptyString(char chr, int *count, char future_char, int *print, int *lift, struct option_field opt);
void NumEveryString(int *count, char future_char);
void NumNonEmptyString(char future_char, char chr, int *count);
void AddDollar(char chr);
void VisibleTab(char chr, int *print);
void InvisibleSymbols(int chr, int *print);

#endif // SRC_CAT_S21_CAT_H_s