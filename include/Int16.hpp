/*
** EPITECH PROJECT, 2019
** objectif_dimanche
** File description:
** Int16
*/

#ifndef INT16_HPP_
#define INT16_HPP_

#include "IOperand.hpp"
#include "EOperand.hpp"
#include "ctype.h"
#include "eOperandOperation.hpp"

namespace AbstractVM {

    class Int16 : public IOperand {
    public :
        Int16(const std::string &value);
        std::string toString() const override;
        eOperandType getType() const override;
        AbstractVM::IOperand *getResult(eOperandType type, eOperation op, const AbstractVM::IOperand &rhs) const;
        IOperand *operator+(const IOperand &rhs) const override;
        IOperand *operator-(const IOperand &rhs) const override;
        IOperand *operator*(const IOperand &rhs) const override;
        IOperand *operator/(const IOperand &rhs) const override;
        IOperand *operator%(const IOperand &rhs) const override;
        ~Int16 () override = default;
    private:
        eOperandType _type;
        int16_t _value;
    };
}

#endif /* !INT16_HPP_ */
