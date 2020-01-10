#include <node.h>
#include <stdio.h>
#include <string>
using namespace std;

namespace idcard_XFS {

using v8::Exception;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

//Add
void Add(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  //参数1
  int param1 = args[0]->IntegerValue();
  //参数2
  int param2 = args[1]->IntegerValue();

  int res = param1 + param2;
  args.GetReturnValue().Set(Number::New(isolate, res));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "add", Add);
}

NODE_MODULE(idcard_XFS, init)

}  
