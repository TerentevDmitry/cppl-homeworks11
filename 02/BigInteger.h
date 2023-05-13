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
	bool flag_ = false; // флаг выхода за пределы bigInteger_
	size_t newSize_ = 0;
	
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
	std::string operator+(BigInteger& other)
	{
		//size_t maxSize = std::max(size_, other.size_)+1;


		int deltaSize = std::abs((static_cast<int>(size_) - static_cast<int>(other.size_)));

		if (size_ > other.size_)
		{ 
			other.size_ = size_;
			auto it = other.bigInteger_.begin();
			for (int i = 0; i < deltaSize; i++)
			{
				other.bigInteger_.insert(it, '0');
			}
		} else
		{ 
			size_ = other.size_;
			auto it = bigInteger_.begin();
			for (int i = 0; i < deltaSize; i++)
			{
				bigInteger_.insert(bigInteger_.begin(), '0');
			}
			
		}


		


		
		
		
		
		result_.reserve(size_);
		other.result_.reserve(size_);
		//size_ += 2;
		int iop = 1;

		int j = static_cast<int>(size_);
		int h = 0;

		//for (int i = 0; i < j; ++i) //
		for (--j; j >= 0; --j, h++)
		{
			result_.push_back((bigInteger_[j] - '0') + (other.bigInteger_[j] - '0'));
			if (result_[h] < 0)
				result_[h] = 0;
		}




		for (size_t i = 0; i < size_; i++)
		{
			//if (*(result_.end()-1) >= 10)
			//{
			//	result_.push_back(0);
			//}

			if (result_[i] >= base_)
			{
				
				result_[i + 1] += result_[i] / base_;
				result_[i] %= base_;
			}
		}
		
		bigInteger_.clear();

		j = static_cast<int>(size_);
		for (--j; j >= 0; --j)
		{
			//if (result_[i] >= 0)
			//{ 
				char k = result_[j] + '0';
				bigInteger_.push_back(k);
			//}
		}




		std::cout << this << " reload operator +\n";
		return std::move(bigInteger_);
	};

	size_t getSize() { return size_; }

	~BigInteger() { std::cout << '\n' << this << " Destructor BigInteger()\n"; };
};