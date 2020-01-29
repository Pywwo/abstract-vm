/*
** EPITECH PROJECT, 2019
** VMexception.hpp
** File description:
** for epitech pool
*/

#ifndef OBJECTIF_DIMANCHE_VMEXCEPTION_HPP
#define OBJECTIF_DIMANCHE_VMEXCEPTION_HPP

#include <exception>
#include <string>

namespace AbstractVM {


    class VMException : public std::exception {
    public:
        explicit VMException(const std::string &info) : _info(info) {};
        const char *what() const throw() {
            return _info.c_str();
            }
    protected:
        std::string _info;
    };

    class CPUException : public VMException {
    public:
        explicit CPUException(const std::string &info) : VMException(info) {};
    };

    class FactoryException : public VMException {
    public:
        explicit FactoryException(const std::string &info) : VMException(info) {};
    };

    class InputOutputException : public VMException {
    public:
        explicit InputOutputException(const std::string &info) : VMException(info) {};
    };

    class IOperandException : public VMException {
    public:
        explicit IOperandException(const std::string &info) : VMException(info) {};
    };

    class MemoryException : public VMException {
    public:
        explicit MemoryException(const std::string &info) : VMException(info) {};
    };

    class OrchestratorException : public VMException {
    public:
        explicit OrchestratorException(const std::string &info) : VMException(info) {};
    };
}

#endif