#include "CrossArray.hpp"

int main() {
    // Test constructor and basic functionality
    sjtu::CrossArray ca(3);
    
    // Test InsertArrays
    int arr1[] = {1, 2, 3};
    bool result1 = ca.InsertArrays(arr1, 3);
    
    int arr2[] = {4, 5};
    bool result2 = ca.InsertArrays(arr2, 2);
    
    // Test At function
    int val = ca.At(0, 1);  // Should be 2
    
    // Test AtArray function
    const int* ptr = ca.AtArray(1);  // Should point to arr2
    
    // Test copy constructor
    sjtu::CrossArray ca2(ca);
    
    // Test IsSame
    bool same = ca.IsSame(ca2);  // Should be false
    
    // Test WhichGreater
    sjtu::CrossArray& greater = ca.WhichGreater(ca2);  // Should return ca
    
    // Test AppendArrays
    int arr3[] = {6, 7, 8};
    ca.AppendArrays(arr3, 0, 3);  // Append to first array
    
    // Test DoubleCrossLength
    ca.DoubleCrossLength();  // Should double capacity to 6
    
    return 0;
}