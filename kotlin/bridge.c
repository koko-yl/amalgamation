#include <jni.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#ifdef _HAS_H
#include "kotlin.h"
#else
extern jbyte *sourcekt_class;
extern unsigned int sourcekt_class_len;
#endif

void kotlin() {
    if (fork() == 0) {
        JavaVM *vm;
        JNIEnv *env;
        JavaVMInitArgs vm_args;
        jclass cls;
        jmethodID mid;
        jbyte *bytes = sourcekt_class;
        int size = sourcekt_class_len;
        vm_args.version = JNI_VERSION_1_8;
        vm_args.nOptions = 0;
        JNI_CreateJavaVM(&vm, (void **)&env, &vm_args);
        cls = (*env)->DefineClass(env, "SourceKt", NULL, bytes, size);
        mid = (*env)->GetStaticMethodID(env, cls, "kotlin", "()V");
        (*env)->CallStaticVoidMethod(env, cls, mid, NULL);
        (*vm)->DestroyJavaVM(vm);
        exit(0);
    } else
        wait(0);
}
