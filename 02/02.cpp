// Домашнее задание к занятию «Move семантика»
// Задача 2. Большие числа

#include "BigInteger.h"

int main()
{
    
    //auto number1 = BigInteger("812");

    //auto number2 = BigInteger("348");

    auto number1 = BigInteger("116666666664575");

    auto number2 = BigInteger("111178524");

   

    auto result = number1 + number2;
    std::cout << result << std::endl; // 193099
    std::cout << "116666777843099";
}