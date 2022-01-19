#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Sorter
{
private:
	vector<int> storage;
public:
	void create(vector<int> input)
	{
		storage = input;
	}
	void bubblesort_ascending()
	{
		bool sorted = false;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < storage.size() - 1; i++)
			{
				if (storage[i] < storage[i + 1])
				{
					int temp;
					temp = storage[i];
					storage[i] = storage[i + 1];
					storage[i + 1] = temp;
					sorted = false;
				}
			}
		}
	}
	void bubblesort_descending()
	{
		bool sorted = false;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < storage.size() - 1; i++)
			{
				if (storage[i] > storage[i + 1])
				{
					int temp;
					temp = storage[i];
					storage[i] = storage[i + 1];
					storage[i + 1] = temp;
					sorted = false;
				}
			}
		}
	}
	void print()
	{
		for (int i = 0; i < storage.size(); i++)
			cout << storage[i] << " ";
		cout << endl;
	}
};
int main()
{
	vector<int> original;
	original.push_back(4);
	original.push_back(2);
	original.push_back(1);
	original.push_back(3);
	Sorter sorter;
	sorter.create(original);
	sorter.print();
	sorter.bubblesort_ascending();
	sorter.print();
	sorter.bubblesort_descending();
	sorter.print();
	return 0;
}