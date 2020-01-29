
#ifndef OBJECTIF_DIMANCHE_CPU_HPP
#define OBJECTIF_DIMANCHE_CPU_HPP

#include "IOperand.hpp"
#include "Factory.hpp"
#include <array>

namespace AbstractVM {

    class CPU {
    public:
        //CT && DT
        CPU();
        ~CPU();

        //public Operations
        IOperand *add(IOperand *V1, IOperand *V2) const;
        IOperand *sub(IOperand *V1, IOperand *V2) const;
        IOperand *mul(IOperand *V1, IOperand *V2) const;
        IOperand *div(IOperand *V1, IOperand *V2) const;
        IOperand *mod(IOperand *V1, IOperand *V2) const;
        IOperand *loadFromRegister(const unsigned int nb);
        void storeInRegister(const unsigned int nb, IOperand *operand);
        bool isEqualToZero(const std::string &cmp) const;

    private:
        std::array<IOperand *, 16> _register;
    };

}


#endif //OBJECTIF_DIMANCHE_CPU_HPP
