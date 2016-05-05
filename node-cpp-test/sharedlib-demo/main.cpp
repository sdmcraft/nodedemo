#include<stdio.h>
#include </usr/include/node/node.h>
#include </usr/include/v8.h>
#include"shared.h"

namespace myspace{
    int add(void)
    {
        unsigned int a = 1;
        unsigned int b = 2;
        unsigned int result = 0;

        result = addValues(a,b);

        printf("\n The result is [%u]\n",result);
        return 0;
    }
}
using namespace v8;

Handle<Value> HelloWorld(const Arguments& args)
{
  HandleScope scope;
  myspace::add();
  //return scope.Close(String::New("Hello World123, Greetings from C++"));
  return scope.Close(Number::New(myspace::add()));
}

void init(Handle<Object> exports)
{
  exports->Set(String::NewSymbol("HelloWorld"),
      FunctionTemplate::New(HelloWorld)->GetFunction());
}

NODE_MODULE(nodecpptest, init)
