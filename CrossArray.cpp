#include "CrossArray.hpp"

namespace sjtu {

CrossArray::CrossArray(int lines) {
    total_lines = lines;
    current_lines = 0;
    total_elements = 0;
    
    arrays = new int*[total_lines];
    sizes = new int[total_lines];
    
    for (int i = 0; i < total_lines; i++) {
        arrays[i] = nullptr;
        sizes[i] = 0;
    }
}

CrossArray::CrossArray(const CrossArray& o) {
    total_lines = o.total_lines;
    current_lines = o.current_lines;
    total_elements = o.total_elements;
    
    arrays = new int*[total_lines];
    sizes = new int[total_lines];
    
    for (int i = 0; i < total_lines; i++) {
        if (o.arrays[i] != nullptr) {
            sizes[i] = o.sizes[i];
            arrays[i] = new int[sizes[i]];
            for (int j = 0; j < sizes[i]; j++) {
                arrays[i][j] = o.arrays[i][j];
            }
        } else {
            arrays[i] = nullptr;
            sizes[i] = 0;
        }
    }
}

CrossArray& CrossArray::WhichGreater(CrossArray& o) {
    if (total_elements >= o.total_elements) {
        return *this;
    } else {
        return o;
    }
}

bool CrossArray::IsSame(const CrossArray& o) {
    return (arrays == o.arrays);
}

bool CrossArray::InsertArrays(const int* Input, int size) {
    if (current_lines >= total_lines) {
        return false;
    }
    
    arrays[current_lines] = new int[size];
    sizes[current_lines] = size;
    
    for (int i = 0; i < size; i++) {
        arrays[current_lines][i] = Input[i];
    }
    
    total_elements += size;
    current_lines++;
    return true;
}

void CrossArray::AppendArrays(const int* Input, int Line, int size) {
    if (Line < 0 || Line >= current_lines || arrays[Line] == nullptr) {
        return;
    }
    
    int old_size = sizes[Line];
    int* new_array = new int[old_size + size];
    
    for (int i = 0; i < old_size; i++) {
        new_array[i] = arrays[Line][i];
    }
    
    for (int i = 0; i < size; i++) {
        new_array[old_size + i] = Input[i];
    }
    
    delete[] arrays[Line];
    arrays[Line] = new_array;
    sizes[Line] = old_size + size;
    total_elements += size;
}

void CrossArray::DoubleCrossLength() {
    int new_total_lines = total_lines * 2;
    
    int** new_arrays = new int*[new_total_lines];
    int* new_sizes = new int[new_total_lines];
    
    for (int i = 0; i < total_lines; i++) {
        new_arrays[i] = arrays[i];
        new_sizes[i] = sizes[i];
    }
    
    for (int i = total_lines; i < new_total_lines; i++) {
        new_arrays[i] = nullptr;
        new_sizes[i] = 0;
    }
    
    delete[] arrays;
    delete[] sizes;
    
    arrays = new_arrays;
    sizes = new_sizes;
    total_lines = new_total_lines;
}

const int* CrossArray::AtArray(int i) {
    if (i < 0 || i >= total_lines) {
        return nullptr;
    }
    return arrays[i];
}

int& CrossArray::At(int i, int j) {
    return arrays[i][j];
}

CrossArray::~CrossArray() {
    for (int i = 0; i < total_lines; i++) {
        if (arrays[i] != nullptr) {
            delete[] arrays[i];
        }
    }
    delete[] arrays;
    delete[] sizes;
}

}