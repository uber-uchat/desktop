#include <stdio.h>
#include <nan.h>
#include <dlfcn.h>
#include <sys/types.h>

typedef int (*ptrace_ptr_t) (int _request, pid_t _pid, caddr_t _addr, int _data);
#if !defined(PT_DENY_ATTACH)
#define PT_DENY_ATTACH 31
#endif

void DisableLLDB(const Nan::FunctionCallbackInfo<v8::Value>& info) {

  // Validate the number of arguments.
  if (info.Length() < 1) {
    Nan::ThrowTypeError("Arity mismatch");
    return;
  }

  void* handle = dlopen(0, RTLD_GLOBAL | RTLD_NOW);
  ptrace_ptr_t ptrace_ptr = (ptrace_ptr_t)dlsym(handle, "ptrace");
  ptrace_ptr(PT_DENY_ATTACH, 0, 0, 0);
  dlclose(handle);
}

void Init(v8::Local<v8::Object> exports) {
  // Bind the `DisableLLDB` function as the `disable_lldb` export.
  exports->Set(Nan::New("deny_ptrace").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(DisableLLDB)->GetFunction());
}

NODE_MODULE(deny_ptrace, Init)
