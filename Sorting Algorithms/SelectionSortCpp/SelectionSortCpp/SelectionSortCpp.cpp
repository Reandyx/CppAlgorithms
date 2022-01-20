#include <iostream>
using std::cout;
using std::endl;

void printArray(int* array, int n)
{
    for (int i = 0; i < n; ++i)
        cout << array[i] << endl;
}

void selectionSort(int* array, int n)
{
    int temp;
    int min;

    for (int i = 0; i < n; ++i)
    {
        min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (array[j] < array[min])
                min = j;
        }
        if (min != i)
        {
            temp = array[i];        //swapping 
            array[i] = array[min];
            array[min] = temp;
        }
    }
}

int main()
{
    int array[] = { 95, 45, 48, 98, 485, 65, 54, 478, 1, 2325, 2137, 420, 2115, 0, 1, 20, 22 };
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Before Selection Sort :" << endl;
    printArray(array, n);

    selectionSort(array, n);

    cout << "After Selection Sort :" << endl;
    printArray(array, n);
    return 0;
}