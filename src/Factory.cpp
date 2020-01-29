#include "../include/Factory.hpp"

AbstractVM::Factory* AbstractVM::Factory::_instance = nullptr;

AbstractVM::Factory::Factory()
    : _type({&AbstractVM::Factory::createInt8, 
             &AbstractVM::Factory::createInt16, 
             &AbstractVM::Factory::createInt32,
             &AbstractVM::Factory::createFloat,
             &AbstractVM::Factory::createDouble,
             &AbstractVM::Factory::createBigDecimal})
{

}

AbstractVM::Factory::~Factory() {

}

AbstractVM::Factory *AbstractVM::Factory::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new Factory();
    }

    return _instance;
}

AbstractVM::IOperand *AbstractVM::Factory::createInt8(const std::string &value) {
    
    return new AbstractVM::Int8(value);
}

AbstractVM::IOperand *AbstractVM::Factory::createInt16(const std::string &value) {
    return new AbstractVM::Int16(value);
}

AbstractVM::IOperand *AbstractVM::Factory::createInt32(const std::string &value) {
    return new AbstractVM::Int32(value);
}

AbstractVM::IOperand *AbstractVM::Factory::createFloat(const std::string &value) {
    return new AbstractVM::Float(value);
}

AbstractVM::IOperand *AbstractVM::Factory::createDouble(const std::string &value) {
    return new AbstractVM::Double(value);
}

AbstractVM::IOperand *AbstractVM::Factory::createBigDecimal(const std::string &value) {
    return new AbstractVM::BigDecimal(value);
}

AbstractVM::IOperand *AbstractVM::Factory::createOperand(AbstractVM::eOperandType type, const std::string &value) {
    static Factory *factory = Factory::getInstance();
    IOperand *operand = (factory->*(factory->_type[type]))(value);

    return (operand);
}
