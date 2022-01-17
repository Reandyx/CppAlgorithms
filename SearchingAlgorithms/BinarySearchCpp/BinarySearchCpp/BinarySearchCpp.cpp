#include<iostream>
#include<algorithm>
using namespace std;

int iterativeBinarySearch(int numbers[], int size, int search);
int recursiveBinarySearch(int numbers[], int begin, int end, int mid, int search);

int main() {

    int Numbers[] = { 30,23,5,9,2,1,13 };    //to add custom numbers 
    sort(Numbers, Numbers + sizeof(Numbers) / sizeof(int));// 1 2 5 9 13 23 30

    int searchingNumber;
    cout << "Enter the number you want to search : ";
    cin >> searchingNumber;

    int size = sizeof(Numbers) / sizeof(int);
    int index;
    index = iterativeBinarySearch(Numbers, size, searchingNumber);

    cout << "Iterative Binary Search : " << index << endl;

    index = recursiveBinarySearch(Numbers, 0, size - 1, size / 2, searchingNumber);

    cout << "Recursive Binary Search : " << index << endl;

    return 0;
}

int iterativeBinarySearch(int numbers[], int size, int search) {

    for (int i = 0, begin = 0, end = size - 1, mid = size / 2; i < size; i++) {

        if (numbers[mid] == search) {
            return mid;
        }
        else if (numbers[mid] < search) {
            begin = mid + 1;
            mid = (begin + end) / 2;
        }
        else {
            end = mid - 1;
            mid = (begin + end) / 2;
        }
    }
    return -1;
}

int recursiveBinarySearch(int numbers[], int begin, int end, int mid, int search) {

    if (end < begin) {
        return -1;
    }
    else if (numbers[mid] == search) {
        return mid;
    }
    else if (numbers[mid] < search) {
        return recursiveBinarySearch(numbers, mid + 1, end, (mid + 1 + end) / 2, search);
    }
    else {
        return recursiveBinarySearch(numbers, begin, mid - 1, (begin + mid - 1) / 2, search);
    }

    return -1;
}