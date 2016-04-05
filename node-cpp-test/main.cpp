#include <node.h>
#include <v8.h>
 
using namespace v8;
 
Handle<Value> HelloWorld(const Arguments& args) 
{
  HandleScope scope;
  return scope.Close(String::New("Hello World, Greetings from C++"));
}
 
void init(Handle<Object> exports) 
{
  exports->Set(String::NewSymbol("HelloWorld"),
      FunctionTemplate::New(HelloWorld)->GetFunction());
}
 
NODE_MODULE(nodecpptest, init)
