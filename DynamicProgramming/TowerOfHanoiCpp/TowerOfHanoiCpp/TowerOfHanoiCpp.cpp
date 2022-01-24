#include <iostream>
using std::cout;
using std::endl;

void TowerOfHanoi(int N)
{
	// Iterate over the range <0, 2^N - 1>
	for (int x = 1;
		x <= pow(2, N) - 1; x++) {
		cout << "Move from Rod " << ((x & x - 1) % 3 + 1) << " to Rod " << (((x | x - 1) + 1) % 3 + 1) << endl;
	}
}

int main()
{
	int N = 3;
	TowerOfHanoi(N);
	return 0;
}
