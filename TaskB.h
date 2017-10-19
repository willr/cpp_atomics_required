//
// Created by will on 10/19/17.
//

#ifndef MYSTATICS_TASKB_H
#define MYSTATICS_TASKB_H


#include "ConfigByParam.h"

namespace tasks
{
    class TaskB
    {
    public:
        void runTaskByFunction();

        void runTaskByModule();

        void runTaskByAtomic();

        void runTaskByParam(cc::ConfigByParam config);
    };
}


#endif //MYSTATICS_TASKB_H
