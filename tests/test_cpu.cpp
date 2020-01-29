/*
** EPITECH PROJECT, 2019
** tests_cpu
** File description:
** for epitech pool
*/

#include "CPU.hpp"
#include <criterion/criterion.h>

Test(isEqualToZero, tests_false)
{
    AbstractVM::CPU cpu;
    std::string temp("0.001");

    bool ret = cpu.isEqualToZero(temp);

    cr_assert_eq(ret, false);
}
