//
// Created by romain on 16/07/19.
//

#include "../include/VM.hpp"

AbstractVM::VM::VM(std::string &av) :
_av(av),
_memory(new AbstractVM::Memory),
_cpu(new AbstractVM::CPU),
_io(new AbstractVM::InputOutputManager),
_orchestrator(new AbstractVM::Orchestrator(av, (*_memory), (*_cpu), (*_io)))
{
}

AbstractVM::VM::~VM() = default;

void AbstractVM::VM::initVM()
{
   _orchestrator->run();
}