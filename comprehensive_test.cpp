#include "CrossArray.hpp"

int main() {
    // Test 1: Basic constructor and destructor
    {
        sjtu::CrossArray ca(5);
        // Destructor should be called here
    }
    
    // Test 2: InsertArrays functionality
    sjtu::CrossArray ca(3);
    int arr1[] = {1, 2, 3};
    bool result = ca.InsertArrays(arr1, 3);
    
    // Test 3: At function with valid indices
    int val = ca.At(0, 0);  // Should be 1
    val = ca.At(0, 2);      // Should be 3
    
    // Test 4: AtArray function
    const int* ptr = ca.AtArray(0);  // Should point to arr1
    ptr = ca.AtArray(1);             // Should be nullptr
    
    // Test 5: Copy constructor
    sjtu::CrossArray ca2(ca);
    bool same = ca.IsSame(ca2);  // Should be false
    
    // Test 6: WhichGreater
    sjtu::CrossArray& greater = ca.WhichGreater(ca2);
    
    // Test 7: AppendArrays
    int arr2[] = {4, 5};
    ca.AppendArrays(arr2, 0, 2);
    
    // Test 8: DoubleCrossLength
    ca.DoubleCrossLength();
    
    // Test 9: Insert more arrays
    int arr3[] = {6, 7, 8, 9};
    ca.InsertArrays(arr3, 4);
    
    // Test 10: Edge cases
    sjtu::CrossArray ca3(1);
    int arr4[] = {10};
    ca3.InsertArrays(arr4, 1);
    
    // Test capacity limit
    bool result2 = ca3.InsertArrays(arr4, 1);  // Should return false
    
    return 0;
}