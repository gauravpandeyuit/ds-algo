#include <iostream>
using namespace std;

int main()
{
	int theNumber;
	int triangle(int);
	
	cout << "Enter a number " << endl;
	cin >> theNumber;
	cout << "Triangle = " << triangle(theNumber) << endl;
	return 0;
}

int triangle(int n)
{
	if(n==1)
		return 1;
	else
		 return (n+triangle(n-1));
}
