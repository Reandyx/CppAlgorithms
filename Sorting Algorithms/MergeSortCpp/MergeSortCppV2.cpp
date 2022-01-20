/*
a merge sort algorithm without output implemetation so in fact it's to do in the future
*/
#include <iostream>
#include <vector>
#include <queue>
 
template<class T>
void merge(std::vector<T> &vec, int low, int mid, int high)
{
    int index = low;
    std::queue<T> left;
    std::queue<T> right;
 
    for (int i = low; i <= mid; i++) {
        left.push(vec[i]);
    }
    for (int i = mid + 1; i <= high; i++) {
        right.push(vec[i]);
    }
 
    while (!left.emtpy() && !right.empty()) {
        if (left.front() < right.front()) {
            vec[index] = left.front();
            left.pop();
        }
        else {
            vec[index] = right.front();
            right.pop();
        }
        index++;
    }
    while (!left.empty()) {
        vec[index] = left.front();
        left.pop();
        index++;
    }
 
    while (!right.empty()) {
        vec[index] = right.front();
        right.pop();
        index++;
    }
     
}
 
template<class T>
void merge_sort(std::vector<T> &vec, int low, int high)
{
    if (low < high) {
        int middle = (low + high) / 2;
        merge_sort(vec, low, middle);
        merge_sort(vec, middle + 1, high);
        merge(vec, low, middle, high);
    }
}

