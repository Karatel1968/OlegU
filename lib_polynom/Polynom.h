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
	TList<CMonom> monom;
public:
	CPolynom();
	CPolynom(const CPolynom& pol);
	CPolynom(std::string pol);
};

CPolynom::CPolynom(std::string pol) {

}
#endif  // LIB_STAC_POLYNOM_H_