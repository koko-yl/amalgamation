#include <node.h>
#include <uv.h>
int _js_init = 0;
std::unique_ptr<node::MultiIsolatePlatform> platform;
std::unique_ptr<node::CommonEnvironmentSetup> setup;
v8::Global<v8::Function> require;
void run_js(node::MultiIsolatePlatform *platform,
            node::CommonEnvironmentSetup *setup, const char *code) {
                {
    v8::Isolate *isolate = setup->isolate();
    v8::Locker locker(isolate);
    v8::Isolate::Scope isolateScope(isolate);
    v8::HandleScope handle_scope(isolate);
    v8::Context::Scope context_scope(setup->context());
    v8::Local<v8::Value> function_args[1];
    function_args[0] = v8::String::NewFromUtf8Literal(isolate, "vm");
    v8::Local<v8::Function> run_in_ctx =
        require.Get(isolate)
            ->Call(setup->context(), v8::Null(isolate), 1, function_args)
            .ToLocalChecked()
            .As<v8::Object>()
            ->Get(setup->context(),
                  v8::String::NewFromUtf8Literal(isolate, "runInThisContext"))
            .ToLocalChecked()
            .As<v8::Function>();
    function_args[0] =
        v8::String::NewFromUtf8(isolate, code, v8::NewStringType::kNormal)
            .ToLocalChecked();
    run_in_ctx->Call(setup->context(), v8::Null(isolate), 1, function_args);
            }
}
int js_init() {
    int argc = 1;
    char **argv = (char **)malloc(sizeof(char *));
    argv[0] = strdup("hi");
    argv = uv_setup_args(argc, argv);
    argv = uv_setup_args(argc, argv);
    std::vector<std::string> args(argv, argv + argc);
    std::vector<std::string> exec_args;
    std::vector<std::string> errors;
    node::InitializeNodeWithArgs(&args, &exec_args, &errors);
    platform = node::MultiIsolatePlatform::Create(4);
    v8::V8::InitializePlatform(platform.get());
    v8::V8::Initialize();
    setup = node::CommonEnvironmentSetup::Create(platform.get(), &errors, args,
                                                 exec_args);
    v8::Isolate *isolate = setup->isolate();
    node::Environment *node_env = setup->env();
    v8::Locker locker(isolate);
    v8::Isolate::Scope isolateScope(isolate);
    v8::HandleScope handle_scope(isolate);
    v8::Context::Scope context_scope(setup->context());
    node::LoadEnvironment(node_env,
                          [&](const node::StartExecutionCallbackInfo &info)
                              -> v8::MaybeLocal<v8::Value> {
                              require.Reset(isolate, info.native_require);
                              run_js(
                                  platform.get(), setup.get(),
                                  "function javascript() {\n    "
                                  "console.log(\"Sent from Javascript\");\n}");
                              return v8::Null(isolate);
                          });
    return 0;
}
extern "C" void javascript() {
    if (!_js_init) {
        _js_init = 1;
        js_init();
    }
    run_js(platform.get(), setup.get(), "javascript()");
}