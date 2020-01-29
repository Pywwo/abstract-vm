/*
** EPITECH PROJECT, 2019
** float.cpp
** File description:
** for epitech pool
*/

#include <cmath>
#include "Factory.hpp"
#include "Float.hpp"
#include <sstream>
#include <iomanip>

AbstractVM::Float::Float(const std::string &value) {
    _value = static_cast<float>(std::atof(value.c_str()));
}

std::string AbstractVM::Float::toString() const {
    std::string res;
    std::ostringstream ss;

    ss << _value;
    res = ss.str();
    return res;
}

AbstractVM::eOperandType AbstractVM::Float::getType() const {
    return FLOAT;
}

AbstractVM::IOperand *AbstractVM::Float::getResult(AbstractVM::eOperandType type, AbstractVM::eOperation op, const AbstractVM::IOperand &rhs) const {
    return AbstractVM::Operation::makeOperation(((type * 5) + op), *this, rhs);
}

AbstractVM::IOperand *AbstractVM::Float::operator+(const IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, ADD, rhs);
    else
        return getResult(v2Type, ADD, rhs);
}

AbstractVM::IOperand *AbstractVM::Float::operator-(const IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, SUB, rhs);
    else
        return getResult(v2Type, SUB, rhs);
}

AbstractVM::IOperand *AbstractVM::Float::operator*(const IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, MUL, rhs);
    else
        return getResult(v2Type, MUL, rhs);
}

AbstractVM::IOperand *AbstractVM::Float::operator/(const IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, DIV, rhs);
    else
        return getResult(v2Type, DIV, rhs);
}

AbstractVM::IOperand *AbstractVM::Float::operator%(const IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, MOD, rhs);
    else
        return getResult(v2Type, MOD, rhs);
}