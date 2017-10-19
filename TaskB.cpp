//
// Created by will on 10/19/17.
//

#include <unistd.h>
#include <iostream>

#include "TaskB.h"
#include "ConfigByFunction.h"
#include "ConfigByModule.h"
#include "Manager.h"

void tasks::TaskB::runTaskByFunction()
{
    auto config = ml::getConfigFunctionStatic();
    for( int i = 1000; i < 1010; i++)
    {
        std::cout << "tasks::TaskB::runTaskByFunction: reading value from testval: " << config.testval << std::endl;

        std::string newVal = std::string{}.append("TaskB::").append(std::to_string(i));
        std::cout << "tasks::TaskB::runTaskByFunction: setting value to testval: " << newVal << std::endl;
        config.testval = newVal;
        sleep(1);
    }
}

void tasks::TaskB::runTaskByModule()
{
    auto config = ml::getConfigModuleStatic();
    for( int i = 1000; i < 1010; i++)
    {
        std::cout << "tasks::TaskB::runTaskByModule: reading value from testval: " << config.testval << std::endl;

        std::string newVal = std::string{}.append("TaskB::").append(std::to_string(i));
        std::cout << "tasks::TaskB::runTaskByModule: setting value to testval: " << newVal << std::endl;
        config.testval = newVal;
        sleep(1);
    }
}

void tasks::TaskB::runTaskByAtomic()
{
    auto config = ml::getConfigModuleAtomic();
    for( int i = 0; i < 10; i++)
    {
        std::cout << "tasks::TaskB::runTaskByAtomic: reading value from test1: " << config->test1 << std::endl;

        std::string newVal = std::string{}.append("TaskB::").append(std::to_string(i));
        std::cout << "tasks::TaskB::runTaskByAtomic: setting value to test1: " << newVal << std::endl;
        config->test1 = i;
        sleep(1);
    }
}

void tasks::TaskB::runTaskByParam(cc::ConfigByParam config)
{
    for( int i = 1000; i < 1010; i++)
    {
        std::cout << "tasks::TaskB::runTaskByParam: reading value from testval: " << config.testval << std::endl;

        std::string newVal = std::string{}.append("TaskB::").append(std::to_string(i));
        std::cout << "tasks::TaskB::runTaskByParam: setting value to testval: " << newVal << std::endl;
        config.testval = newVal;
        sleep(1);
    }
}