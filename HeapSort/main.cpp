//
//  main.cpp
//  HeapSort
//
//  Created by Kevin Liu on 2024-02-04.
//

#include <iostream>
#include <vector>
#include <iterator>

void Heapify(std::vector<int> &array, long int array_size, long int root)
{
    // initialize largest as root
    long int largest = root;
    
    // left = 2i+1
    long int left = 2*root + 1;
    
    // righ = 2i+2
    long int right = 2*root + 2;
    
    // if the left child is larger than the root
    if(left < array_size && array[left] > array[largest])
        largest = left;
    
    // if the right child is larger than largest so far
    if(right < array_size && array[right] > array[largest])
        largest = right;
    
    // if largest is not the root
    if(largest != root)
    {
        std::swap(array[root], array[largest]);
        
        // recursion to the affected sub-tree
        Heapify(array, array_size, largest);
    }
}


void HeapSort(std::vector<int> &array)
{
    long int array_size = array.size();
    
    // build a heap
    for(long int i = (array_size/2)-1; i >= 0; i--)
    {
        Heapify(array, array_size, i);
    }
    
    // extract elements from the heap, one by one
    for(long int i = array_size-1; i > 0; i--)
    {
        // move the current root to the end
        std::swap(array[0], array[i]);
        
        // call max heapify on the reduced heap
        Heapify(array, array_size, 0);
    }
}


void Print(std::vector<int> &array)
{
    std::vector<int>::iterator itr;
    
    std::cout << "[    ";
    for(itr = array.begin(); itr < array.end(); itr++)
        std::cout << *itr << "    ";
    std::cout << "]\n";
    
}


int main(int argc, const char * argv[]) 
{
    std::vector<int> array = {2, 5, 4, 6, 0, -33, 45, -25, 20};
    std::cout << "Unsorted array as follows...\n";
    Print(array);
    puts("");
    
    std::cout << "Sorted array as follows...\n";
    HeapSort(array);
    Print(array);
    
    puts("");
    return 0;
}
