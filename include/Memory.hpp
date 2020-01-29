//
// Created by romain on 16/07/19.
//

#ifndef OBJECTIF_DIMANCHE_MEMORY_HPP
#define OBJECTIF_DIMANCHE_MEMORY_HPP

#include <stack>
#include "IOperand.hpp"
#include "Factory.hpp"

namespace AbstractVM {

    class Memory {
    public:

        //CT && DT
        Memory();

        ~Memory();

        //Public Functions
        IOperand *getFirstValueOfStack() const;
        const std::stack<IOperand *> getStack() const;
        void push(IOperand *operand);
        IOperand *pop();
        void clear();
        void dup();
        void swap();
        bool assert(const std::string &value, const std::string &type) const;
        int getSize() const;
        eOperandType getRightType(const std::string &type) const;

    private:

        //private variable
        std::stack<IOperand *> _stack;
        std::string roundToCheck(const std::string &toRevert) const;
    };

}

#endif //OBJECTIF_DIMANCHE_MEMORY_HPP
