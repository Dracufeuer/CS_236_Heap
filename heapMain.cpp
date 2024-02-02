//
//  heapMain.cpp
//  PR-4
//  Class: CS 236
//  Semester: Fall 2023
//  Name: Marcus Shaw
//  Created by Marcus Shaw on 11/9/23.
//

#include <iostream>
#include "heap.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    string arr[6] = {"D", "B", "A", "C", "F", "E"};
    heap a;
    a.heapify(arr, (sizeof(arr)/sizeof(string)));
    a.heapSort();
    
    
    return 0;
}
