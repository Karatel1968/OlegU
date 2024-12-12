#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <windows.h>
#include <psapi.h>
#include "../lib_list/TList.h"
#include "../lib_stack/TStack.h"
#include <string>
#include <iomanip>



//size_t getCurrentMemoryUsage() {
//    PROCESS_MEMORY_COUNTERS pmc;
//    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
//    return pmc.WorkingSetSize;
//}

//void printMemoryUsage() {
//    _CrtMemState s1;
//    _CrtMemCheckpoint(&s1);
//    std::cout << "Memory usage: " << s1.lSizes[0] << " bytes" << std::endl;
//}
//void testPopFront(TList<int>& list, int n) {
//    for (int i = n; i > 0; i--) {
//        list.pop_front();
//    }
//}
    

void testPopBack(TList<int>& list) {
    list.pop_back();
}

//void testpush(TStack<int>& stack, int n) {
//    //for (int i = 0; i < n; i++) {
//    //    //list.pop_back();
//    //    if (data[i] == val) {
//    //        data[i] = 7;
//    //    }
//    //}
//    stack.push(1);
//}

double Time(TList<int>& list) {
    auto start = std::chrono::high_resolution_clock::now();
    /*std::cout << "Initial memory usage:" << std::endl;
    printMemoryUsage();*/
    testPopBack(list);
    /*std::cout << "Final memory usage:" << std::endl;
    printMemoryUsage();*/
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}

