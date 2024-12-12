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
};

CPolynom::CPolynom(const CPolynom& pol) {

}

CPolynom::CPolynom(std::string pol) {
    parse(pol);
}


#endif  // LIB_STAC_POLYNOM_H_