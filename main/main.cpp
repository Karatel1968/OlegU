// Copyright 2024 Marina Usova

//#define EASY_EXAMPLE


#include <iostream>
#include <iomanip>
#include "../lib_easy_example/easy_example.h"
#include "../lib_pair/pair.h"

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
};

#endif  // EASY_EXAMPLE

int main() {

    TPair<int, double> pair1(2, 5.8);


    TPair<int, double> pair2(1, 2);

    std::cout << "Pair 1: " << pair1 << std::endl;
    std::cout << "Pair 2: " << pair2 << std::endl;


    TPair<int, double> pair3 = pair1 + pair2;
    std::cout << "Pair 3 (Pair 1 + Pair 2): " << pair3 << std::endl;

    pair1 -= pair2;
    std::cout << "Pair 1 after subtraction (Pair 1 - Pair 2): " << pair1 << std::endl;

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
    std::cout << "Pair 1 after setting first element to 10: " << pair1 << std::endl;

    pair1.set_second(20);
    std::cout << "Pair 1 after setting second element to 20: " << pair1 << std::endl;

    pair1.swap(pair2);

    std::cout << pair1 << std::endl;
    std::cout << pair2 << std::endl;

    return 0;
}

