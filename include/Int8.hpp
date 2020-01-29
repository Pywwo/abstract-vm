/*
** EPITECH PROJECT, 2019
** objectif_dimanche
** File description:
** Int8
*/

#ifndef INT8_HPP_
#define INT8_HPP_

#include "IOperand.hpp"
#include "EOperand.hpp"
#include "ctype.h"
#include "eOperandOperation.hpp"
#include "Operation.hpp"
#include <map>

namespace AbstractVM {

    class Int8 : public IOperand {

    public :
        Int8(const std::string &value);
        std::string toString() const override;
        eOperandType getType() const override;
        AbstractVM::IOperand *getResult(eOperandType type, eOperation op, const AbstractVM::IOperand &rhs) const;
        IOperand *operator+(const IOperand &rhs) const override;
        IOperand *operator-(const IOperand &rhs) const override;
        IOperand *operator*(const IOperand &rhs) const override;
        IOperand *operator/(const IOperand &rhs) const override;
        IOperand *operator%(const IOperand &rhs) const override;
        ~Int8 () override = default;

    private:
        eOperandType _type;
        int8_t _value;
    };
}

#endif /* !INT8_HPP_ */
