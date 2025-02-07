#include "node.h"
#include <sys/wait.h>
#include <unistd.h>
#ifdef _HAS_H
#include "javascript.h"
#else
extern unsigned char *source_js;
extern int source_js_len;
#endif

extern "C" void javascript() {
    if (fork() == 0) {
        source_js[source_js_len] = 0;
        std::string source_js_s((char *)source_js);
        source_js_s.append("javascript()");
        std::vector<std::string> args = {""};
        node::InitializeOncePerProcess(
            args,
            {node::ProcessInitializationFlags::kNoInitializeV8,
             node::ProcessInitializationFlags::kNoInitializeNodeV8Platform});
        std::unique_ptr<node::MultiIsolatePlatform> platform =
            node::MultiIsolatePlatform::Create(4);
        v8::V8::InitializePlatform(platform.get());
        v8::V8::Initialize();
        {
            std::vector<std::string> none = {};
            std::unique_ptr<node::CommonEnvironmentSetup> setup =
                node::CommonEnvironmentSetup::Create(platform.get(), &none,
                                                     none, none);
            v8::Isolate *isolate = setup->isolate();
            node::Environment *env = setup->env();

            {
                v8::Locker locker(isolate);
                v8::Isolate::Scope isolate_scope(isolate);
                v8::HandleScope handle_scope(isolate);
                v8::Context::Scope context_scope(setup->context());
                node::LoadEnvironment(env, source_js_s);
                node::Stop(env);
            }
        }
        v8::V8::Dispose();
        v8::V8::DisposePlatform();
        node::TearDownOncePerProcess();
        exit(0);
    } else
        wait(0);
}
