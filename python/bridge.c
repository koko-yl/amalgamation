#include <Python.h>
#ifdef _HAS_H
#include "python.h"
#else
extern unsigned char *source_py;
extern int source_py_len;
#endif
void python() {
    source_py[source_py_len] = 0;
    Py_Initialize();
    PyRun_SimpleString((const char*)source_py);
    PyRun_SimpleString("python();");
    Py_FinalizeEx();
}
