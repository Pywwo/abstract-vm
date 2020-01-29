/*
** EPITECH PROJECT, 2019
** objectif_dimanche
** File description:
** Int32
*/

#ifndef INT32_HPP_
#define INT32_HPP_

#include "IOperand.hpp"
#include "EOperand.hpp"
#include "ctype.h"

namespace AbstractVM {

    class Int32 : public IOperand {
    public :
        Int32(const std::string &value);
        std::string toString() const override;
        eOperandType getType() const override;
        AbstractVM::IOperand *getResult(eOperandType type, eOperation op, const AbstractVM::IOperand &rhs) const;
        IOperand *operator+(const IOperand &rhs) const override;
        IOperand *operator-(const IOperand &rhs) const override;
        IOperand *operator*(const IOperand &rhs) const override;
        IOperand *operator/(const IOperand &rhs) const override;
        IOperand *operator%(const IOperand &rhs) const override;
        ~Int32 () override = default;
    private:
        eOperandType _type;
        int32_t _value;
    };
}

#endif /* !INT32_HPP_ */
