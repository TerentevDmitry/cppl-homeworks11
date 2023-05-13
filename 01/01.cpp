//Домашнее задание к занятию «Move семантика»
//Задача 1. Перемещение объектов

#include <iostream>
#include <string>
#include <vector>
#include <utility>


//_CONSTEXPR20 void swap(_Ty(&_Left)[_Size], _Ty(&_Right)[_Size]) noexcept(_Is_nothrow_swappable<_Ty>::value) {
//    if (&_Left != &_Right) {
//        _Ty* _First1 = _Left;
//        _Ty* _Last1 = _First1 + _Size;
//        _Ty* _First2 = _Right;
//        for (; _First1 != _Last1; ++_First1, ++_First2) {
//            _STD iter_swap(_First1, _First2);
//        }
//    }
//}






template<class T>
void move_vectors(T& one, T& two)
{
    T _Tmp = one;
    one = two;
    two = _Tmp;
};

template<class T>
void print_vectors(std::vector<T>& any)
{
    for (const auto& i : any)
    {
        std::cout << i << '\t';
    }
    std::cout << std::endl;
};




int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;

    std::cout << "std::string one before\t";
    print_vectors(one);
    std::cout << "std::string two before\t";
    print_vectors(two);

    move_vectors(one,two);
    
    std::cout << "std::string one after\t";
    print_vectors(one);
    std::cout << "std::string two after\t";
    print_vectors(two);

    std::vector <int> three = { 1,2,3,4,5 };
    std::vector <int> four;

    std::cout << "int one before\t";
    print_vectors(three);
    std::cout << "int two before\t";
    print_vectors(four);

    move_vectors(three, four);

    std::cout << "int one after\t";
    print_vectors(three);
    std::cout << "int two after\t";
    print_vectors(four);

    std::cout << "\n\nHello World!\n";
}