#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <chrono>
#include "../lib_list/TList.h"






void testPushFront(TList<int>& list, int n) {
    for (int i = 0; i < n; i++) {
        list.push_front(rand() % 1000);
    }
}

double Time(TList<int>& list, int n) {
    auto start = std::chrono::high_resolution_clock::now();
    testPushFront(list, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}

