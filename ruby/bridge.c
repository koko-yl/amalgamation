#include <ruby.h>

#ifdef _HAS_H
#include "ruby.h"
#else
extern unsigned char *source_rb;
extern int source_rb_len;
#endif

void ruby() {
    source_rb[source_rb_len] = 0;
    ruby_init();
    rb_eval_string((const char *)source_rb);
    rb_eval_string("ruby()");
    ruby_cleanup(0);
}