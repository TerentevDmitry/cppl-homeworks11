#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <charconv>
#include <math.h>
#include <algorithm>

class BigInteger
{
private:
	std::string bigInteger_;
	std::vector<int> bigIntegerTemp_{};
	std::string bigIntegerResult_;

	int base_ = 10; //система исчисления
	size_t size_ = 0; //размер bigInteger_

	
public:
	BigInteger(const std::string& value) : bigInteger_{ value }, size_{ value.size() }
	{ 
		if (value == "") bigInteger_ = '0';
		std::cout << this << " Constructor BigInteger(T value)\n"; 
	};

	////Copy Constructor
	BigInteger(const BigInteger& other) : bigInteger_{ other.bigInteger_ }, bigIntegerTemp_{ other.bigIntegerTemp_ }, size_{other.size_}
	{ 
		std::cout << this << " Copy Constructor\n";
	};

	// Copy assignment Constructor=
	BigInteger& operator=(const BigInteger& other)
	{
		if (this != &other) // not a self-assignment
		{
			bigInteger_ = other.bigInteger_;
			bigIntegerTemp_ = other.bigIntegerTemp_;
			size_ = other.size_;
			std::cout << this << " Copy Assignment Constructor\n";
		}
		return *this;
	};

	//Move Constructor
	BigInteger(BigInteger&& other) noexcept : bigInteger_{ std::move(other.bigInteger_) }, bigIntegerTemp_{ std::move(other.bigIntegerTemp_) }, size_{ std::move(other.size_) }
	{ 
		other.bigIntegerTemp_.clear();
		other.bigInteger_.clear();
		other.size_ = 0;
		std::cout << this << " Move Constructor\n"; 
	};

	// Move assignment Constructor=
	BigInteger& operator=(BigInteger&& other) noexcept
	{
		if (this != &other) // not a self-assignment
		{
			bigInteger_ = std::move(other.bigInteger_);
			bigIntegerTemp_ = std::move(other.bigIntegerTemp_);
			size_ = other.size_;
			other.size_ = 0;
			std::cout << this << " Move Assignment Constructor\n";
		}
		return *this;
	};

	std::string operator+(BigInteger& other)
	{
		bigIntegerResult_.clear();
		other.bigIntegerResult_.clear();
		//bigIntegerResult_ копия  bigInteger_ для изменения и вывода в майн
		bigIntegerResult_ = bigInteger_;
		other.bigIntegerResult_ = other.bigInteger_;

		//проверка на то что оба числа нулевые
		if ((bigIntegerResult_[0] == '0' && bigIntegerResult_.size() == 1) && (other.bigIntegerResult_[0] == '0' && other.bigIntegerResult_.size() == 1))
			return bigIntegerResult_;

		//кол-во раз делать bigInteger_.insert
		int deltaSize = std::abs((static_cast<int>(size_) - static_cast<int>(other.size_)));

		//равняем по размеру и вставляем в начало '0' для соблюдения разрядности
		if (size_ > other.size_)
		{
			other.size_ = size_;
			auto it = other.bigIntegerResult_.begin();
			for (int i = 0; i < deltaSize; i++)
			{
				other.bigIntegerResult_.insert(it, '0');
			}
		}
		else if (size_ < other.size_)
		{
			size_ = other.size_;
			auto it = bigIntegerResult_.begin();
			for (int i = 0; i < deltaSize; i++)
			{
				bigIntegerResult_.insert(it, '0');
			}
		}

		bigIntegerTemp_.clear(); //чистим массив стрингов и пишем туда ответ
		bigIntegerTemp_.reserve(size_ + 1); //резерв места в векторе
		other.bigIntegerTemp_.reserve(size_ + 1); //резерв места в векторе

		int j = static_cast<int>(size_);
		int h = 0;

		//складываем поразрядно
		for (--j; j >= 0; --j, h++)
		{
			bigIntegerTemp_.push_back((bigIntegerResult_[j] - '0') + (other.bigIntegerResult_[j] - '0'));
			if (bigIntegerTemp_[h] < 0)
				bigIntegerTemp_[h] = 0;
		}
		//проверка необходимости добавить еще разряд вверху
		if (bigIntegerTemp_[static_cast<int>(size_) - static_cast<int>(1)] >= 9)
		{
			j = static_cast<int>(size_) + 1;
			bigIntegerTemp_.push_back(0);
		} else 
		{ j = static_cast<int>(size_); }
		
		//переносим десятки на разряд выше
		for (size_t i = 0; i < size_; i++)
		{
			if (bigIntegerTemp_[i] >= base_)
			{
				bigIntegerTemp_[i + 1] += bigIntegerTemp_[i] / base_;
				bigIntegerTemp_[i] %= base_;
			}
		}

		bigIntegerResult_.clear(); //чистим массив стрингов и пишем туда ответ
		
		for (--j; j >= 0; --j)
		{
			char k = bigIntegerTemp_[j] + '0';
			bigIntegerResult_.push_back(k);
		}

		//std::cout << this << " operator +";
		return bigIntegerResult_;
	};
	
	// down *****************************************************************
	std::string operator*(BigInteger& other)
	{
		bigIntegerResult_.clear();
		other.bigIntegerResult_.clear();
		bigIntegerTemp_.clear();
		//bigIntegerResult_ копия  bigInteger_ для изменения и вывода в майн
		bigIntegerResult_ = bigInteger_;
		other.bigIntegerResult_ = other.bigInteger_;

		//проверка на ноль
		if ((bigIntegerResult_[0] == '0' && bigIntegerResult_.size() == 1) || (other.bigIntegerResult_[0] == '0' && other.bigIntegerResult_.size() == 1))
			return bigIntegerResult_ = '0';

		bigIntegerTemp_.clear(); //чистим массив стрингов и пишем туда ответ

		int max_size = bigIntegerResult_.size() + other.bigIntegerResult_.size();

		BigInteger::bigIntegerTemp_.resize(max_size, 0);

		for (int i = bigIntegerResult_.size() - 1; i >= 0; --i)
		{
			for (int j = other.bigIntegerResult_.size() - 1; j >= 0; --j)
				bigIntegerTemp_[max_size - 2 - i - j] += (bigIntegerResult_[i] - '0') * (other.bigIntegerResult_[j] - '0');
		}

		for (int i = 0; i < bigIntegerTemp_.size() - 1; i++)
		{
			bigIntegerTemp_[i + 1] += bigIntegerTemp_[i] / base_;
			bigIntegerTemp_[i] %= base_;
		}

		while (bigIntegerTemp_.back() == 0)
		{
			bigIntegerTemp_.pop_back();
		}

		std::reverse(bigIntegerTemp_.begin(), bigIntegerTemp_.end());

		bigIntegerResult_.clear(); //чистим массив стрингов и пишем туда ответ

		for (auto i : bigIntegerTemp_)
		{
			char k = i + '0';
			bigIntegerResult_.push_back(k);
		}
		return bigIntegerResult_;
	}

// up *****************************************************************




	friend std::ostream& operator<< (std::ostream& out, const BigInteger& point);

	size_t getSize() { return size_; }

	~BigInteger() 
	{
		std::cout << '\n' << this << " Destructor BigInteger()"; 
	};
};