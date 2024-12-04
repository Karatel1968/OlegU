// Copyright 2024 Urin Oleg


#ifndef LIB_ARIFMETICEXPRESSION
#define LIB_ARIFMETICEXPRESSION

#include <utility>
#include <stdexcept>
#include <iostream>
#include "../lib_list/TList.h"
#include "../lib_stack/TStack.h"
#include "../lib_vector/TVector.h"

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

bool is_alph(char symbol) {
    return symbol >= 'a' && symbol <= 'z';
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

class IntConst : public Lexem {
    int _value;
public:
    IntConst(std::string exp) : Lexem(exp, INT_CONST) {
        int curr_pos = 0;
        int result = 0;
        while (is_number(exp[curr_pos])) {
            result = result * 10 + (exp[curr_pos] - '0');
            curr_pos++;
        }
        _value = result;
    }
};

class Variable : public Lexem {
    int _value;
public:
    Variable(std::string exp) : Lexem(exp, VARIABLE), _value(0.0) {}
    void set_value(double value) { _value = value; }
    double value() const { return _value; }
};

class Function : public Lexem {
    TVector<Lexem> _parameters;
    int _priority;
public:
    Function(std::string exp) : Lexem(exp, FUNCTION) {}

    void add_parameter(const Lexem& parameter) {
        _parameters.push_back(parameter);
    }

    const TVector<Lexem>& parameters() const {
        return _parameters;
    }

    void setPriority(int priority) { _priority = priority; }
};

class Brackets : public Lexem {
    int _priority;
public:
    Brackets(std::string exp) : Lexem(exp, BRACKET), _priority(0){}
    void setPriority(int priority) { _priority = priority; }
};

class Operation : public Lexem {
    int _priority;
public:
    Operation(std::string exp) : Lexem(exp, OPERATION), _priority(0) {}
    void setPriority(int priority) { _priority = priority; }
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
    void parse_number(std::string& exp, int& curr_pos);
    void parse_brackets(std::string& exp, int& curr_pos);
    void parse_var_or_funck(std::string& exp, int& curr_pos);
    void parse_operation(std::string& exp, int& curr_pos);
    void delete_spaces(std::string* exp);
    void parse(std::string exp);
    //void check();
    //void build_polish_record();
};

void Expression::delete_spaces(std::string* exp) {
    exp->erase(std::remove_if(exp->begin(), exp->end(), [](char c) { return std::isspace(c); }), exp->end());
}

void Expression::parse(std::string exp) {
    int curr_pos = 0;
    while (exp[curr_pos]) {
        if (is_number(exp[curr_pos])) {
            parse_number(exp, curr_pos);
        }
        else if (is_alph(exp[curr_pos])) {
            parse_var_or_funck(exp, curr_pos);
        }
        else if (exp[curr_pos] == '(' || exp[curr_pos] == ')') {
            parse_brackets(exp, curr_pos);
        }
        else if (exp[curr_pos] == '+' || exp[curr_pos] == '-' || exp[curr_pos] == '*' || exp[curr_pos] == '/' || exp[curr_pos] == '^') {
            parse_operation(exp, curr_pos);
        }
        curr_pos++;
    }
}

void Expression::parse_operation(std::string& exp, int& curr_pos) {
    Operation new_lexem(exp);
    _expression.push_back(new_lexem);
}

void Expression::parse_brackets(std::string& exp, int& curr_pos) {
    int start_pos = curr_pos;
    Brackets new_lexem(exp);
    _expression.push_back(new_lexem);
}

void Expression::parse_var_or_funck(std::string& exp, int& curr_pos) {
    int start_pos = curr_pos;
    while (curr_pos < exp.size() && is_alph(exp[curr_pos])) {
        curr_pos++;
    }
    std::string str = exp.substr(start_pos, curr_pos);
    if (str == "sin" || str == "cos" || str == "tg" || str == "ctg") {
        Function new_lexem(str);
        _expression.push_back(new_lexem);
    }
    else if(exp[curr_pos] >= 'a' && exp[curr_pos] <= 'z'){
        Variable new_lexem(str);
        _expression.push_back(new_lexem);
    }
    else {
        throw std::logic_error("bla bla bla");
    }
    
}

void Expression::parse_number(std::string& exp, int& curr_pos) {
    int start_pos = curr_pos;
    while (is_number(exp[curr_pos])) { curr_pos++; }
        if (exp[curr_pos] == '.') {
            curr_pos++;
            while (is_number(exp[curr_pos])) { curr_pos++; }
            FloatConst new_lexem(exp.substr(start_pos, curr_pos));
            _expression.push_back(new_lexem);
        }
        else {
            IntConst new_lexem(exp.substr(start_pos, curr_pos));
            _expression.push_back(new_lexem);
        }
}

#endif  // LIB_ARIFMETICEXPRESSION