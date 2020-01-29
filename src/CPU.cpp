#include "../include/CPU.hpp"
#include "VMException.hpp"

AbstractVM::CPU::CPU() 
    : _register() 
{
    _register.fill(NULL);
}

AbstractVM::CPU::~CPU() {
    int size = static_cast<int>(_register.size());

    for (int i = 0; i < size; i++) {
        if (_register[i] != NULL)
            delete _register[i];
    }
}

bool AbstractVM::CPU::isEqualToZero(const std::string &cmp) const {
    for (char c : cmp)
        if (c != '.' && c != '0')
            return false;
    return true;
}

AbstractVM::IOperand *AbstractVM::CPU::add(IOperand *V1, IOperand *V2) const {
    IOperand *result = (*V2) + (*V1);
    return result;
}

AbstractVM::IOperand *AbstractVM::CPU::sub(IOperand *V1, IOperand *V2) const {
    IOperand *result = (*V2) - (*V1);
    return result;
}

AbstractVM::IOperand *AbstractVM::CPU::mul(IOperand *V1, IOperand *V2) const {
    IOperand *result = (*V2) * (*V1);
    return result;
}

AbstractVM::IOperand *AbstractVM::CPU::div(IOperand *V1, IOperand *V2) const {
    if (this->isEqualToZero(V1->toString()) == true)
        throw CPUException("Division by zero is forbidden");
    IOperand *result = (*V2) / (*V1);
    return result;
}

AbstractVM::IOperand *AbstractVM::CPU::mod(IOperand *V1, IOperand *V2) const {
    if (this->isEqualToZero(V1->toString()) == true)
        throw CPUException("Modulo by zero is forbidden");
    IOperand *result = (*V2) % (*V1);
    return result;
}

AbstractVM::IOperand *AbstractVM::CPU::loadFromRegister(const unsigned int nb) {
    if (!_register[nb])
        throw CPUException("no value in this register");
    IOperand *last = Factory::createOperand(_register[nb]->getType(), _register[nb]->toString());
    return (last);
}

void AbstractVM::CPU::storeInRegister(const unsigned int nb, IOperand *operand) {
    _register[nb] = operand;
}
