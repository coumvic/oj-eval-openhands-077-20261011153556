#include "CrossArray.hpp"

int main() {
    // Simple test to ensure compilation
    sjtu::CrossArray ca(5);
    
    int test_array[] = {1, 2, 3, 4, 5};
    ca.InsertArrays(test_array, 5);
    
    return 0;
}