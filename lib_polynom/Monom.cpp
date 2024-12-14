
#include "Monom.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <sstream>
#include <string>
#include <regex>




void CMonom::parse(const std::string& str) {
	std::regex pattern(R"(([-+]?\d*\.?\d*)x\^(\d+)y\^(\d+)z\^(\d+))");
	std::smatch matches;

	if (std::regex_match(str, matches, pattern)) {
		_coeff = std::stod(matches[1].str());
		_powess[0] = std::stoi(matches[2].str());
		_powess[1] = std::stoi(matches[3].str());
		_powess[2] = std::stoi(matches[4].str());
	}
	else {
		throw std::invalid_argument("Invalid monomial string format.");
	}
}

CMonom::CMonom(const std::string& str) {
	parse(str);
}

CMonom::CMonom(float coeff, int pow1, int pow2, int pow3) : _coeff(coeff) {
	_powess[0] = pow1;
	_powess[1] = pow2;
	_powess[2] = pow3;
}

CMonom CMonom::operator-() const {
	return CMonom(-_coeff, _powess[0], _powess[1], _powess[2]);
}

bool CMonom::operator<(const CMonom& other) const {
	for (int i = 0; i < Vars_count; ++i) {
		if (_powess[i] != other._powess[i]) {
			return _powess[i] > other._powess[i];
		}
	}
	return false;
}

double CMonom::evaluate(double x, double y, double z) const {
	return _coeff * std::pow(x, _powess[0]) * std::pow(y, _powess[1]) * std::pow(z, _powess[2]);
}

float CMonom::getCoeff() const noexcept {
	return _coeff;
}

int CMonom::getPow(int i) const {
	if (i < 0 || i >= Vars_count) {
		throw std::out_of_range("Exponent index out of range.");
	}
	return _powess[i];
}

void CMonom::print() const {
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

CMonom& CMonom::operator*=(const CMonom& other) {
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

CMonom& CMonom::operator+=(const CMonom& other) {
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
