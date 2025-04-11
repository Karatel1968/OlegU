// Copyright 2024 Urin Oleg
#include <iostream>
#include <iomanip>
#include <list>
#include "../lib_easy_example/easy_example.h"
#include "../lib_pair/pair.h"
#include "../lib_stack/TStack.h"
#include "../lib_parser/parser.h"
#include <vector>
#include <string>
#include <clocale>
#include <ctime>
#include <cstdlib>
#include "../lib_list/TList.h"
#include "../lib_experiments/experiments.cpp"
//#include "../lib_dmassive/dmassive.h"
#include "../lib_stack/TStack.h"
#include "../lib_algorithms/algorithms.cpp"
#include "../lib_binary_search_tree/TBinSearchTree.h"
#include "../lib_binary_search_tree/BTreeNode.h"
#include "../lib_max_heap/TMaxHeap.h"
#include "../lib_min_heap/TMinHeap.h"
#include "../lib_hash_table/Hash_table_open_mix.h"
//#include "../lib_dsu/dsu.cpp"
//#define BRACETS
//#define TITERATOR
//#define EXPERIMENTS
//#define EXP
//#define Tree
//#define LABIRINTH
//#define TMaxHeap
#define HASHTABLE
//#define LISTMERGE
#ifdef EXP
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
}; // либо объединённая "константа" с помощью шаблона - TCONST

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
    std::list<Lexem> _expression;
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
private:
    void delete_spaces(std::string* exp) {}

    
    //void check();
    //void build_polish_record();
};

int main() {
    Lexem new_lexem("11.11", FLOAT_CONST);
    Expression exp1("14.43");
    std::string exp = "14.45";
    
    exp1.parse(exp);
    exp1.print();

    system("pause");
    return 0;
}
#endif

#ifdef EXPERIMENTS
int main() {
    srand(static_cast<unsigned int>(time(0)));
    TList<int> list;
    
    int n = 100;
    //int* data = new int[n];
    //TStack<int> stack(n);
    int val = rand() % n;
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    for (int i = 0; i < n; i++) {
        list.push_front(rand() % n);
        //data[i] = rand() % n;
        //stack.push(rand() % n);
    };

    std::cout << Time(list) << std::endl;

    return 0;
}
#endif

#ifdef EASY_EXAMPLE

int main() {
  int a, b;
  float result;

  a = 1; b = 4;

  try {
      result = division(a, b);
      std::cout << a << " / " << b << " = "
          << std::setprecision(2) << result << std::endl;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }

  a = 1; b = 0;

  try {
      result = division(a, b);
      std::cout << a << " / " << b << " = "
          << std::setprecision(2) << result << std::endl;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }

  return 0;
}
#endif

#ifdef PAIR

int main() {
    TPair<int, double> pair1(2, 5.8);


    TPair<int, double> pair2(1, 2);

    std::cout << "Pair 1: " << pair1 << std::endl;
    std::cout << "Pair 2: " << pair2 << std::endl;


    TPair<int, double> pair3 = pair1 + pair2;
    std::cout << "Pair 3 (Pair 1 + Pair 2): " << pair3 << std::endl;

    TPair<int, double> pair4 = pair1 - pair2;
    std::cout << "Pair 4 (Pair 1 - Pair 2): " << pair4 << std::endl;

    pair1 -= pair2;
    std::cout << "Pair 1 after subtraction \
    (Pair 1 - Pair 2): " << pair1 << std::endl;

    if (pair1 == pair2) {
        std::cout << "Pair 1 is equal to Pair 2" << std::endl;
    }
    else {
        std::cout << "Pair 1 is not equal to Pair 2" << std::endl;
    }

    if (pair1 > pair2) {
        std::cout << "Pair 1 > Pair 2" << std::endl;
    }
    else {
        std::cout << "false" << std::endl;
    }

    if (pair1 < pair2) {
        std::cout << "Pair 1 < Pair 2" << std::endl;
    }
    else {
        std::cout << "false" << std::endl;
    }

    pair1.set_first(10);
    std::cout << "Pair 1 after setting first element to 10: "\
        << pair1 << std::endl;

    pair1.set_second(20);
    std::cout << "Pair 1 after setting second element to 20: \
     " << pair1 << std::endl;

    pair1.swap(pair2);

    std::cout << pair1 << std::endl;
    std::cout << pair2 << std::endl;

    return 0;
}
#endif

#ifdef BRACETS
  
