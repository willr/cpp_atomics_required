//
// Created by will on 10/19/17.
//

#ifndef MYSTATICS_TASKA_H
#define MYSTATICS_TASKA_H

#include "ConfigByParam.h"

namespace tasks
{
    class TaskA
    {
    public:
        void runTaskByFunction();

        void runTaskByModule();

        void runTaskByAtomic();

        void runTaskByPointer();

        void runTaskByParam(cc::ConfigByParam config);
    };
}

#endif //MYSTATICS_TASKA_H
