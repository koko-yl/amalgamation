#include "node.h"
#include <sys/wait.h>
#include <unistd.h>

#ifdef _HAS_H
#include "typescript.h"
#else
extern unsigned char *source_ts;
extern int source_ts_len;
#endif

extern "C" void typescript() {
    if (fork() == 0) {
        source_ts[source_ts_len] = 0;
        std::string source_ts_s((char *)source_ts);
        source_ts_s.append("typescript()");
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
                node::LoadEnvironment(env, source_ts_s);
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
