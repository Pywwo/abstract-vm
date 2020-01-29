/*
** EPITECH PROJECT, 2019
** Double.cpp
** File description:
** for epitech pool
*/

#include <cmath>
#include "Double.hpp"
#include "Factory.hpp"

AbstractVM::Double::Double(const std::string &value) {
    _value = std::atof(value.c_str());
}

std::string AbstractVM::Double::toString() const {
    std::string res;

    res = std::to_string(_value);
    return res;
}

AbstractVM::eOperandType AbstractVM::Double::getType() const {
    return DOUBLE;
}

AbstractVM::IOperand *AbstractVM::Double::getResult(AbstractVM::eOperandType type, AbstractVM::eOperation op, const AbstractVM::IOperand &rhs) const {
    return AbstractVM::Operation::makeOperation(((type * 5) + op), *this, rhs);
}

AbstractVM::IOperand *AbstractVM::Double::operator+(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, ADD, rhs);
    else
        return getResult(v2Type, ADD, rhs);
}

AbstractVM::IOperand *AbstractVM::Double::operator-(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, SUB, rhs);
    else
        return getResult(v2Type, SUB, rhs);
}

AbstractVM::IOperand *AbstractVM::Double::operator*(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, MUL, rhs);
    else
        return getResult(v2Type, MUL, rhs);
}

AbstractVM::IOperand *AbstractVM::Double::operator/(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, DIV, rhs);
    else
        return getResult(v2Type, DIV, rhs);
}

AbstractVM::IOperand *AbstractVM::Double::operator%(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, MOD, rhs);
    else
        return getResult(v2Type, MOD, rhs);
}
