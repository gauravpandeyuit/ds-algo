#include <iostream>
using namespace std;

void merge(int[],int,int[],int,int[]);
void display(int[],int);

int main()
{
	int arrA[] = {2,3,14,15};
	int sizeA = 4;
	int arrB[] = {12,13,4,5,16,17};
	int sizeB = 6;
	int arrC[10];
	int sizeC = 10;

	merge(arrA,sizeA,arrB,sizeB,arrC);
	display(arrC,sizeC);

	return 0;
}

void merge(int arrA[],int sizeA,int arrB[],int sizeB,int arrC[])
{
	int cntA =0,cntB=0,cntC=0;
	while(cntA < sizeA && cntB < sizeB)
	{
		if(arrA[cntA] < arrB[cntB])
			arrC[cntC++] = arrA[cntA++];
		else
			arrC[cntC++] = arrB[cntB++];
	}
	while(cntA < sizeA)
	{
		arrC[cntC++] = arrA[cntA++];
	}
	while(cntB < sizeB)
	{
		arrC[cntC++] = arrB[cntB++];
	}
}

void display(int arr[],int size)
{
	cout << "Meged array is : " << endl;
	for(int i=0;i<size;i++)
	{
		cout <<  arr[i] << " ";
	}
	cout << endl;
}
