//
// Created by romain on 16/07/19.
//

#ifndef OBJECTIF_DIMANCHE_FACTORY_HPP
#define OBJECTIF_DIMANCHE_FACTORY_HPP


#include <string>
#include "IOperand.hpp"
#include "EOperand.hpp"
#include <array>
#include <iostream>
#include <ctype.h>
#include "Float.hpp"
#include "Double.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Int8.hpp"
#include "BigDecimal.hpp"

namespace AbstractVM {

    class Factory {
    
    typedef IOperand *(Factory::*which)(const std::string &value);

    public:
        //CT && DT
        ~Factory();

        //Public Functions
        static Factory *getInstance();
        static IOperand *createOperand(eOperandType type, const std::string &value);

    private:
        static Factory *_instance;
        std::array<which, 6> _type;

        Factory();
        IOperand *createInt8(const std::string &value);
        IOperand *createInt16(const std::string &value);
        IOperand *createInt32(const std::string &value);
        IOperand *createFloat(const std::string &value);
        IOperand *createDouble(const std::string &value);
        IOperand *createBigDecimal(const std::string &value);
    };
}

#endif //OBJECTIF_DIMANCHE_FACTORY_HPP
