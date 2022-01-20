#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void swap(int &large, int &small)
{
    int temp = large;
    large = small;
    small = temp;
}

int partitionFn(vector<int> &myArr, int start, int end)
{
    int pivot = myArr[end];
    int i = start;
    for (int j = start; j <= end - 1; j++)
    {
        if (myArr[j] <= pivot)
        {
            swap(myArr[j], myArr[i]);
            i++;
        }
    }
    swap(myArr[i], myArr[end]);
    return i;
}

void quickSort(vector<int> &myArr, int start, int end)
{
    if (end > start)
    {
        int partition = partitionFn(myArr, start, end);
        quickSort(myArr, start, partition - 1);
        quickSort(myArr, partition + 1, end);
    }
}

void quickSort(vector<int> &myArr)
{
    int start = 0;
    int end = myArr.size() - 1;
    quickSort(myArr, start, end);
}

void printArray(vector<int> myArr)
{
    for (int index = 0; index < myArr.size(); index++)
    {
        cout << myArr[index] << " ";
    }
}

int main()
{

    vector<int> myArr;
    int index, number, input;

    cout << "Enter the number of elements in the array : ";
    cin >> number;
    cout << "You want your array to be " << number << " well then now enter the elements of the array: " << endl;

    for (int index = 0; index < number; index++)
    {
        cin >> input;
        myArr.push_back(input);
    }

    quickSort(myArr);

    cout << "The sorted elements in ascending order are" << endl;

    printArray(myArr);

    return 0;
}