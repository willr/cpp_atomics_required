#include <iostream>

#include <boost/thread.hpp>

#include "Manager.h"

enum {
    ByFunction,
    ByModule,
    ByParam,
    ByAtomic,
    ByPointer
};

static constexpr int run = ByModule;

int main()
{
    cc::ConfigByParam config = cc::ConfigByParam{};
    boost::thread t;
    // main loop
    switch(run)
    {
        case ByFunction:
            t = boost::thread(&ml::mainLoopByFunction);
            break;
        case ByModule:
            t = boost::thread(&ml::mainLoopByModule);
            break;
        case ByParam:
            t = boost::thread{boost::bind(&ml::mainLoopByParam, config)};
            break;
        case ByAtomic:
            t = boost::thread(&ml::mainLoopByAtomic);
            break;
        case ByPointer:
            t = boost::thread(&ml::mainLoopByPointer);
            break;
        default:
            throw "Bad Value";
    }

    while(true)
    {
        sleep(1);
    }
}