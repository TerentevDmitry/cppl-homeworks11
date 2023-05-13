// Домашнее задание к занятию «Move семантика»
// Задача 2. Большие числа

#include "BigInteger.h"

int main()
{
    
    auto number0 = BigInteger("31");
    std::cout << number0.getSize() << std::endl;

    auto number3 = BigInteger("34");
    std::cout << number0.getSize() << std::endl;

    //auto number1 = BigInteger("114575");
    //std::cout << number1.getSize() << std::endl;

    //auto number2 = BigInteger("78524");
    //std::cout << number2.getSize() << std::endl;

    auto result = number0 + number3;
    std::cout << "193099 55 = number1 + number2 = " << result; // 193099


}