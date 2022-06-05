#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
    int i, sum = 0;
    // char textvar[100] = {'\0'};
    // if ((strlen((*argv)) > 2) && (**argv) != '-') *textvar = argv[3];
    printf("**argv = %d\n", **argv);
    printf("argc = %d\n", argc);
    printf("что сейчас в argv[]\n");
    if(argc > 1) {
        for(i = 0; i < argc; i++) {
            printf("argv[%d] = %s\n", i, argv[i]);
            sum += atoi(argv[i]);
        }
    }
    return 0;
}