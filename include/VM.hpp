//
// Created by romain on 16/07/19.
//

#ifndef OBJECTIF_DIMANCHE_VM_HPP
#define OBJECTIF_DIMANCHE_VM_HPP

#include <string>
#include <bits/unique_ptr.h>
#include "Memory.hpp"
#include "CPU.hpp"
#include "InputOutputManager.hpp"
#include "Factory.hpp"
#include "Orchestrator.hpp"

namespace AbstractVM {

    class VM {
    public:
        //CT && DT
        VM(std::string &av);
        ~VM();

        //Public Func
        void initVM();

    private:
        std::string _av;
        std::unique_ptr<Memory> _memory;
        std::unique_ptr<CPU> _cpu;
        std::unique_ptr<InputOutputManager> _io;
        std::unique_ptr<Orchestrator> _orchestrator;
    };

}


#endif //OBJECTIF_DIMANCHE_VM_HPP
