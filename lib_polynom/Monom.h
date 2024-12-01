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
	CMonom(float coeff = 1.0, int pow1 = 1, int pow2 = 1, int pow3 = 1) : _coeff(coeff){
		_powess[0] = pow1;
		_powess[1] = pow2;
		_powess[2] = pow3;
	};
	CMonom operator*(const CMonom& other) const;
	CMonom& operator*=(const CMonom& monom);
	CMonom operator/(const CMonom& other) const;
	CMonom& operator/=(const CMonom& monom);
	CMonom operator-(const CMonom& other) const;
	CMonom operator+(const CMonom& other) const;
	bool operator!=(const CMonom& monom) const noexcept;
	bool operator==(const CMonom& monom) const noexcept;
	CMonom& operator=(const CMonom& monom) noexcept;
	CMonom& operator+=(const CMonom& monom);
	CMonom& operator-=(const CMonom& monom);
	void print() const;
	float getCoeff() const noexcept;
	int getPow(int i) const;
};

float CMonom::getCoeff() const noexcept {
	return _coeff;
}

int CMonom::getPow(int i) const {
	if (i < 0 || i >= Vars_count) {
		throw std::out_of_range("Exponent index out of range.");
	}
	return _powess[i];
}

void CMonom::print() const{
	std::cout << _coeff << "x^" << _powess[0] << "y^" << _powess[1] << "z^" << _powess[2];
}

CMonom::CMonom(const CMonom& other) {
	_coeff = other._coeff;
	for (int i = 0; i < 3; i++) {
		_powess[i] = other._powess[i];
	}
}

CMonom& CMonom::operator=(const CMonom& other) noexcept {
	return CMonom(
		_coeff = other._coeff,
		_powess[0] = other._powess[0],
		_powess[1] = other._powess[1],
		_powess[2] = other._powess[2]
	);
}

CMonom CMonom::operator*(const CMonom& other) const {
	return CMonom(
		_coeff * other._coeff,
		_powess[0] + other._powess[0],
		_powess[1] + other._powess[1],
		_powess[2] + other._powess[2]
		);
}

CMonom& CMonom::operator*=(const CMonom& other){
	return CMonom(
		_coeff *= other._coeff,
		_powess[0] += other._powess[0],
		_powess[1] += other._powess[1],
		_powess[2] += other._powess[2]
	);
}

CMonom CMonom::operator+(const CMonom& other) const {
	for (int i = 0; i < Vars_count; ++i) {
		if (_powess[i] != other._powess[i]) {
			throw std::invalid_argument("Exponents must be the same to add monomials.");
		}
	}
	return CMonom(_coeff + other._coeff, _powess[0], _powess[1], _powess[2]);
}

CMonom& CMonom::operator+=(const CMonom& other){
	for (int i = 0; i < Vars_count; ++i) {
		if (_powess[i] != other._powess[i]) {
			throw std::invalid_argument("Exponents must be the same to add monomials.");
		}
	}
	_coeff += other._coeff;
	return *this;
}

CMonom CMonom::operator/(const CMonom& other) const {
	return CMonom(
		_coeff / other._coeff,
		_powess[0] - other._powess[0],
		_powess[1] - other._powess[1],
		_powess[2] - other._powess[2]
	);
}

CMonom& CMonom::operator/=(const CMonom& other) {
	_coeff /= other._coeff;
	_powess[0] -= other._powess[0];
	_powess[1] -= other._powess[1];
	_powess[2] -= other._powess[2];
	return *this;
}

CMonom CMonom::operator-(const CMonom& other) const {
	for (int i = 0; i < Vars_count; ++i) {
		if (_powess[i] != other._powess[i]) {
			throw std::invalid_argument("Exponents must be the same to add monomials.");
		}
	}
	return CMonom(_coeff - other._coeff, _powess[0], _powess[1], _powess[2]);
}

CMonom& CMonom::operator-=(const CMonom& other) {
	for (int i = 0; i < Vars_count; ++i) {
		if (_powess[i] != other._powess[i]) {
			throw std::invalid_argument("Exponents must be the same to add monomials.");
		}
	}
	_coeff -= other._coeff;
	return *this;
}

bool CMonom::operator!=(const CMonom& monom) const noexcept {
	for (int i = 0; i < Vars_count; ++i) {
		if (_powess[i] != monom._powess[i]) {
			return true;
		}
	}
	return false;
}

bool CMonom::operator==(const CMonom& monom) const noexcept {
	for (int i = 0; i < Vars_count; ++i) {
		if (_powess[i] != monom._powess[i]) {
			return false;
		}
	}
	return true;
}
#endif  // LIB_STACH_MONOM_H_