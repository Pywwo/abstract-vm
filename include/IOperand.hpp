//
// Created by romain on 16/07/19.
//

#ifndef OBJECTIF_DIMANCHE_IOPERAND_HPP
#define OBJECTIF_DIMANCHE_IOPERAND_HPP

#include <string>
#include "EOperand.hpp"

namespace AbstractVM {

    class IOperand {
    public :
        virtual std::string toString() const = 0;
        virtual eOperandType getType() const = 0;
        virtual IOperand *operator+(const IOperand &rhs) const = 0;
        virtual IOperand *operator-(const IOperand &rhs) const = 0;
        virtual IOperand *operator*(const IOperand &rhs) const = 0;
        virtual IOperand *operator/(const IOperand &rhs) const = 0;
        virtual IOperand *operator%(const IOperand &rhs) const = 0;
        virtual   ~IOperand () {}
    };
}

#endif //OBJECTIF_DIMANCHE_IOPERAND_HPP
