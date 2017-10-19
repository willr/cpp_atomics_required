//
// Created by will on 10/19/17.
//


#include <unistd.h>
#include <iostream>

#include "TaskA.h"
#include "ConfigByFunction.h"
#include "Manager.h"

void tasks::TaskA::runTaskByFunction()
{
    auto config = ml::getConfigFunctionStatic();
    printf("runTaskByFunction config address: %p\n", (void *)&config);
    for( int i = 0; i < 10; i++)
    {
        std::cout << "tasks::TaskA::runTaskByFunction: reading value from testval: " << config.testval << std::endl;

        std::string newVal = std::string{}.append("TaskA::").append(std::to_string(i));
        std::cout << "tasks::TaskA::runTaskByFunction: setting value to testval: " << newVal << std::endl;
        config.testval = newVal;
        sleep(1);
    }
}

void tasks::TaskA::runTaskByModule()
{
    auto config = ml::getConfigModuleStatic();
    printf("runTaskByModule config address: %p\n", (void *)&config);
    for( int i = 0; i < 10; i++)
    {
        std::cout << "tasks::TaskA::runTaskByModule: reading value from testval: " << config.testval << std::endl;

        std::string newVal = std::string{}.append("TaskA::").append(std::to_string(i));
        std::cout << "tasks::TaskA::runTaskByModule: setting value to testval: " << newVal << std::endl;
        config.testval = newVal;
        sleep(1);
    }
}

void tasks::TaskA::runTaskByAtomic()
{
    auto config = ml::getConfigModuleAtomic();
    printf("runTaskByAtomic config address: %p\n", (void *)config);
    for( int i = 0; i < 10; i++)
    {
        std::cout << "tasks::TaskA::runTaskByAtomic: reading value from test1: " << config->testX << std::endl;

        std::string newVal = std::string{}.append("TaskA::").append(std::to_string(i));
        std::cout << "tasks::TaskA::runTaskByAtomic: setting value to test1: " << newVal << std::endl;
        config->testX = i;
        sleep(1);
    }
}

void tasks::TaskA::runTaskByPointer()
{
    auto config = ml::getConfigModulePointer();
    printf("runTaskByPointer config address: %p\n", (void *)config);
    for( int i = 0; i < 10; i++)
    {
        std::cout << "tasks::TaskA::runTaskByPointer: reading value from test1: " << config->test1 << std::endl;

        std::string newVal = std::string{}.append("TaskA::").append(std::to_string(i));
        std::cout << "tasks::TaskA::runTaskByPointer: setting value to test1: " << newVal << std::endl;
        config->test1 = i;
        sleep(1);
    }
}

void tasks::TaskA::runTaskByParam(cc::ConfigByParam config)
{
    for( int i = 0; i < 10; i++)
    {
        std::cout << "tasks::TaskA::runTaskByParam: reading value from testval: " << config.testval << std::endl;

        std::string newVal = std::string{}.append("TaskA::").append(std::to_string(i));
        std::cout << "tasks::TaskA::runTaskByParam: setting value to testval: " << newVal << std::endl;
        config.testval = newVal;
        sleep(1);
    }
}

