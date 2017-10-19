//
// Created by will on 10/19/17.
//

#ifndef MYSTATICS_MANAGER_H
#define MYSTATICS_MANAGER_H


#include "ConfigByFunction.h"
#include "ConfigByModule.h"
#include "ConfigByParam.h"
#include "ConfigByAtomic.h"
#include "ConfigByPointer.h"

namespace ml
{

    void
    mainLoopByParam(cc::ConfigByParam &config);

    void
    mainLoopByFunction();

    void
    mainLoopByModule();

    void
    mainLoopByAtomic();

    void
    mainLoopByPointer();

    void
    runTasksByFunction();

    void
    runTasksByModule();

    void
    runTasksByAtomic();

    void
    runTasksByPointer();

    void
    runTasksByParam(cc::ConfigByParam &config);

    cc::ConfigByFunction&
    getConfigFunctionStatic();

    cc::ConfigByModule&
    getConfigModuleStatic();

    cc::ConfigByAtomic*
    getConfigModuleAtomic();

    cc::ConfigByPointer*
    getConfigModulePointer();
}



#endif //MYSTATICS_MANAGER_H
