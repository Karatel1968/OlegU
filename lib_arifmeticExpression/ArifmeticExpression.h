// Copyright 2024 Urin Oleg


#ifndef LIB_ARIFMETICEXPRESSION
#define LIB_ARIFMETICEXPRESSION

#include <utility>
#include <stdexcept>
#include <iostream>
#include "../lib_list/TList.h"
#include "../lib_stack/TStack.h"

enum ParsingErrorType {
    EXTRA_BRACKET = 1,
    MISSING_BRACKET = 2,
    MISMATCHED_BRACKET = 3,
    UNVALID_BRACKET = 4,
    NON_ERROR = 0
};

enum LexemType {
    BRACKET,
    VARIABLE,
    OPERATION,
    FUNCTION,
    INT_CONST,
    FLOAT_CONST
}; 

bool is_number(char symbol) {
    return symbol >= '0' && symbol <= '9';
}

class Lexem {
protected:
    std::string _name;
    LexemType _type;
public:
    Lexem(std::string name, LexemType type) : _name(name), _type(type) {}

    void set_name(std::string name) { _name = name; }
    void set_type(LexemType type) { _type = type; }

    std::string name() { return _name; }
    LexemType type() { return _type; }

    friend std::ostream& operator<<(std::ostream& out, const Lexem& lexem);
};

std::ostream& operator<<(std::ostream& out, const Lexem& lexem) { out << lexem._name; return out; }

class FloatConst : public Lexem {
    float _value;
public:
    FloatConst(std::string exp) : Lexem(exp, FLOAT_CONST) {
        int curr_pos = 0;
        float result = 0;
        while (is_number(exp[curr_pos])) {
            result = result * 10 + (exp[curr_pos] - '0');
            curr_pos++;
        }
        if (exp[curr_pos] == '.') {
            curr_pos++;
            float float_part = 0.0;
            int accuracy = 0;
            while (is_number(exp[curr_pos])) {
                float_part = float_part * 10 + (exp[curr_pos] - '0');
                curr_pos++;
                accuracy++;
            }
            result += float_part * pow(10, -accuracy);
        }
        _value = result;
    }

    void set_value(float value) { _value = value; }
    float value() { return _value; }
};

class Expression {
    TList<Lexem> _expression;
    // <what type?> polish_record;
public:
    Expression(std::string exp) { delete_spaces(&exp); parse(exp); }
    //void set_vars_values();
    //void calculate();
    void print() {
        // std::cout << _expression;  // если в списке есть <<
        for (auto it = _expression.begin(); it != _expression.end(); it++) {
            std::cout << *it << " ";
        }
    }
private:
    void delete_spaces(std::string* exp) {}

    void parse(std::string exp) {
        int curr_pos = 0;
        if (is_number(exp[curr_pos])) {
            int start_pos = curr_pos;
            while (is_number(exp[curr_pos])) { curr_pos++; }
            if (exp[curr_pos] == '.') {
                curr_pos++;
                while (is_number(exp[curr_pos])) { curr_pos++; }
                FloatConst new_lexem(exp.substr(start_pos, curr_pos));
                _expression.push_back(new_lexem);
            }
            else {
                //IntConst new_lexem(exp.substr(start_pos, curr_pos));
            }
        }
    }
    //void check();
    //void build_polish_record();
};

#endif  // LIB_ARIFMETICEXPRESSION