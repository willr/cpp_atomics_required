//
// Created by will on 10/19/17.
//

#include <boost/thread.hpp>
#include <iostream>

#include "Manager.h"
#include "TaskA.h"
#include "TaskB.h"

// module level static variable
static cc::ConfigByModule configModuleStatic{};
static cc::ConfigByAtomic configModuleAtomic{};
static cc::ConfigByPointer configModulePointer{};

void
runBTaskByModule()
{
    tasks::TaskB taskB{};

    taskB.runTaskByModule();
}

void
runBTaskByFunction()
{
    tasks::TaskB taskB{};

    taskB.runTaskByFunction();
}

void
ml::mainLoopByParam(cc::ConfigByParam &config)
{
    boost::thread t(boost::bind(&runTasksByParam, config));
    printf("mainLoopByParam config address: %p\n", (void *)&config);
    for( int i = 100; i < 110; i++)
    {
        std::cout << "ml::mainLoopByParam: reading value from testval: " << config.testval << std::endl;

        std::string newVal = std::string{}.append("Manager::").append(std::to_string(i));
        std::cout << "ml::mainLoopByParam: setting value to testval: " << newVal << std::endl;
        config.testval = newVal;
        sleep(1);
    }
}

void
ml::mainLoopByFunction()
{
    boost::thread t{&runTasksByFunction};
    auto config = ml::getConfigFunctionStatic();
    printf("mainLoopByFunction config address: %p\n", (void *)&config);
    for( int i = 100; i < 110; i++)
    {
        std::cout << "ml::mainLoopByFunction: reading value from testval: " << config.testval << std::endl;

        std::string newVal = std::string{}.append("Manager::").append(std::to_string(i));
        std::cout << "ml::mainLoopByFunction: setting value to testval: " << newVal << std::endl;
        config.testval = newVal;
        sleep(1);
    }
}

void
ml::mainLoopByModule()
{
    boost::thread t{&runTasksByModule};
    auto config = ml::getConfigModuleStatic();
    printf("mainLoopByModule config address: %p\n", (void *)&config);
    for( int i = 100; i < 110; i++)
    {
        std::cout << "ml::mainLoopByModule: reading value from testval: " << config.testval << std::endl;

        std::string newVal = std::string{}.append("Manager::").append(std::to_string(i));
        std::cout << "ml::mainLoopByModule: setting value to testval: " << newVal << std::endl;
        config.testval = newVal;
        sleep(1);
    }
}

void
ml::mainLoopByAtomic()
{
    boost::thread t{&runTasksByAtomic};
    auto config = ml::getConfigModuleAtomic();
    printf("mainLoopByAtomic config address: %p\n", (void *)config);
    for( int i = 100; i < 110; i++)
    {
        std::cout << "ml::mainLoopByAtomic: reading value from test1: " << config->testX << std::endl;

        std::string newVal = std::string{}.append("Manager::").append(std::to_string(i));
        std::cout << "ml::mainLoopByAtomic: setting value to test1: " << newVal << std::endl;
        config->testX = i;
        sleep(1);
    }
}

void
ml::mainLoopByPointer()
{
    boost::thread t{&runTasksByPointer};
    auto config = ml::getConfigModuleAtomic();
    printf("mainLoopByPointer config address: %p\n", (void *)config);
    for( int i = 100; i < 110; i++)
    {
        std::cout << "ml::mainLoopByPointer: reading value from test1: " << config->test1 << std::endl;

        std::string newVal = std::string{}.append("Manager::").append(std::to_string(i));
        std::cout << "ml::mainLoopByPointer: setting value to test1: " << newVal << std::endl;
        config->test1 = i;
        sleep(1);
    }
}

void
ml::runTasksByFunction()
{
    tasks::TaskA taskA{};
//    boost::thread(&runBTaskByFunction).detach();
    usleep(500);
    taskA.runTaskByFunction();
}

void
ml::runTasksByModule()
{
    tasks::TaskA taskA{};
//    boost::thread(&runBTaskByModule).detach();
    usleep(500);
    taskA.runTaskByModule();
}

void
ml::runTasksByAtomic()
{
    tasks::TaskA taskA{};
//    boost::thread(&runBTaskByAtomic).detach();
    usleep(500);
    taskA.runTaskByAtomic();
}

void
ml::runTasksByPointer()
{
    tasks::TaskA taskA{};
//    boost::thread(&runBTaskByAtomic).detach();
    usleep(500);
    taskA.runTaskByPointer();
}

void
ml::runTasksByParam(cc::ConfigByParam &config)
{
    tasks::TaskA taskA{};

    usleep(500);
    taskA.runTaskByParam(config);
}


cc::ConfigByFunction&
ml::getConfigFunctionStatic()
{
    // this is held as a function static
    static cc::ConfigByFunction config{};
    return config;
}

cc::ConfigByModule&
ml::getConfigModuleStatic()
{
    return configModuleStatic;
}

cc::ConfigByAtomic*
ml::getConfigModuleAtomic()
{
    return &configModuleAtomic;
}

cc::ConfigByPointer*
ml::getConfigModulePointer()
{
    return &configModulePointer;
}