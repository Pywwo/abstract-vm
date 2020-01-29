/*
** EPITECH PROJECT, 2019
** float.hpp
** File description:
** for epitech pool
*/

#ifndef OBJECTIF_DIMANCHE_FLOAT_HPP
#define OBJECTIF_DIMANCHE_FLOAT_HPP

#include "IOperand.hpp"
#include "EOperand.hpp"
#include "eOperandOperation.hpp"

namespace AbstractVM {

    class Float : public IOperand {
    public :
        Float(const std::string &value);
        std::string toString() const override;
        eOperandType getType() const override;
        AbstractVM::IOperand *getResult(eOperandType type, eOperation op, const AbstractVM::IOperand &rhs) const;
        IOperand *operator+(const IOperand &rhs) const override;
        IOperand *operator-(const IOperand &rhs) const override;
        IOperand *operator*(const IOperand &rhs) const override;
        IOperand *operator/(const IOperand &rhs) const override;
        IOperand *operator%(const IOperand &rhs) const override;
        ~Float () {}
    private:
        eOperandType _type;
        float _value;
    };
}

#endif