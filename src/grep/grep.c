/* -i  Игнорирует регистр символов при сравнениях.
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
    // строка для шаблона
    char SEARCH_STRING[8192];
    struct option_field opt;
    FILE *fp;
    // char chr, future_char = '\n';
    // char *textvar = {'\0'};
    // if ((strlen((*argv)) > 2) && (**argv) != '-') textvar = *argv;
    int print, long_index, lift = 0, count = 0, total = 0;
    StructToNull(&opt);
    while ((total = getopt_long(argc, argv, "eivcln",
                                long_options, &long_index)) != -1) {
        FlagPut(total, &opt);
    }
    if (argc > 1) {
        for (int i = 0; argv++ && (i < argc - 1); i++) {
            if ((strlen((*argv)) > 2) && (**(argv) != '-')) {
                if ((fp = fopen(*argv, "r")) == NULL) {
                    printf("s21_cat: %s: No such file or directory", *argv);
                } else {



                }
            }

        }
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

void FlagPut(int total, struct option_field *opt) {
    if (total == 'e') {
        opt->e = total;
    } else if (total == 'i') {
        opt->i = total;
    } else if (total == 'v') {
        opt->v = total;
    } else if (total == 'c') {
        opt->c = total;
    } else if (total == 'l') {
        opt->l = total;
    } else if (total == 'n') {
        opt->n = total;
    }
}