int main() {
    setlocale(LC_ALL, "rus");
    const std::string str = "({[])";

    if (is_valid(str)) {
        std::cout << "Корректно" << std::endl;
    }
    else {
        std::cout << "Некорректно" << std::endl;
    }
}

#endif

#ifdef TITERATOR
    
int main() {
    TList<std::pair<int, std::string>> list;
    //TList<int>::iterator it = list.begin();

    list.push_front(std::make_pair(1, "uyu"));
    list.push_back(std::make_pair(2, "uyu"));
    list.push_back(std::make_pair(3, "uyu"));

    for (TList<std::pair<int, std::string>>::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << (*it).second << " ";
    }
    std::cout << std::endl;

    for (TList<std::pair<int, std::string>>::iterator it = list.begin(); it != list.end(); ++it) {
        (*it).second = "5";
    }
    std::cout << std::endl;

    for (TList<std::pair<int, std::string>>::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << (*it).second << " ";
    }
    std::cout << std::endl;

    while (!list.isEmpty()) {
        list.pop_front();
    }
    for (TList<std::pair<int, std::string>>::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << (*it).second << " ";
    }
    std::cout << std::endl;
    return 0;
}

#endif

#ifdef LISTMERGE
int main() {
    TList<int> list1;
    list1.push_back(4);
    list1.push_back(5);
    list1.push_back(6);
    TList<int> list2;
    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);
    list2.push_back(4);
    
    listMerge(list1, list2);

 
}
#endif

#ifdef Tree
int main() {
    TBinSearchTree<int> tree;
    tree.insert(4); 
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(7);
    tree.insert(6);
    tree.insert(9);
    tree.insert(8);
    tree.insert(11);
    tree.level(tree.getHead());
    return 0;
}
#endif

#ifdef TMaxHeap

int main() {
    int mass[] = {6, 5, 3, 2, 8, 10, 9};
    
    int n = 7;
    int k = 3;

    MinHeap<int> heap;

    heap.insert(6);
    heap.insert(5);
    heap.insert(3);

    int i = 0;
    for (k; k < n; k++) {
        heap.insert(mass[k]);
        
        mass[i] = heap.remove_min();
        i++;
    }
    
    mass[n - 3] = heap.remove_min();
    mass[n - 2] = heap.remove_min();
    mass[n - 1] = heap.remove_min();

    for (int i = 0; i < n; i++) {
        std::cout << mass[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

#endif

#ifdef LABIRINTH

int main() {
    DSU dsu;
    
    const int rows = 10;
    const int cols = 10;
    std::vector<std::vector<int>> maze(rows, std::vector<int>(cols));
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            maze[r][c] = (rand() % 100 < 30) ? 1 : 0; 
        }
    }
    maze[0][cols - 1] = 0; 
    maze[rows - 1][0] = 0; 

    
    
    
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (maze[r][c] == 0) {
                    if (r > 0 && maze[r - 1][c] == 0) {
                        dsu.Union(r , r - 1);
                    }
                    if (c > 0 && maze[r][c - 1] == 0) {
                        dsu.Union({ r, c }, { r, c - 1 });
                    }
                }
            }
        }
    

}

#endif

#ifdef HASHTABLE

int main() {

    THTableOM<int> table1(10);
    table1.insert("абажур", 1);
    table1.insert("кинотеатр", 2);
    table1.insert("самолет", 3);
    table1.insert("человек", 4);

    
    THTableOM<int> table2(10);
    table2.insert("кинотеатр", 15);
    table2.insert("музыка", 16);
    table2.insert("самолет", 17);

    //int newSize = 0;
    int newSize = table1.size() + table2.size();

    /*if (table1.size() >= table2.size()) {
        newSize = table1.size();
    }
    else {
        newSize = table2.size();
    }*/

    THTableOM<int> result(newSize);

    for (int i = 0; i < table1.size(); ++i) {
        if (table1.getState(i) == state::busy) {
            result.insert(table1.data(i).first(), table1.data(i).second());
        }
    }

    for (int i = 0; i < table2.size(); ++i) {
        if (table2.getState(i) == state::busy) {
            std::string key = table2.data(i).first();
            int value = table2.data(i).second();

            try {
                result.find(key);
                
            }
            catch (const std::logic_error&) {
                
                result.insert(key, value);
            }
        }
    }

    for (int i = 0; i < result.size(); ++i) {
        if (result.getState(i) == state::busy) {
            std::cout << result.data(i).first() << " — " << result.data(i).second() << std::endl;
        }
    }
    
    
}

#endif