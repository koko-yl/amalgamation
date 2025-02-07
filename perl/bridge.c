#include <EXTERN.h>
#include <perl.h>
#ifdef _HAS_H
#include "perl.h"
#else
extern unsigned char *source_pl;
extern int source_pl_len;
#endif

void perl() {
    int argc = 3;
    char **argv = (char **)malloc(sizeof(char *));
    argv[0] = NULL;
    argv[1] = strdup("-e");
    argv[2] = source_pl;
    source_pl[source_pl_len] = 0;
    PerlInterpreter *my_perl = perl_alloc();
    perl_construct(my_perl);
    perl_parse(my_perl, NULL, argc, argv, NULL);
    char *args[0] = {};
    eval_pv("perl()", 0);
    perl_destruct(my_perl);
    perl_free(my_perl);
    PERL_SYS_TERM();
    free(argv);
}