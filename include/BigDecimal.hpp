/*
** EPITECH PROJECT, 2019
** objectif_dimanche
** File description:
** BigDecimal
*/

#ifndef BIGDECIMAL_HPP_
#define BIGDECIMAL_HPP_

#include "IOperand.hpp"
#include "EOperand.hpp"
#include "ctype.h"

namespace AbstractVM {

    class BigDecimal : public IOperand {
    public :
        BigDecimal(const std::string &value);
        std::string toString() const override;
        eOperandType getType() const override;
        AbstractVM::IOperand *getResult(eOperandType type, eOperation op, const AbstractVM::IOperand &rhs) const;
        IOperand *operator+(const IOperand &rhs) const override;
        IOperand *operator-(const IOperand &rhs) const override;
        IOperand *operator*(const IOperand &rhs) const override;
        IOperand *operator/(const IOperand &rhs) const override;
        IOperand *operator%(const IOperand &rhs) const override;
        ~BigDecimal () override = default;
    private:
        eOperandType _type;
        double _value;
    };
}

#endif /* !BIGDECIMAL_HPP_ */
