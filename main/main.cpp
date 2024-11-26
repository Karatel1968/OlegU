// Copyright 2024 Urin Oleg
#include <iostream>
#include <iomanip>
#include "../lib_easy_example/easy_example.h"
#include "../lib_pair/pair.h"
#include "../lib_stack/TStack.h"
#include "../lib_parser/parser.h"
#include <vector>
#include <string>
#include <clocale>
#include "../lib_list/TList.h"
#include "../lib_experiments/experiments.cpp"
#include "../lib_dmassive/dmassive.h"
#include "../lib_stack/TStack.h"

//#define BRACETS
//#define TITERATOR
#define EXPERIMENTS

#ifdef EXPERIMENTS
int main() {
    srand(static_cast<unsigned int>(time(0)));
    TList<int> list;
    
    int n = 100;
    //int* data = new int[n];
    //TStack<int> stack(n);
    int val = 10;
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    for (int i = 0; i < n - 1; i++) {
        list.push_front(rand() % n);
        //data[i] = rand() % n;
        //stack.push(rand() % n);
    };

    std::cout << Time(list, val) << std::endl;

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
    TList<int> list;
    //TList<int>::iterator it = list.begin();

    list.push_front(1);
    list.push_back(2);
    list.push_back(3);

    for (TList<int>::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (TList<int>::iterator it = list.begin(); it != list.end(); ++it) {
        *it = 5;
    }
    std::cout << std::endl;

    for (TList<int>::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    while (!list.isEmpty()) {
        list.pop_front();
    }
    for (TList<int>::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}

#endif
