/*
** EPITECH PROJECT, 2019
** AbstractVM
** File description:
** main.cpp
*/

#include "VM.hpp"
#include "VMException.hpp"

int main(int ac, char **av)
{
    if (ac > 2) {
        std::cerr << "USAGE : ./abstractVM [path file]\n";
        return 84;
    }
    std::string pathFile;
    if (ac == 1)
        pathFile = "";
    else {
        pathFile = av[1];
    }
    try {
        AbstractVM::VM vm(pathFile);
        vm.initVM();
    } catch (const AbstractVM::VMException &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (...) {
        std::cerr << "invalid behavior in programm" << std::endl;
        return 84;
    }
    return 0;
}
