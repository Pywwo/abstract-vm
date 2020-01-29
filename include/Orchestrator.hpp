//
// Created by romain on 16/07/19.
//

#ifndef OBJECTIF_DIMANCHE_ORCHESTRATOR_HPP
#define OBJECTIF_DIMANCHE_ORCHESTRATOR_HPP


#include <string>
#include "Memory.hpp"
#include <bits/unique_ptr.h>
#include "CPU.hpp"
#include "InputOutputManager.hpp"
#include <vector>
#include <regex>

namespace AbstractVM {

    class Orchestrator {

        typedef void (Orchestrator::*which)(std::string &value);
        
    public:

        //CT && DT
        Orchestrator(std::string &av, Memory &memory, CPU &cpu, InputOutputManager &io);
        ~Orchestrator();

        //Run Orchestrator
        void run();

        //public Function
        void startInputManager();
        void execByLine();

    private:

        //Private Variables
        Memory &_memory;
        CPU &_cpu;
        InputOutputManager &_io;
        std::string _av;
        std::vector<std::string> _listCommands;
        std::map<std::string, which> _list;
        bool _hasExit;

        eOperandType getRightType(const std::string &which);
        bool isOverflowOrUnderflow(AbstractVM::eOperandType type, const std::string &number);

        void push(std::string &);
        void pop(std::string &);
        void clear(std::string &);
        void dup(std::string &);
        void swap(std::string &);
        void dump(std::string &);
        void assert(std::string &);
        void add(std::string &);
        void sub(std::string &);
        void mul(std::string &);
        void div(std::string &);
        void mod(std::string &);
        void load(std::string &);
        void store(std::string &);
        void print(std::string &);
        void exit(std::string &);
        std::string concatLine(const std::string &toParse);
        std::string concatLineComment(const std::string &toParse);
    };

}

#endif //OBJECTIF_DIMANCHE_ORCHESTRATOR_HPP
