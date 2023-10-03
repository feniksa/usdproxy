#pragma once

#ifdef EXPORT
    #define LIBUSDPROXY_API __declspec(dllexport)
#else
    #define LIBUSDPROXY_API __declspec(dllimport)
#endif

namespace usdproxy
{

class Test2
{
public:
    LIBUSDPROXY_API void DoSomething();
};

}

extern "C"
{
    LIBUSDPROXY_API int dostage();
}