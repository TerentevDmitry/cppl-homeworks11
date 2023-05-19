#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <charconv>
#include <math.h>

class BigInteger
{
private:
	std::string bigInteger_;
	std::vector<int> result_{};

	int base_ = 10; //система исчисления
	size_t size_ = 0; //размер bigInteger_

	
public:
	BigInteger(const std::string& value) : bigInteger_{ value }, size_{ value.size() }
	{ std::cout << this << " Constructor BigInteger(T value)\n"; };

	////Copy Constructor
	BigInteger(const BigInteger& other)
	{ 
		bigInteger_ = other.bigInteger_;
		std::cout << this << " Copy Constructor\n"; 
	};

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

	std::string operator+(BigInteger& other)
	{
		//кол-во раз делать bigInteger_.insert
		int deltaSize = std::abs((static_cast<int>(size_) - static_cast<int>(other.size_)));

		//равняем по размеру и вставляем в начало '0' для соблюдения разрядности
		if (size_ > other.size_)
		{
			other.size_ = size_;
			auto it = other.bigInteger_.begin();
			for (int i = 0; i < deltaSize; i++)
			{
				other.bigInteger_.insert(it, '0');
			}
		}
		else
		{
			size_ = other.size_;
			auto it = bigInteger_.begin();
			for (int i = 0; i < deltaSize; i++)
			{
				bigInteger_.insert(it, '0');
			}
		}

		result_.reserve(size_ + 1); //резерв места в векторе
		other.result_.reserve(size_ + 1); //резерв места в векторе

		int j = static_cast<int>(size_);
		int h = 0;
		//складываем поразрядно
		for (--j; j >= 0; --j, h++)
		{
			result_.push_back((bigInteger_[j] - '0') + (other.bigInteger_[j] - '0'));
			if (result_[h] < 0)
				result_[h] = 0;
		}

		//проверка необходимости добавить еще разряд вверху
		if (result_[static_cast<int>(size_) - 1] >= 9)
		{
			j = static_cast<int>(size_) + 1;
			result_.push_back(0);
		} else 
		{ j = static_cast<int>(size_); }
		
		//переносим десятки на разряд выше
		for (size_t i = 0; i < size_; i++)
		{
			if (result_[i] >= base_)
			{
				result_[i + 1] += result_[i] / base_;
				result_[i] %= base_;
			}
		}

		bigInteger_.clear(); //чистим массив стрингов и пишем туда ответ
		
		for (--j; j >= 0; --j)
		{
			char k = result_[j] + '0';
			bigInteger_.push_back(k);
		}

		//std::cout << this << " operator +";
		return std::move(bigInteger_);
	};

	std::ostream& operator<<(std::ostream& out)
	{
		
		return out << bigInteger_;
	};

	size_t getSize() { return size_; }

	~BigInteger() { std::cout << '\n' << this << " Destructor BigInteger()"; };
};