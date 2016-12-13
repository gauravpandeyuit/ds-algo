#include <iostream>
#include <vector>
using namespace std;

class Link{

public:
	double dData;
	Link* pNext;

	Link(double dd):dData(dd)
	{

	}

	void displayLink()
	{
		cout << dData << " ";
	}
};

class SortedList
{
private:
	Link* pFirst;
public:
	SortedList(Link** lnkArray, int size):pFirst(NULL)
	{
		for(int i=0;i<size;i++)
		{
			insert(lnkArray[i]);
		}
	}

	void insert(Link* newLink)
	{
		Link* pCurrent = pFirst;
		Link* pPrevious = NULL;

		while(pCurrent!=NULL && pCurrent->dData < newLink->dData)
		{
			pPrevious = pCurrent;
			pCurrent=pCurrent->pNext;
		}

		if(pPrevious==NULL)
		{
			pFirst = newLink;
		}
		else
		{
			pPrevious->pNext = newLink;
		}
		newLink->pNext = pCurrent;
	}

	void displayList()
	{
		Link* pCurrent = pFirst;
		cout << "List first ---> last" << endl;
		while(pCurrent!=NULL)
		{
			pCurrent->displayLink();
			pCurrent = pCurrent->pNext;
		}
		cout << endl;
	}

	Link* remove()
	{
		Link* pTemp = pFirst;
		pFirst = pFirst -> pNext;
		return pTemp;
	}

};

int main()
{
	const int size = 6;
	Link* lnkArray[size];
	for(int i=0;i<size;i++)
	{
		if(i%2==0)
		{
			lnkArray[i]=new Link(i+1);
		}
		else lnkArray[i]=new Link(i*4);
	}

	cout << "Our array is " << endl;
	for(int i=0;i<size;i++)
	{
		cout << lnkArray[i]->dData << " ";
	}
	cout << endl;

	cout << "sorting array now " << endl;

	SortedList theList(lnkArray,size);

	for(int i=0;i<size;i++)
	{
		lnkArray[i] = theList.remove();
	}

	cout << "Our array is " << endl;
	for(int i=0;i<size;i++)
	{
		cout << lnkArray[i]->dData << " ";
	}
	cout << endl;
	
	for(int i=0;i<size;i++)
	{
		delete lnkArray[i];
	}


}