#include<iostream>
using std::cout;
using std::cin;

class GFG {

public:
	int fib(int n)
	{
		auto* f = new int[n + 2];
		int i;

		f[0] = 0;
		f[1] = 1;

		for (i = 2; i <= n; i++)
		{
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
		delete[] f;
	}
};

int main()
{
	GFG g;
	int n;
	cout << "give n parameter: ";
	cin >> n;
	cout << g.fib(n);
	return 0;
}