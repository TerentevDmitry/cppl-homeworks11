// Домашнее задание к занятию «Move семантика»
// Задача 2. Большие числа

#include "BigInteger.h"

int main()
{
    auto number1 = BigInteger("5");
    auto number2 = BigInteger("6");

    auto resultSum = number1 + number2;
    std::cout << std::endl << "sum = " << resultSum << std::endl;

    number1 = BigInteger("5");
    number2 = BigInteger("6");

    auto resultMultiplication = number1 * number2;
    std::cout << std::endl << "multiplication = " << resultMultiplication << std::endl;





    auto number3(number2);
    std::cout << number2 << " & " << number3 << std::endl;

    BigInteger number4 = number1;
    
    std::cout << number1 << " & " << number2 << " & " << number3 << " & " << number4 << std::endl;

    BigInteger number5 = std::move(number1);
    std::cout << number1 << " & " << number2 << " & " << number3 << " & " << number4 << " & " << number5 << std::endl;

    number1 = std::move(number4);
    std::cout << number1 << " & " << number2 << " & " << number3 << " & " << number4 << " & " << number5 << std::endl;

}