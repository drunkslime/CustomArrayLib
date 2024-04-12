// array.h

#ifndef ARRAY_H
#define ARRAY_H

#include <bits/stdc++.h>
using namespace std;

/// @brief Custom array class to create any form of array
/// @tparam T datatype parameter 
/// @tparam N amount of elements 
template <typename T, size_t N>
class Array{
    public:
        T data[N];

        /// @brief A method to check if target is inside the array
        /// @param req target value
        /// @return True if target found, otherwise - false
        bool is_inside(T req){
            for(const T& n : data){
                if (req == n){
                    return true;
                }
            }
            return false;
        }

        /// @brief A method to find the certain component
        /// @param req target value
        /// @return Returns a pointer to the position of the target in the array. Returns nullptr if not found.
        T* search(T req){
            for(T& n : data){
                if (req == n){
                    return &n;
                }
            }
            return nullptr;
        } 

        /// @brief A method to perform a binary search for the array
        /// @param target target value
        /// @return Returns a pointer to the position of the target in the array. Returns nullptr if not found.
        T* binarySearch(const T target){
            if(is_sorted()) {
                int low = 0, high = N - 1;
                while (low <= high) {
                    int middle = low + ((high - low) / 2);
                    T val = data[middle];
                    if (val < target) { low = middle + 1; }
                    else if (val > target) { high = middle - 1; }
                    else { return &data[middle]; }
                }
            } else { std::cerr << "Can't perform binary search on the unsorted array."; }
            return nullptr;
        }
    
        /// @brief Interpolation search method through recursion; Runtime avg.: O(log2(log2 n)); worst: O(n) 
        /// @param target target
        /// @param low Starting index; SET BY DEFAULT, DO NOT CHANGE (unless you know what are you doing)
        /// @param high Ending index; SET BY DEFAULT, DO NOT CHANGE (unless you know what are you doing)
        /// @return Returns pointer to the target in array or nullptr if not found.
        T* interpolationSearch(const T target, int low = 0, int high = (N - 1)){
            if(is_sorted()){
                int pos;
                if (low <= high && target >= data[low] && target <= data[high]){
                    
                    pos = low + 
                                (((double)(high - low) / (data[high] - data[low])) 
                                * (target - data[low]));
                    
                    if (data[pos] == target) return *data[pos];
                    if (data[pos] < target) return interpolationSearch(target, pos + 1, high);
                    if (data[pos] > target) return interpolationSearch(target, low, pos - 1);
                }
            } else { std::cerr << "Can't perform interpolation search on the unsorted array."; }
            return nullptr;
        }

        /// @brief A method to sort an array
        /// @param asc True by defaul, meaning it will sort in ascending order. If set false will sort in descending.
        void sort(bool asc = true){
            bool swapped;
            for(int i = 0; i < N - 1; i++){
                swapped = false;
                for(int j = 0; j < N - i - 1; j++){
                    if (asc) {
                        if(data[j] > data[j+1]){
                            swap(data[j], data[j+1]);
                            swapped = true;
                        }
                    } else {
                        if(data[j] < data[j+1]){
                            swap(data[j], data[j+1]);
                            swapped = true;
                        }
                    }
                }
                if (!swapped)
                break;
            }
        }

        /// @brief A method to check if the array is sorted
        /// @param asc true by defaul, meaing that it is logic is for the ascending order. False for descending.
        /// @return Returns false if not sorted, true if sorted
        bool is_sorted(bool asc = true){ //asc[ending]
            if (asc){
                for (size_t i = 1; i < N; i++){
                    if(data[i] < data[i-1]){
                        return false;
                    }
                }
            } else {
                for (size_t i = 1; i < N; i++){
                    if(data[i] > data[i-1]){
                        return false;
                    }
                }
            }
            return true;
        }

        /// @brief A method to get arrays length
        /// @return size_t value meaning the amount of elements in the array
        size_t length(){
            return N;
        }
};

    /// @brief A function to find the array's length
    /// @tparam T datatype parameter
    /// @tparam N amount of elements
    /// @param arr passing array of ambiguous type and size
    /// @return length, type size_t
    template <typename T, size_t N>
    size_t arrlen(const T (&arr)[N]){
            return N; // <-- somehow returns the amount of elements and not size in bytes or anything
        }


#endif