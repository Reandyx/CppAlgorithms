#include <iostream>
using std::cout;

int exponentMod(int A, int B, int C)
{
	if (A == 0)
		return 0;
	if (B == 0)
		return 1;

	long y;
	if (B % 2 == 0) {
		y = exponentMod(A, B / 2, C);
		y = (y * y) % C;
	}

	else {
		y = A % C;
		y = (y * exponentMod(A, B - 1, C) % C) % C;
	}

	return (int)((y + C) % C);
}

int main()
{
	int A = 2, B = 5, C = 13;
	cout << "Power is " << exponentMod(A, B, C);
	return 0;
}

