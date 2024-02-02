//
//  heap.hpp
//  PR-4
//
//  Created by Marcus Shaw on 11/9/23.
//

#ifndef heap_hpp
#define heap_hpp

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
class heap{
private:
    int heapSize; // this is to know what the size of the sored array is
    int allocationSize; // this is used to store the allocation size
    string* heapArr; // this is the heap array to be used
    
    void resizeArray(); // this is to resize the array to make it bigger
    
public:
    heap(); // this is the default constructor of a
    void heapify(string arr[], int size); // this is to use insert to create a heap inside the class
    void heapSort(); // this is to sort the heap array 
    void insert(string a); // this is to insert the next value in the heap
    void percolateDown(int nodeIndex, int heapSize); // this is to see if the childs are higher than the current parent given the node
    void percolateUp(int nodeIndex); // This is to see if the parents are less than the current node.
    void swap(int size); // this swaps the beginning and end of the unsorted heap
    void output(int num); // this is to be used for output of each line and have multiple cases depending on what needs to be outputted
    virtual ~heap(); // this is used to delete the heap array
};
#endif /* heap_hpp */
