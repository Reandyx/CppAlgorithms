#include<iostream>
using namespace std;

int LinearSearch(int* array, int size, int key)
{
	for (int i = 0; i < size; ++i)
	{
		if (array[i] == key)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	//to add the custom size array 
	const int size = 100;			
	cout << "\nEnter the size of the Array (temp. it's disabled): ";
	//cin >> size;
	int array[size];
	int key;
	//Input array
	cout << "\nEnter the Array of " << size << " numbers : ";
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
	cout << "\nEnter the number to be searched : ";
	cin >> key;
	int index = LinearSearch(array, size, key);
	if (index != -1)
	{
		cout << "\nNumber found at index : " << index;
	}
	else
	{
		cout << "\nNot found";
	}
	return 0;
}