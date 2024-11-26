// Copyright 2024 Urin Oleg

#ifndef LIB_STACH_MONOM_H_
#define LIB_STACH_MONOM_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>

#define Vars_count 3

class CMonom {
	float _coeff;
	int _powess[Vars_count];

public:
	CMonom(const CMonom& other);
	//CMonom(float _coeff, int powess);
	CMonom(float _coeff = 1.0, int pow1 = 1, int pow2 = 1, int pow3 = 1) : _coeff(_coeff) {
		_powess[0] == pow1;
		_powess[1] == pow2;
		_powess[2] == pow3;
	};
	CMonom operator*(const CMonom& other) const;
	CMonom operator/(const CMonom& other) const;
	CMonom operator-(const CMonom& other) const;
	CMonom operator+(const CMonom& other) const;
	bool operator!=(const CMonom& monom) const noexcept;
	bool operator==(const CMonom& monom) const noexcept;
	CMonom& operator=(const CMonom& monom) const noexcept;
	CMonom& operator+=(const CMonom& monom) const noexcept;
	CMonom& operator-=(const CMonom& monom) const noexcept;
};

CMonom::CMonom(const CMonom& other) {

}



#endif  // LIB_STACH_MONOM_H_