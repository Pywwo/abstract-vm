/*
** EPITECH PROJECT, 2019
** Int8.cpp
** File description:
** for epitech pool
*/

#include "Factory.hpp"
#include "Int8.hpp"

AbstractVM::Int8::Int8(const std::string &value) {
    _value = std::atoi(value.c_str());
}

std::string AbstractVM::Int8::toString() const {
    std::string res;

    res = std::to_string(_value);
    return res;
}

AbstractVM::eOperandType AbstractVM::Int8::getType() const {
    return INT8;
}

AbstractVM::IOperand *AbstractVM::Int8::getResult(eOperandType type, eOperation op, const AbstractVM::IOperand &rhs) const {
    return AbstractVM::Operation::makeOperation(((type * 5) + op), *this, rhs);
}

AbstractVM::IOperand *AbstractVM::Int8::operator+(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, ADD, rhs);
    else
        return getResult(v2Type, ADD, rhs);
}

AbstractVM::IOperand *AbstractVM::Int8::operator-(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, SUB, rhs);
    else
        return getResult(v2Type, SUB, rhs);
}

AbstractVM::IOperand *AbstractVM::Int8::operator*(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, MUL, rhs);
    else
        return getResult(v2Type, MUL, rhs);
}

AbstractVM::IOperand *AbstractVM::Int8::operator/(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, DIV, rhs);
    else
        return getResult(v2Type, DIV, rhs);
}

AbstractVM::IOperand *AbstractVM::Int8::operator%(const AbstractVM::IOperand &rhs) const {
    eOperandType v1Type = getType();
    eOperandType v2Type = rhs.getType();

    if (v1Type > v2Type)
        return getResult(v1Type, MOD, rhs);
    else
        return getResult(v2Type, MOD, rhs);
}
