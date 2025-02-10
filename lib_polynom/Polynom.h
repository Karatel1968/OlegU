// Copyright 2024 Urin Oleg

#ifndef LIB_STACH_POLYNOM_H_
#define LIB_STAC_POLYNOM_H_

#include "../lib_list/TList.h"
#include "../lib_polynom/Monom.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <type_traits>
#include <sstream>
#include <string>
#include <regex>

#define Vars_count 3

class CPolynom {
	static char _names[Vars_count];
	TList<CMonom> _monom;

    void parse(const std::string& str) {
        std::regex pattern(R"(([-+]?\d*\.?\d*)x\^(\d+)y\^(\d+)z\^(\d+))");
        std::sregex_iterator iter(str.begin(), str.end(), pattern);
        std::sregex_iterator end;

        for (; iter != end; ++iter) {
            std::smatch match = *iter;
            CMonom m(std::stod(match[1].str()),
                std::stoi(match[2].str()),
                std::stoi(match[3].str()),
                std::stoi(match[4].str()));
            addMonom(m);
        }
    }
public:
    CPolynom() {};
	CPolynom(const CPolynom& pol);
	CPolynom(std::string pol);

    void addMonom(const CMonom& monom) {
        _monom.push_back(monom);
    }

    void CPolynom::print2(std::ostream& os) const {
        for (const auto& m : _monom) {
            m.print2(os);
            os << " + ";
        }
        os << "0"; // Для красоты вывода
    }

    std::string CPolynom::toString() const {
        std::ostringstream oss;
        for (const auto& m : _monom) {
            oss << m.getCoeff() << "x^" << m.getPow(0) << "y^" << m.getPow(1) << "z^" << m.getPow(2) << " + ";
        }
        oss << "0"; // Для красоты вывода
        return oss.str();
    }
    
    void print() const {
        for (const auto& m : _monom) {
            m.print();
            std::cout << " + ";
        }
        std::cout << "0"; 
    }

    double evaluate(double x, double y, double z) const {
        double result = 0.0;
        for (const auto& m : _monom) {
            result += m.evaluate(x, y, z);
        }
        return result;
    }

    CPolynom CPolynom::operator+(const CPolynom& other) const {
        CPolynom result(*this);
        for (const auto& m : other._monom) {
            result.addMonom(m);
        }
        return result;
    }

    CPolynom CPolynom::operator-(const CPolynom& other) const {
        CPolynom result(*this);
        for (const auto& m : other._monom) {
            result.addMonom(-m);
        }
        return result;
    }

    CPolynom CPolynom::operator*(const CPolynom& other) const {
        CPolynom result;
        for (const auto& m1 : _monom) {
            for (const auto& m2 : other._monom) {
                result.addMonom(m1 * m2);
            }
        }
        return result;
    }

    CPolynom CPolynom::operator/(const CPolynom& other) const {
        CPolynom result;
        for (const auto& m1 : _monom) {
            for (const auto& m2 : other._monom) {
                /*if (m1.getPow(0) >= m2.getPow(0) &&
                    m1.getPow(1) >= m2.getPow(1) &&
                    m1.getPow(2) >= m2.getPow(2)) {
                    CMonom quotient(
                        m1.getCoeff() / m2.getCoeff(),
                        m1.getPow(0) - m2.getPow(0),
                        m1.getPow(1) - m2.getPow(1),
                        m1.getPow(2) - m2.getPow(2)
                    );*/
                    result.addMonom(m1 / m2);
                
            }
        }
        return result;
    }

    /*typedef TList<CMonom>::iterator iterator;
    typedef TList<CMonom>::const_iterator const_iterator;

    iterator begin() { return _monom.begin(); }
    const_iterator begin() const { return _monom.begin(); }
    iterator end() { return _monom.end(); }
    const_iterator end() const { return _monom.end(); }*/
};

CPolynom::CPolynom(const CPolynom& pol) : _monom(pol._monom) {}

CPolynom::CPolynom(std::string pol) {
    parse(pol);
}


#endif  // LIB_STAC_POLYNOM_H_