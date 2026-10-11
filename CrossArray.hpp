#ifndef CROSSARRAY_HPP
#define CROSSARRAY_HPP

namespace sjtu {
    class CrossArray {
    private:
        int** arrays;        // Pointer to array of int pointers
        int* sizes;          // Array to store size of each 1D array
        int total_lines;     // Maximum number of arrays
        int current_lines;   // Current number of inserted arrays
        int total_elements;  // Total number of elements across all arrays

    public:
        explicit CrossArray(int lines);
        CrossArray(const CrossArray& o);
        CrossArray& WhichGreater(CrossArray& o);
        bool IsSame(const CrossArray& o);
        bool InsertArrays(const int* Input, int size);
        void AppendArrays(const int* Input, int Line, int size);
        void DoubleCrossLength();
        const int* AtArray(int i);
        int& At(int i, int j);
        ~CrossArray();
    };
}

#endif // CROSSARRAY_HPP