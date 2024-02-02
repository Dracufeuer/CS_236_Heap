//
//  heap.cpp
//  PR-4
//
//  Created by Marcus Shaw on 11/9/23.
//

#include "heap.hpp"
using namespace std;

void heap::resizeArray() {
    int newAllocationSize = allocationSize * 2;
    string* newArr = new string[newAllocationSize];
    if(newArr) {
        for(int i = 0; i < allocationSize; i++) {
            
        }
        delete[] heapArr;
        heapArr = newArr;
        allocationSize = newAllocationSize;
    }
}
heap::heap(){
    allocationSize = 7;
    heapArr = new string[allocationSize];
    heapSize = 0;
}
heap::~heap() {
    delete[] heapArr;
}

void heap::heapify(string arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        insert(arr[i]);
        
    }
    cout << " Original array" <<'\n'; // thought htis was a convineint place to output the original array
    output(0);
}
void heap::heapSort() {
    for(int i = heapSize; i > 1; i--) {
        swap(i - 1);
        percolateDown(0, i - 1);
        if(i != 2) {
            output(2);
        }
    }
    output(3);
}
void heap::swap(int size) {
    string x = heapArr[size];
    heapArr[size] = heapArr[0];
    heapArr[0] = x;
    output(1);
    cout << heapArr[size] << '\n'; // this is so I do not need to send another variable to output
}

void heap::percolateUp(int nodeIndex) {
    while(nodeIndex > 0) {
        int parentIndex;
        parentIndex = (nodeIndex - 1)/2;
        
        if(heapArr[nodeIndex] <= heapArr[parentIndex]) {
            return;
        }
        
        else {
            string x;
            x = heapArr[nodeIndex];
            heapArr[nodeIndex] = heapArr[parentIndex];
            heapArr[parentIndex] = x;
            nodeIndex = parentIndex;
        }
    }
}

void heap::percolateDown(int nodeIndex, int Size) {
    int childIndex = 2 * nodeIndex +1;
    string x = heapArr[nodeIndex];
    
    while (childIndex < Size) {
        string minVal = x;
        int minIndex = -1;
        int i = 0;
        while(i < 2 && (i + childIndex) < Size) {
            if(heapArr[i + childIndex] > minVal) {
                minVal = heapArr[i + childIndex];
                minIndex = i + childIndex;
            }
            i++;
        }
        
        if(minVal == x) {
            return;
        }
        
        else{
            string temp = heapArr[nodeIndex]; 
            heapArr[nodeIndex] = heapArr[minIndex];
            heapArr[minIndex] = temp;
            
            nodeIndex = minIndex;
            childIndex = 2 * nodeIndex +1;
        }
    }
}
void heap::insert(string a) {
    if (heapSize == allocationSize) {
        resizeArray();
    }
    heapArr[heapSize] = a;
    heapSize++;
    
    percolateUp(heapSize - 1);
}
void heap::output(int num) {
    for(int i = 0; i < heapSize; i++) {
        cout << heapArr[i] << " ";
    }
    switch(num){
        case 0:
            cout << " Initial rebuild to form a heap";
            break;
        case 1:
            cout <<" After Swapping " << heapArr[0] << " and ";
            break;
        case 2:
            cout << " After rebuilding min heap";
            break;
        case 3:
            cout << " Sorted array";
    
    }
    if( num != 1) {
        cout << '\n';
    }
}
