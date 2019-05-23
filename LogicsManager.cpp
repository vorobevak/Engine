#include "LogicsManager.h"

LogicsManager::LogicsManager()
{}

void LogicsManager::registerScript(Script* S)
{
    scripts.push_back(S);
}

void LogicsManager::startLogics()
{
    for (Script* scr : scripts)
    {
        scr->start();
    }
    
}

void LogicsManager::updateLogics()
{
    for (Script* scr : scripts)
    {
        scr->update();
    }
}
