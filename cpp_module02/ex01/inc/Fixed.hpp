#ifndef __FIXED__H__
#define __FIXED__H__

#include <iostream>
#include <string>
#include <bitset>

class Fixed
{
private:
	int value;
	static const int bits = 8;
public:
	Fixed()
	{
		this->value = 0;
		std::cout << "Default constructor called" << std::endl;
	};
	Fixed( int n )
	{
		this->value = n << bits;
		std::cout << "Int constructor called" << std::endl;
	};
	Fixed( float floatn )
	{
		std::cout << "Float constructor called" << std::endl;
		this->value = roundf( floatn * (1 << this->bits));
	}
	Fixed(const Fixed& obj)
	{
		std::cout << "Copy constructor called" << std::endl;
		this->value = obj.getRawBits();
	};
	Fixed &operator= (const Fixed &obj)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		if (this != &obj)
		{
			this->value = obj.getRawBits();
		}
		return *this;
	};
	~Fixed()
	{
		std::cout << "Destructor called" << std::endl;
	};
	int getRawBits( void ) const
	{
		return this->value;
	};
	void setRawBits( int const raw )
	{
		this->value = raw;
		std::cout << this->value << std::endl;
	};
	float toFloat( void ) const
	{
		return static_cast<float>(this->value) / (1 << this->bits);
	};
	int toInt( void ) const
	{
		return this->value >> bits;
	};
	
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
    return os;
	};

#endif