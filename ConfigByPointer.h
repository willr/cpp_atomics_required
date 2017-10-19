//
// Created by will on 10/19/17.
//

#ifndef MYSTATICS_CONFIGBYPOINTER_H
#define MYSTATICS_CONFIGBYPOINTER_H

#include <string>

namespace cc
{
    struct ConfigByPointer
    {
        ConfigByPointer()
        {
            test1 = 0;
            testval = "";

            std::cout << "ConfigByPointer ctor" << std::endl;
        }

        ConfigByPointer(const ConfigByPointer &config)
        {
            test1 = config.test1;

            std::cout << "ConfigByPointer copy ctor" << std::endl;
        }

        ConfigByPointer(ConfigByPointer &&config) noexcept
        {
            test1 = config.test1;

            std::cout << "ConfigByModule move ctor" << std::endl;
        }

        ConfigByPointer& operator =(const ConfigByPointer &config)
        {
            std::cout << "ConfigByPointer copy assignment operator" << std::endl;

            test1 = config.test1;
            testval = config.testval;
        }

        ConfigByPointer& operator =(ConfigByPointer &&config) noexcept
        {
            std::cout << "ConfigByPointer move assignment operator" << std::endl;

            test1 = config.test1;
            testval = std::move(config.testval);
        }

    public:
        int test1;
        std::string testval;
    };
}

#endif //MYSTATICS_CONFIGBYPOINTER_H
