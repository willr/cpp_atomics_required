//
// Created by will on 10/19/17.
//

#ifndef MYSTATICS_CONFIGBYFUNCTION_H
#define MYSTATICS_CONFIGBYFUNCTION_H

#include <string>

namespace cc
{
    struct ConfigByFunction
    {
        ConfigByFunction()
        {
            test1 = 0;
            testval = "";

            std::cout << "ConfigByFunction ctor" << std::endl;
        }

    public:
        int test1;
        std::string testval;
    };
}

#endif //MYSTATICS_CONFIGBYFUNCTION_H
