#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <chrono>
#include "../lib_list/TList.h"




//void testPopFront(TList<int>& list, int n) {
//    for (int i = n; i > 0; i--) {
//        list.pop_front();
//    }
//}

void testFind(TList<int>& list, const int& value) {
    list.find(value);
}

//void testPushFront(TList<int>& list, int n) {
//    for (int i = 0; i < n; i++) {
//        list.push_front(rand() % 1000);
//    }
//}

double Time(TList<int>& list, const int& val) {
    auto start = std::chrono::high_resolution_clock::now();
    testFind(list, val);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}

