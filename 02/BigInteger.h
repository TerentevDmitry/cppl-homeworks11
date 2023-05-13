#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <string>


//template<class T>
class BigInteger
{
private:
	std::string bigInteger_;
	std::vector<int> result_{};

	int base_ = 10; //система исчисления
	size_t size_ = 0; //размер bigInteger_
	bool flag_ = false; // флаг выхода за пределы bigInteger_

	
public:
	////Default constructor
	//BigInteger() { std::cout << this << " Default constructor BigInteger()\n"; };

	//Constructor
	BigInteger(const std::string& value) : bigInteger_{ value }, size_{ value.size() }
	{ std::cout << this << " Constructor BigInteger(T value)\n"; };

	////Copy Constructor
	//BigInteger(const BigInteger& other)
	//{ 
	//	bigInteger_ = other.bigInteger_;
	//	std::cout << this << " Copy Constructor\n"; 
	//};

	//// Copy as Constructor=
	//std::string& operator=(const BigInteger& other)
	//{
	//	//int sum = this->bigInteger_ + other.bigInteger_;
	//	std::cout << this << " Перегрузка оператора +\n";
	//	//return this;
	//};


	////Move Constructor
	//BigInteger(BigInteger&& other) noexcept
	//{ 
	//	bigInteger_ = other.bigInteger_;
	//	other.~BigInteger();
	//	std::cout << this << " Move Constructor\n"; 
	//};

	//Перегрузка оператора +
	std::string operator+(const BigInteger& other)
	{
		size_t maxSize = std::max(size_, other.size_);

		for (size_t i = 0; i < maxSize; i++)
		{
			result_.push_back((bigInteger_[i] - '0') + (other.bigInteger_[i] - '0'));
		}

		//for (size_t i = 0; i < maxSize; i++)
		//{
		//	if (result_[i] >= base_)
		//	{
		//		result_[i + 1] += result_[i] / base_;
		//		result_[i] %= base_;
		//	}
		//}
		std::cout << this << " reload operator +\n";

		bigInteger_.(result_);

		return std::move(bigInteger_);




	};

	size_t getSize() { return size_; }

	~BigInteger() { std::cout << '\n' << this << " Destructor BigInteger()\n"; };
};