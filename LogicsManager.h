#ifndef __LOGICS__
#define __LOGICS__
#include "Script.h"
#include <list>

class Script;

class LogicsManager
{
public:
    LogicsManager();
    std::list <Script*> scripts;
    
    void registerScript(Script* S);
    void startLogics();
    void updateLogics();
};

#endif
