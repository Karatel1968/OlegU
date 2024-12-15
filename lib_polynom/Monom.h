// Copyright 2024 Urin Oleg

#ifndef LIB_STACH_MONOM_H_
#define LIB_STACH_MONOM_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <sstream>
#include <string>
#include <regex>

#define Vars_count 3

class CMonom {
	float _coeff;
	int _powess[Vars_count];
	void parse(const std::string& str);
		

public:
	CMonom(const CMonom& other);
	//CMonom(float _coeff, int powess);
	CMonom(float coeff = 1.0, int pow1 = 1, int pow2 = 1, int pow3 = 1);
	CMonom(const std::string& str);
	
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
	CMonom operator-() const;
	void print2(std::ostream& os = std::cout) const;
	void print() const;
	float getCoeff() const noexcept;
	int getPow(int i) const;

	double evaluate(double x, double y, double z) const;

	bool operator<(const CMonom& other) const;
};


#endif  // LIB_STACH_MONOM_H_