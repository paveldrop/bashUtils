#include "s21_cat.h"



// void InvisibleSymbols(char chr, int *print);


int main(int argc, char* argv[]) {
    struct option_field opt;
    FILE *fp;
    char chr, future_char = '\n';
    int PRINT, long_index, lift = 0, count = 0, total = 0;;
    StructToNull(&opt);
    while ((total = getopt_long(argc, argv, "beEstnv",
                                long_options, &long_index)) != -1) {
        FlagPut(total, &opt);
    }
    if (argc > 1) {
        for (int i = 0; argv++ && (i < argc - 1); i++) {
            if ((strlen((*argv)) > 2) && (**(argv) != '-')) {
                if ((fp = fopen(*argv, "r")) == NULL) {
                    printf("s21_cat: %s: No such file or directory", *argv);
                } else {
                    while ((chr = getc(fp)) != EOF) {
                        PRINT = 1;
                    if (opt.s) {
                        EmptyString(chr, future_char, &PRINT, &lift);
                    }
                    if (opt.n && !opt.b) {
                        NumEveryString(&count, future_char);
                    }
                    if (opt.b) {
                        NumNonEmptyString(chr, future_char, &count);
                    }
                    if (opt.t) {
                        VisibleTab(chr, &PRINT);
                    }
                    if (opt.e) {
                        AddDollar(chr);
                    }
                    if (opt.v) {
                        // InvisibleSymbols(chr, &PRINT);
                    }
                    if (PRINT) {
                        putc(chr, stdout);
                    }
                    future_char = chr;
                }
                fclose(fp);
                }
            }
        }
    }

    return 0;;

    return 0;
}


// void GetOptions(int argc, char **argv, struct option_field *opt) {
//     // StructToNull(&opt);
//     // const char* short_options = "beEstn";
//     int long_index = 0;
//     int total = getopt_long(argc, argv, "beEstnv", long_options, &long_index);

//     while (total != -1) {
//         FlagPut(total, opt);
//     }
// }
void StructToNull(struct option_field *opt) {
    opt->b = 0;
    opt->e = 0;
    opt->s = 0;
    opt->t = 0;
    opt->n = 0;
    opt->v = 0;
}

void FlagPut(char total, struct option_field *opt) {
    if (total == 'b') {
        opt->b = total;
    } else if (total == 'e') {
        opt->v = 1;
        opt->e = total;
    } else if (total == 'n') {
        opt->n = total;
    } else if (total == 's') {
        opt->s = total;
    } else if (total == 't') {
        opt->v = 1;
        opt->t = total;
    } else if (total == 'v') {
        opt->v = total;
    } else if (total == 'E') {
        opt->e = total;
    } else if (total == 'T') {
        opt->t = total;
    }
}

// void FlagsForRun(int argc, char **argv, struct option_field opt) {
//     FILE *fp;
//     char chr, future_char = '\n';
//     int print = 0, lift = 0, count = 0;
//     for (int i = 0; argv++ && (i < argc - 1); i++) {
//         if ((strlen((*argv)) > 2) && (**(argv) != '-')) {
//             if ((fp = fopen(*argv, "r")) == NULL) {
//                 printf("s21_cat: %s: No such file or directory", *argv);
//             } else {
//                 while ((chr = getc(fp)) != EOF) {
//                     print = 1;
//                     if (opt.s) {
//                         EmptyString(chr, future_char, &print, &lift);
//                     }
//                     if (opt.n && !opt.b) {
//                         NumEveryString(&count, future_char);
//                     }
//                     if (opt.b) {
//                         NumNonEmptyString(chr, future_char, &count);
//                     }
//                     if (opt.t) {
//                         VisibleTab(chr, &print);
//                     }
//                     if (opt.e) {
//                         AddDollar(chr);
//                     }
//                     if (opt.v) {
//                         // InvisibleSymbols(chr, &print);
//                     }
//                     if (print) {
//                         putc(chr, stdout);
//                     }
//                     future_char = chr;
//                 }
//                 fclose(fp);
//                 }
//             }
//         }
//     }
void EmptyString(char chr, char future_char, int *print, int *lift) {
    if ((chr == '\n') && (future_char == '\n')) {
        *lift += 1;
    }
    if (chr != '\n') {
        *lift = 0;
        *print = 1;
    }
    if (*lift > 1) {
        *print = 0;
    }
}

void NumEveryString(int *count, char future_char) {
    // while(!feof(fp)) {
    //         fgets(text, 1000, fp);
    //         printf("%6d\t%s", *count++, text);
    //     }
    if (future_char == '\n') {
        printf("%6d\t", *count += 1);
    }
}


void NumNonEmptyString(char future_char, char chr, int *count) {
    // while(!feof(fp)) {
    //         fgets(text, 1000, fp);
    //         if(strlen(text) > 1) {
    //         printf("%6d\t%s", count++, text);
    //         } else {
    //             printf("%s", text);
    //         }
    //     }
    if (chr != '\n' && future_char == '\n') {
        printf("%6d\t", *count += 1);
    }

}

void AddDollar(char chr) {
    if (chr == '\n') {
        printf("$");
    }
}

void VisibleTab(char chr, int *print) {
    if (chr == '\t') {
        printf("^I");
        *print = 0;
    }
}

// void InvisibleSymbols(char chr, int *print) {

// }

