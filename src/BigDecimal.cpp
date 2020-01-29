/*
** EPITECH PROJECT, 2019
** BigDecimal.cpp
** File description:
** for epitech pool
*/

#include <cmath>
#include "Factory.hpp"
#include "BigDecimal.hpp"

AbstractVM::BigDecimal::BigDecimal(const std::string &value) {
    _value = std::atof(value.c_str());
}

std::string AbstractVM::BigDecimal::toString() const {
    std::string res;

    res = std::to_string(_value);
    return res;
}

AbstractVM::eOperandType AbstractVM::BigDecimal::getType() const {
    return BIGDECIMAL;
}

AbstractVM::IOperand *AbstractVM::BigDecimal::getResult(AbstractVM::eOperandType type, AbstractVM::eOperation op, const AbstractVM::IOperand &rhs) const {
    return AbstractVM::Operation::makeOperation(((type * 5) + op), *this, rhs);
}

AbstractVM::IOperand *AbstractVM::BigDecimal::operator+(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, ADD, rhs);
    else
        return getResult(v2Type, ADD, rhs);
}

AbstractVM::IOperand *AbstractVM::BigDecimal::operator-(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, SUB, rhs);
    else
        return getResult(v2Type, SUB, rhs);
}

AbstractVM::IOperand *AbstractVM::BigDecimal::operator*(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, MUL, rhs);
    else
        return getResult(v2Type, MUL, rhs);
}

AbstractVM::IOperand *AbstractVM::BigDecimal::operator/(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, DIV, rhs);
    else
        return getResult(v2Type, DIV, rhs);
}

AbstractVM::IOperand *AbstractVM::BigDecimal::operator%(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, MOD, rhs);
    else
        return getResult(v2Type, MOD, rhs);
}