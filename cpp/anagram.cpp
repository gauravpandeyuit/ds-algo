//anagram.cpp
//creates anagrams
#include <iostream>
#include <string>
using namespace std;

class word
{
private:
	int size;
	int count;
	string workStr;
	void rotate(int);
	void displayWord();
	int cnt=0;

public:
	word(string);
	void anagram(int);
};

word::word(string inpStr):workStr(inpStr),count(0)
{
	size = inpStr.length();
}

void word::anagram(int newSize)
{
cout << ++cnt << endl;
	if(newSize==1)
		return;

	for(int j=0;j<newSize;j++)
	{
		anagram(newSize-1);
		if(newSize == 2)
			displayWord();

		rotate(newSize);
	}
}

//rotate left all chars from position to end
void word::rotate(int newSize)
{
	int j;
	int position = size - newSize;
	char temp = workStr[position];//save first letter
	for(j=position+1;j<size;j++)
	{
		workStr[j-1] = workStr[j];
	}
	workStr[j-1]=temp;
}

void word::displayWord()
{
	if(count < 99)
		cout << " ";
	if(count < 9)
		cout << " ";
//	cout << ++count << " ";
	cout << workStr << "  ";
	if(count%6==0)
		cout << endl;
}

int main()
{
	string input;
	int length;
	
	cout << "Eneter a word: ";
	cin >> input;
	length = input.length();
	
	word  theWord(input);
	theWord.anagram(length);
	
	return 0;
}


