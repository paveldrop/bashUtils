/* 
   -i  Игнорирует регистр символов при сравнениях.
   -v  Выдает все строки, за исключением содержащих образец.
   -c  Выдает только количество строк, содержащих образец.
   -l  Выдает только имена файлов, содержащих сопоставившиеся строки, по одному в строке. Если образец найден в нескольких строках файла, имя файла не повторяется.
   -n  Выдает перед каждой строкой ее номер в файле (строки нумеруются с 1).
   -e  example grep -e pattern1 -e pattern2 -e pattern3
   grep [options] template [file_name]
   использование regex.h и pcre
*/


#include "s21_grep.h"


int main(int argc, char* argv[]) {
    char pat[2048];
    struct option_field opt;
    struct option l_options;
    StructToNull(&opt);
    FlagPut(argc, argv, &opt, pat, l_options);
    if (opt.l || opt.c) {
        opt.i = 0;
        opt.n = 0;
        opt.v = 0;
    }

    if (!opt.e) {
        strcat(pat, argv[optind]);
        optind++;
    }

    while (optind < argc) {
        FileOpen(argc, argv, opt, pat);
        optind++;
    }
}

void StructToNull(struct option_field *opt) {
    opt->e = 0;
    opt->i = 0;
    opt->v = 0;
    opt->c = 0;
    opt->l = 0;
    opt->n = 0;
}

void FlagPut(int argc, char**argv, struct option_field *opt, char *pat, struct option) {
    int kolvo = 0;
    int options, long_index = 0;
    while ((options =  getopt_long(argc, argv, "e:inclv", long_options, &long_index)) != 0) {
        switch (options) {
        case 'e':
            Pat_E(&kolvo, pat, optarg);
            opt->e = 1;
            break;
        case 'i':
            opt->i = 1;
            break;
        case 'v':
            opt->v = 1;
            break;
        case 'c':
            opt->c = 1;
            break;
        case 'l':
            opt->l = 1;
            break;
        case 'n':
            opt->n = 1;
            break;
        default:
            fprintf(stderr, "usage: grep [e:ivcln] [file ...]\n");
            exit(1);
        }
    }
}


void Pat_E(int *kolvo, char *pat, char *optarg) {
    if (*kolvo > 0) {
        strcat(pat, "|");
    }
    *kolvo += 1;
    strcat(pat, optarg);
}

void FileOpen(char argc, char**argv, struct option_field opt, char *pat) {
    FILE *fp = fopen(argv[optind], "r");
    if (fp) {
        UseOptions(argc, argv, fp, pat, &opt);
        fclose(fp);
    } else {
        fprintf(stderr, "s21_grep: %s: No such file or directory\n", argv[optind]);
    }
}

void UseOptions(char argc, char **argv, FILE *fp, char *pat, struct option_field *opt) {
    regex_t reg[2048];
    char *str = NULL;
    size_t len = 0;
    int str_count = 1;
    int counter = 0;
    int match = 0;
/* option -i */
    if (opt->i) {
        regcomp(reg, pat, 0003);  // REG_ICASE 0002 + REG_EXTENDED 0001
    } else {
        regcomp(reg, pat, 0001);  // REG_EXTENDED 0001
    }
    while ((getline(&str, &len, fp) != -1)) {
        if (optind != argc - 1) {
            opt->cnt_file = 1;
        }
        int err = 0;
        err = regexec(reg, str, 0, NULL, 0);
/* option -v */
        if (err == 1) {
            if (opt->v) {
                if (opt->cnt_file) {
                    printf("%s:", argv[optind]);
                }
                printf("%s", str);
            }
        }
/* option -n */
        if (err == 0 && !opt->v && !opt->l && !opt->c) {
            if (opt->cnt_file > 1) {
                printf("%s:", argv[optind]);
            }
            if (opt->n) {
                    printf("%d:", str_count);
                }
            printf("%s", str);
        }
/* option -l */
        if (err == 0 && counter == 0) {
            counter++;
            if (opt->l) {
                printf("%s\n", argv[optind]);
            }
        }
        if (err == 0) {
            match++;
        }
        str_count++;
    }
/* option -c */
    if (opt->c) {
        if (opt->cnt_file) {
            printf("%s:", argv[optind]);
        }
        printf("%d\n", match);
    }
    regfree(reg);
    free(str);
}
