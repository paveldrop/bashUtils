#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_
#include <string.h>
#include <stdio.h>
#include <getopt.h>

struct option_field{
    int e;
    int i;
    int v;
    int c;
    int l;
    int n;
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
void FlagPut(int total, struct option_field *opt);


#endif // SRC_GREP_S21_GREP_H_