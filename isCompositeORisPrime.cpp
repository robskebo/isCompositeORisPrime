// isCompisiteOrisPrime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// isCompositeORisPrime.cpp : Defines the entry point for the console application.

#include <iostream>

using namespace std;

int main()
{

	int n = 1, i = 0, c = 0;

	printf("Enter any number n:");
	//scanf("%d", &n);
	cin >> n;

	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			c++;
		}
	}
	if (c == 2)
	{
		cout << "n is a Prime number";
		cout << endl;
	}
	else {
			cout << "n is a Composite number";
			cout << endl;
		 }
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
