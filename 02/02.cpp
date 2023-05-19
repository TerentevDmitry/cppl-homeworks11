// Домашнее задание к занятию «Move семантика»
// Задача 2. Большие числа

#include "BigInteger.h"

int main()
{
    auto number1 = BigInteger("114575");
    auto number2 = BigInteger("78524");

    auto result = number1 + number2;
    std::cout << result << std::endl; // 193099
    std::cout << "193099";
}