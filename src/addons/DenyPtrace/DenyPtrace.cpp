#include <stdio.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <node.h>

using v8::FunctionCallbackInfo;
using v8::Local;
using v8::Object;
using v8::Value;

typedef int (*ptrace_ptr_t) (int _request, pid_t _pid, caddr_t _addr, int _data);
#if !defined(PT_DENY_ATTACH)
#define PT_DENY_ATTACH 31
#endif

void DisableLLDB(const FunctionCallbackInfo<Value>& args) {

  void* handle = dlopen(0, RTLD_GLOBAL | RTLD_NOW);
  ptrace_ptr_t ptrace_ptr = (ptrace_ptr_t)dlsym(handle, "ptrace");
  ptrace_ptr(PT_DENY_ATTACH, 0, 0, 0);
  dlclose(handle);
}

void Init(Local<Object> exports) {
   NODE_SET_METHOD(exports, "deny_ptrace", DisableLLDB);
}

NODE_MODULE(deny_ptrace, Init)
