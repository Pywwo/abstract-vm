/*
** EPITECH PROJECT, 2019
** objectif_dimanche
** File description:
** Double
*/

#ifndef DOUBLE_HPP_
#define DOUBLE_HPP_

#include "IOperand.hpp"
#include "EOperand.hpp"
#include "eOperandOperation.hpp"

namespace AbstractVM {

    class Double : public IOperand {
    public :
        Double(const std::string &value);
        std::string toString() const override;
        eOperandType getType() const override;
        AbstractVM::IOperand *getResult(eOperandType type, eOperation op, const AbstractVM::IOperand &rhs) const;
        IOperand *operator+(const IOperand &rhs) const override;
        IOperand *operator-(const IOperand &rhs) const override;
        IOperand *operator*(const IOperand &rhs) const override;
        IOperand *operator/(const IOperand &rhs) const override;
        IOperand *operator%(const IOperand &rhs) const override;
        ~Double () override = default;
    private:
        eOperandType _type;
        double _value;
    };
}

#endif /* !DOUBLE_HPP_ */
