#include <iostream>
#include <vector>
using namespace std;

class StackX{
	
private:
	int maxSize;
	vector<int> stackVect;
	int count;

public:
	StackX(int size):maxSize(maxSize),count(0)
	{
		stackVect.resize(size);
	}

	void push(int di)
	{
		cout << "Push : " << di << endl;
		stackVect[count++]=di;
	}
	
	int pop()
	{
		cout << "Pop" << endl;
		return stackVect[--count];
	}

	int peek()
	{
		return stackVect[count];
	}

	bool isEmpty()
	{
		return count==0;
	}	

};

int main()
{
	/*StackX theStack(10);
	theStack.push(10);
	theStack.push(11);
	theStack.push(12);
	theStack.push(13);
	theStack.push(14);
	
	cout << "Peek : " << theStack.peek() << endl;

	theStack.pop();
	theStack.pop();

	cout << "Peek : " << theStack.peek() << endl;*/

	int theNumber;
	int theAnswer;
	int stackTriangle(int);
	cout << "Please enter a number" << endl;
	cin >> theNumber;

	theAnswer = stackTriangle(theNumber);
	cout << "The answer is : " << theAnswer << endl;


	return 0;
}

int stackTriangle(int i)
{
	StackX theStack(10000);
	int answer = 0;

	while(i>0)
	{
		theStack.push(i--);
	}
	while(!theStack.isEmpty())
	{
		int temp = theStack.pop();
		cout << "temp : " << temp << endl;
		answer += temp;
	}
	return answer;
}

int stackTriangle1(int i)
{
	if(i==1)
		return i;
	else return  i+stackTriangle(i-1);
}



