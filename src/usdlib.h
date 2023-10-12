#pragma once

#ifdef EXPORT
    #define LIBUSDPROXY_API __declspec(dllexport)
#else
    #define LIBUSDPROXY_API __declspec(dllimport)
#endif

namespace usdproxy
{}