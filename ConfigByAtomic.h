//
// Created by will on 10/19/17.
//

#ifndef MYSTATICS_CONFIGBYATOMIC_H
#define MYSTATICS_CONFIGBYATOMIC_H

#include <string>
#include <memory>
#include <atomic>

namespace cc
{
    struct ConfigByAtomic
    {
        ConfigByAtomic()
        {
            test1 = 0;

            std::cout << "ConfigByAtomic ctor" << std::endl;
        }

        ConfigByAtomic(const ConfigByAtomic &config)
        {
            test1 = config.test1;

            std::cout << "ConfigByAtomic copy ctor" << std::endl;
        }

        ConfigByAtomic(ConfigByAtomic &&config) noexcept
        {
            test1 = config.test1;

            std::cout << "ConfigByAtomic move ctor" << std::endl;
        }

        ConfigByAtomic& operator =(const ConfigByAtomic &config)
        {
            std::cout << "ConfigByAtomic copy assignment operator" << std::endl;

            test1 = config.test1;
            testX.store(config.testX);
        }

        ConfigByAtomic& operator =(ConfigByAtomic &&config) noexcept
        {
            std::cout << "ConfigByAtomic move assignment operator" << std::endl;

            test1 = config.test1;
            testX.store(config.testX);
        }

        int test1;

        std::atomic<int> testX{0};
    };
}

#endif //MYSTATICS_CONFIGBYATOMIC_H
