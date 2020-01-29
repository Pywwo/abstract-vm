//
// Created by romain on 18/07/19.
//

#include "Factory.hpp"
#include <cmath>
#include "Operation.hpp"

AbstractVM::Operation* AbstractVM::Operation::_instance = nullptr;

AbstractVM::IOperand *AbstractVM::Operation::int8add(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int8_t value1 = static_cast<int8_t>(std::atoi(v1.toString().c_str()));
    int8_t value2 = static_cast<int8_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 + value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT8, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::int8sub(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int8_t value1 = static_cast<int8_t>(std::atoi(v1.toString().c_str()));
    int8_t value2 = static_cast<int8_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 - value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT8, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::int8mul(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int8_t value1 = static_cast<int8_t>(std::atoi(v1.toString().c_str()));
    int8_t value2 = static_cast<int8_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 * value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT8, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::int8div(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int8_t value1 = static_cast<int8_t>(std::atoi(v1.toString().c_str()));
    int8_t value2 = static_cast<int8_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 / value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT8, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::int8mod(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int8_t value1 = static_cast<int8_t>(std::atoi(v1.toString().c_str()));
    int8_t value2 = static_cast<int8_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 % value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT8, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::int16add(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int16_t value1 = static_cast<int16_t>(std::atoi(v1.toString().c_str()));
    int16_t value2 = static_cast<int16_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 + value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT16, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::int16sub(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int16_t value1 = static_cast<int16_t>(std::atoi(v1.toString().c_str()));
    int16_t value2 = static_cast<int16_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 - value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT16, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::int16mul(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int16_t value1 = static_cast<int16_t>(std::atoi(v1.toString().c_str()));
    int16_t value2 = static_cast<int16_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 * value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT16, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::int16div(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int16_t value1 = static_cast<int16_t>(std::atoi(v1.toString().c_str()));
    int16_t value2 = static_cast<int16_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 / value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT16, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::int16mod(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int16_t value1 = static_cast<int16_t>(std::atoi(v1.toString().c_str()));
    int16_t value2 = static_cast<int16_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 % value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT16, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::int32add(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int32_t value1 = static_cast<int32_t>(std::atoi(v1.toString().c_str()));
    int32_t value2 = static_cast<int32_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 + value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT32, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::int32sub(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int32_t value1 = static_cast<int32_t>(std::atoi(v1.toString().c_str()));
    int32_t value2 = static_cast<int32_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 - value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT32, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::int32mul(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int32_t value1 = static_cast<int32_t>(std::atoi(v1.toString().c_str()));
    int32_t value2 = static_cast<int32_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 * value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT32, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::int32div(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int32_t value1 = static_cast<int32_t>(std::atoi(v1.toString().c_str()));
    int32_t value2 = static_cast<int32_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 / value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT32, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::int32mod(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    int32_t value1 = static_cast<int32_t>(std::atoi(v1.toString().c_str()));
    int32_t value2 = static_cast<int32_t>(std::atoi(v2.toString().c_str()));

    value1 = value1 % value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(INT32, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::floatadd(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    float value1 = static_cast<float>(std::atof(v1.toString().c_str()));
    float value2 = static_cast<float>(std::atof(v2.toString().c_str()));

    value1 = value1 + value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(FLOAT, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::floatsub(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    float value1 = static_cast<float>(std::atof(v1.toString().c_str()));
    float value2 = static_cast<float>(std::atof(v2.toString().c_str()));

    value1 = value1 - value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(FLOAT, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::floatmul(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    float value1 = static_cast<float>(std::atof(v1.toString().c_str()));
    float value2 = static_cast<float>(std::atof(v2.toString().c_str()));

    value1 = value1 * value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(FLOAT, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::floatdiv(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    float value1 = static_cast<float>(std::atof(v1.toString().c_str()));
    float value2 = static_cast<float>(std::atof(v2.toString().c_str()));

    value1 = value1 / value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(FLOAT, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::floatmod(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    float value1 = static_cast<float>(std::atof(v1.toString().c_str()));
    float value2 = static_cast<float>(std::atof(v2.toString().c_str()));

    value1 = std::fmod(value1, value2);
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(FLOAT, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::doubleadd(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    double value1 = static_cast<double>(std::atof(v1.toString().c_str()));
    double value2 = static_cast<double>(std::atof(v2.toString().c_str()));

    value1 = value1 + value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(DOUBLE, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::doublesub(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    double value1 = static_cast<double>(std::atof(v1.toString().c_str()));
    double value2 = static_cast<double>(std::atof(v2.toString().c_str()));

    value1 = value1 - value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(DOUBLE, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::doublemul(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    double value1 = static_cast<double>(std::atof(v1.toString().c_str()));
    double value2 = static_cast<double>(std::atof(v2.toString().c_str()));

    value1 = value1 * value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(DOUBLE, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::doublediv(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    double value1 = static_cast<double>(std::atof(v1.toString().c_str()));
    double value2 = static_cast<double>(std::atof(v2.toString().c_str()));

    value1 = value1 / value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(DOUBLE, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::doublemod(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    double value1 = static_cast<double>(std::atof(v1.toString().c_str()));
    double value2 = static_cast<double>(std::atof(v2.toString().c_str()));

    value1 = std::fmod(value1, value2);
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(DOUBLE, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::bigdecimaladd(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    double value1 = static_cast<double>(std::atof(v1.toString().c_str()));
    double value2 = static_cast<double>(std::atof(v2.toString().c_str()));

    value1 = value1 + value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(DOUBLE, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::bigdecimalsub(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    double value1 = static_cast<double>(std::atof(v1.toString().c_str()));
    double value2 = static_cast<double>(std::atof(v2.toString().c_str()));

    value1 = value1 - value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(DOUBLE, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::bigdecimalmul(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    double value1 = static_cast<double>(std::atof(v1.toString().c_str()));
    double value2 = static_cast<double>(std::atof(v2.toString().c_str()));

    value1 = value1 * value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(DOUBLE, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::bigdecimaldiv(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    double value1 = static_cast<double>(std::atof(v1.toString().c_str()));
    double value2 = static_cast<double>(std::atof(v2.toString().c_str()));

    value1 = value1 / value2;
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(DOUBLE, valueInStr);
}

AbstractVM::IOperand *AbstractVM::Operation::bigdecimalmod(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    double value1 = static_cast<double>(std::atof(v1.toString().c_str()));
    double value2 = static_cast<double>(std::atof(v2.toString().c_str()));

    value1 = std::fmod(value1, value2);
    std::string valueInStr = std::to_string(value1);
    return AbstractVM::Factory::createOperand(DOUBLE, valueInStr);
}

AbstractVM::Operation::Operation()
        : _doOperation({&AbstractVM::Operation::int8add,
                      &AbstractVM::Operation::int8sub,
                      &AbstractVM::Operation::int8mul,
                      &AbstractVM::Operation::int8div,
                      &AbstractVM::Operation::int8mod,
                      &AbstractVM::Operation::int16add,
                      &AbstractVM::Operation::int16sub,
                      &AbstractVM::Operation::int16mul,
                      &AbstractVM::Operation::int16div,
                      &AbstractVM::Operation::int16mod,
                      &AbstractVM::Operation::int32add,
                      &AbstractVM::Operation::int32sub,
                      &AbstractVM::Operation::int32mul,
                      &AbstractVM::Operation::int32div,
                      &AbstractVM::Operation::int32mod,
                      &AbstractVM::Operation::floatadd,
                      &AbstractVM::Operation::floatsub,
                      &AbstractVM::Operation::floatmul,
                      &AbstractVM::Operation::floatdiv,
                      &AbstractVM::Operation::floatmod,
                      &AbstractVM::Operation::doubleadd,
                      &AbstractVM::Operation::doublesub,
                      &AbstractVM::Operation::doublemul,
                      &AbstractVM::Operation::doublediv,
                      &AbstractVM::Operation::doublemod,
                      &AbstractVM::Operation::bigdecimaladd,
                      &AbstractVM::Operation::bigdecimalsub,
                      &AbstractVM::Operation::bigdecimalmul,
                      &AbstractVM::Operation::bigdecimaldiv,
                      &AbstractVM::Operation::bigdecimalmod})
{
}

AbstractVM::Operation *AbstractVM::Operation::getInstance() {
    if (_instance == nullptr)
    {
        _instance = new Operation();
    }

    return _instance;
}

AbstractVM::IOperand *AbstractVM::Operation::makeOperation(int whichOpe, const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2) {
    static Operation *operation = Operation::getInstance();
    IOperand *operand = (operation->*(operation->_doOperation[whichOpe]))(v1, v2);

    return operand;
}

AbstractVM::Operation::~Operation() {

}
