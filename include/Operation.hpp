//
// Created by romain on 18/07/19.
//

#ifndef OBJECTIF_DIMANCHE_OPERATION_HPP
#define OBJECTIF_DIMANCHE_OPERATION_HPP

#include "IOperand.hpp"
#include "eOperandOperation.hpp"
#include <array>

namespace AbstractVM {

    class Operation {

        typedef IOperand * (Operation::*which)(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);

    public:

        ~Operation();

        static Operation *getInstance();
        static IOperand *makeOperation(int whichOpe, const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);

    private:
        static Operation *_instance;
        std::array<which, 30> _doOperation;

        Operation();
        AbstractVM::IOperand *int8add(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *int8sub(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *int8mul(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *int8div(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *int8mod(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *int16add(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *int16sub(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *int16mul(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *int16div(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *int16mod(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *int32add(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *int32sub(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *int32mul(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *int32div(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *int32mod(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *floatadd(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *floatsub(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *floatmul(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *floatdiv(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *floatmod(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *doubleadd(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *doublesub(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *doublemul(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *doublediv(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *doublemod(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *bigdecimaladd(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *bigdecimalsub(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *bigdecimalmul(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *bigdecimaldiv(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
        AbstractVM::IOperand *bigdecimalmod(const AbstractVM::IOperand &v1, const AbstractVM::IOperand &v2);
    };

}

#endif //OBJECTIF_DIMANCHE_OPERATION_HPP
