#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

const int SIZE = 5;

template <class T>
void printArray(T arrray[], int size);
template <class T>
void insertionSort(T arrray[], int size);

int main(void)
{
    string stringArray[SIZE] =
    { "beta", "gamma", "alpha", "epsilon", "delta" };       
    // test string array Adam Respond idea :D
    cout << "Unsorted array:" << endl;
    printArray(stringArray, SIZE);

    insertionSort(stringArray, SIZE);

    cout << "Sorted array:" << endl;
    printArray(stringArray, SIZE);

    cin.get();
    return EXIT_SUCCESS;
}

template <class T>
void printArray(T arrray[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arrray[i] << " ";
    cout << endl;
}
/*
template <class T>
void insertionSort(T arrray[], int size)
{
    for (int i = 1; i < size; i++)  // ar[i] is element to insert
    {
    for (int j = i; j > 0; j--)
        if (arrray[j] < arrray[j - 1])
            swap(arrray[j], arrray[j - 1]);
        else
            break;
    }
}
*/


//more efficient 
 template <class T>
 void insertionSort(T array[], int size)
{
    T temp = array[0];
    for(int i = 1; i < size; i++)  // ar[i] is element to insert
    {
        temp = array[i];
        int j = 0;
        for(j = i; j > 0; j--)
            if(temp < array[j - 1])
               array[j] = array[j - 1];
            else break;
        array[j] =  temp;
    }
}

