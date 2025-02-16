#include <jni.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#ifdef _HAS_H
#include "java.h"
#else
extern jbyte *source_class;
extern unsigned int source_class_len;
#endif

void java() {
    if (fork() == 0) {
        JavaVM *vm;
        JNIEnv *env;
        JavaVMInitArgs vm_args;
        jclass cls;
        jmethodID mid;
        jbyte *bytes = source_class;
        int size = source_class_len;
        vm_args.version = JNI_VERSION_1_8;
        vm_args.nOptions = 0;
        JNI_CreateJavaVM(&vm, (void **)&env, &vm_args);
        cls = (*env)->DefineClass(env, "source", NULL, bytes, size);
        mid = (*env)->GetStaticMethodID(env, cls, "java", "()V");
        (*env)->CallStaticVoidMethod(env, cls, mid, NULL);
        (*vm)->DestroyJavaVM(vm);
        exit(0);
    } 
    else
        wait(0);
}
