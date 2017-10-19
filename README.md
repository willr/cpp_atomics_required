# cpp_atomics_required

Demonstrates the only way a make sure a variable's state is shared when the container struct 
  is held at static scope is to use atomic.
  
**shared with static module scope**
```
ConfigByModule ctor
ConfigByAtomic ctor
ConfigByPointer ctor
ConfigByModule copy ctor
mainLoopByModule config address: 0x7ffff691be80
ml::mainLoopByModule: reading value from testval: 
ml::mainLoopByModule: setting value to testval: Manager::100
ConfigByModule copy ctor
runTaskByModule config address: 0x7ffff611ae60
tasks::TaskA::runTaskByModule: reading value from testval: 
tasks::TaskA::runTaskByModule: setting value to testval: TaskA::0
ml::mainLoopByModule: reading value from testval: Manager::100
ml::mainLoopByModule: setting value to testval: Manager::101
tasks::TaskA::runTaskByModule: reading value from testval: TaskA::0
tasks::TaskA::runTaskByModule: setting value to testval: TaskA::1
ml::mainLoopByModule: reading value from testval: Manager::101
ml::mainLoopByModule: setting value to testval: Manager::102
tasks::TaskA::runTaskByModule: reading value from testval: TaskA::1
tasks::TaskA::runTaskByModule: setting value to testval: TaskA::2
ml::mainLoopByModule: reading value from testval: Manager::102
ml::mainLoopByModule: setting value to testval: Manager::103
tasks::TaskA::runTaskByModule: reading value from testval: TaskA::2
tasks::TaskA::runTaskByModule: setting value to testval: TaskA::3
```

**shared via std::atomic**
```
ConfigByModule ctor
ConfigByAtomic ctor
ConfigByPointer ctor
mainLoopByAtomic config address: 0x6156e8
ml::mainLoopByAtomic: reading value from test1: 0
ml::mainLoopByAtomic: setting value to test1: Manager::100
runTaskByAtomic config address: 0x6156e8
tasks::TaskA::runTaskByAtomic: reading value from test1: 100
tasks::TaskA::runTaskByAtomic: setting value to test1: TaskA::0
ml::mainLoopByAtomic: reading value from test1: 0
ml::mainLoopByAtomic: setting value to test1: Manager::101
tasks::TaskA::runTaskByAtomic: reading value from test1: 101
tasks::TaskA::runTaskByAtomic: setting value to test1: TaskA::1
ml::mainLoopByAtomic: reading value from test1: 1
ml::mainLoopByAtomic: setting value to test1: Manager::102
tasks::TaskA::runTaskByAtomic: reading value from test1: 102
tasks::TaskA::runTaskByAtomic: setting value to test1: TaskA::2
ml::mainLoopByAtomic: reading value from test1: 2
ml::mainLoopByAtomic: setting value to test1: Manager::103
tasks::TaskA::runTaskByAtomic: reading value from test1: 103
tasks::TaskA::runTaskByAtomic: setting value to test1: TaskA::3
```
