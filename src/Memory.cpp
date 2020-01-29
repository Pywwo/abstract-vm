#include "../include/Memory.hpp"
#include "VMException.hpp"
#include <algorithm>

AbstractVM::Memory::Memory() : _stack()
{

}

AbstractVM::Memory::~Memory() {

}

const std::stack<AbstractVM::IOperand *> AbstractVM::Memory::getStack() const {
    return _stack;
}

void AbstractVM::Memory::push(IOperand *operand) {
    _stack.push(operand);
}

AbstractVM::IOperand *AbstractVM::Memory::pop() {
    if (_stack.empty())
        throw MemoryException("Stack empty while trying to pop");
    IOperand *top = _stack.top();
    _stack.pop();
    return (top);
}

void AbstractVM::Memory::clear() {
    while (_stack.size() > 0) {
        delete pop();
    }
}

void AbstractVM::Memory::dup() {
    if (_stack.empty())
        throw MemoryException("Stack empty while trying to dup");
    IOperand *top = _stack.top();

    IOperand *copy = Factory::createOperand(top->getType(), top->toString());
    push(copy);
}

void AbstractVM::Memory::swap() {
    if (_stack.size() < 2)
        throw MemoryException("Stack not big enough while trying to swap");
    IOperand *first = _stack.top();
    _stack.pop();
    IOperand *second = _stack.top();
    _stack.pop();
    push(first);
    push(second);
}

int AbstractVM::Memory::getSize() const {
    return _stack.size();
}

AbstractVM::eOperandType AbstractVM::Memory::getRightType(const std::string &type) const {
    if (type == "int8") {
        return eOperandType::INT8;
    } else if (type == "int16") {
        return eOperandType::INT16;
    } else if (type == "int32") {
        return eOperandType::INT32;
    } else if (type == "double") {
        return eOperandType::DOUBLE;
    } else if (type == "float") {
        return eOperandType::FLOAT;
    } else if (type == "bigdecimal") {
        return eOperandType::BIGDECIMAL;
    } else
        throw OrchestratorException("Invalid behavior on type");
}

bool AbstractVM::Memory::assert(const std::string &value, const std::string &type) const {
    if (_stack.empty())
        throw MemoryException("Stack empty while trying to assert");
    IOperand *top = _stack.top();
    std::string rounded(roundToCheck(top->toString()));

    if (rounded == value && top->getType() == getRightType(type))
        return true;
    return false;
}

AbstractVM::IOperand *AbstractVM::Memory::getFirstValueOfStack() const {
    return _stack.top();
}

std::string AbstractVM::Memory::roundToCheck(const std::string &toRevert) const {
    std::string revert(toRevert);
    if (toRevert.find(".") == std::string::npos)
        return revert;
    std::reverse(revert.begin(), revert.end());
    while (revert.at(0) == '0')
        revert.erase(0, 1);
    std::reverse(revert.begin(), revert.end());
    return revert;
}