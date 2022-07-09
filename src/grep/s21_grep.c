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
    // pattern
    char pat[2048] = {0};
    opt option_field;
    // struct = 0
    StructToNull(&option_field);
    // put flag 1 or 0
    FlagPut(argc, argv, &option_field, pat);

    if (option_field.l || option_field.c) {
        option_field.i = 0;
        option_field.n = 0;
        option_field.v = 0;
    }
    // if "e" option empty
    if (!option_field.e) {
        strcat(pat, argv[optind]);
        optind++;
    }
    // every arg and total argc
    while (optind < argc) {
        FileOpen(argc, argv, &option_field, pat);
        optind++;
    }
    return 0;
}

void StructToNull(opt *option_field) {
    option_field->e = 0;
    option_field->i = 0;
    option_field->v = 0;
    option_field->c = 0;
    option_field->l = 0;
    option_field->n = 0;
}

void FlagPut(int argc, char**argv, opt *option_field, char *pat) {
    int kolvo = 0;
    int options = 0;
    while ((options = getopt_long(argc, argv, "e:inclv", NULL, NULL)) != -1) {
        switch (options) {
        case 'e':
            Pat_E(&kolvo, pat, optarg);
            option_field->e = 1;
            break;
        case 'i':
            option_field->i = 1;
            break;
        case 'v':
            option_field->v = 1;
            break;
        case 'c':
            option_field->c = 1;
            break;
        case 'l':
            option_field->l = 1;
            break;
        case 'n':
            option_field->n = 1;
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

void FileOpen(char argc, char**argv, opt *option_field, char *pat) {
    FILE *fp = fopen(argv[optind], "r");
    if (fp) {
        UseOptions(argc, argv, fp, pat, option_field);
        fclose(fp);
    } else {
        fprintf(stderr, "s21_grep: %s: No such file or directory\n", argv[optind]);
    }
}

void UseOptions(char argc, char **argv, FILE *fp, char *pat, opt *option_field) {
    regex_t reg[2048];
    char *str = NULL;
    size_t len = 0;
    int str_count = 1;
    int counter = 0;
    int match = 0;
/* option -i */
    if (option_field->i) {
        regcomp(reg, pat, 0003);  // pointer compiler regex, my_pattern, REG_ICASE 0002 + REG_EXTENDED 0001
    } else {
        regcomp(reg, pat, 0001);  // pointer compiler regex, my_pattern, REG_EXTENDED 0001
    }
    while (getline(&str, &len, fp) != -1) {
        if (optind != argc - 1) {
            option_field->cnt_file = 1;
        }
        int err = 0;
        err = regexec(reg, str, 0, NULL, 0);
/* option -v */
        if (err == 1) {
            if (option_field->v) {
                printf("%s", str);
            }
        }
/* option -n */
        if (err == 0 && !option_field->v && !option_field->l && !option_field->c) {
            if (option_field->n) {
                    printf("%d:", str_count);
                }
            printf("%s", str);
        }
/* option -l */
        if (err == 0 && counter == 0) {
            counter++;
            if (option_field->l) {
                printf("%s\n", argv[optind]);
            }
        }
        if (err == 0) {
            match++;
        }
        str_count++;
    }
/* option -c */
    if (option_field->c) {
        printf("%d\n", match);
    }
    regfree(reg);
    free(str);
}
