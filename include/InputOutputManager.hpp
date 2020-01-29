
#ifndef OBJECTIF_DIMANCHE_INPUTOUTPUTMANAGER_HPP
#define OBJECTIF_DIMANCHE_INPUTOUTPUTMANAGER_HPP

#include <string>
#include <stack>
#include "IOperand.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

namespace AbstractVM {

    enum  MODE {
        INPUT,
        FILE
    };

    class InputOutputManager {
    public:
        //CT && DT
        InputOutputManager();
        ~InputOutputManager();

        //public Function
        void setMode();
        std::vector<std::string> readInput();
        void outputDisplay();
        void displayFullStack(std::stack<IOperand *> &stack);
        void printOperand(IOperand *operand);
        std::string deleteUselessZeros(const std::string &toRevert);

        //getter && setter
        const std::string &getAv() const;
        void setAv(const std::string &av);
        MODE getMode() const;
        void setMode(MODE mode);

    private:

        //Private
        std::string _av;
        MODE _mode;

    };

}

#endif //OBJECTIF_DIMANCHE_INPUTOUTPUTMANAGER_HPP
