//
// Created by will on 10/19/17.
//

#ifndef MYSTATICS_CONFIGBYMODULE_H
#define MYSTATICS_CONFIGBYMODULE_H

#include <string>

namespace cc
{
    struct ConfigByModule
    {
        ConfigByModule()
        {
            test1 = 0;
            testval = "";

            std::cout << "ConfigByModule ctor" << std::endl;
        }

        ConfigByModule(const ConfigByModule &config)
        {
            test1 = config.test1;

            std::cout << "ConfigByModule copy ctor" << std::endl;
        }

        ConfigByModule(ConfigByModule &&config) noexcept
        {
            test1 = config.test1;

            std::cout << "ConfigByModule move ctor" << std::endl;
        }

        ConfigByModule& operator =(const ConfigByModule &config)
        {
            std::cout << "ConfigByModule copy assignment operator" << std::endl;

            test1 = config.test1;
            testval = config.testval;
        }

        ConfigByModule& operator =(ConfigByModule &&config) noexcept
        {
            std::cout << "ConfigByModule move assignment operator" << std::endl;

            test1 = config.test1;
            testval = std::move(config.testval);
        }

    public:
        int test1;
        std::string testval;
    };
}


#endif //MYSTATICS_CONFIGBYMODULE_H
