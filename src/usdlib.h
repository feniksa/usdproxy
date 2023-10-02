#pragma once

#ifdef EXPORT
    #define LIBUSDPROXY_API __declspec(dllexport)
#else
    #define LIBUSDPROXY_API __declspec(dllimport)
#endif

class Test
{
    void test() {}
};

extern "C"
{


    LIBUSDPROXY_API int dostage();
}