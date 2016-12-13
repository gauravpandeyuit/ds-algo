#include <iostream>
using namespace std;

class Link{
	public:
		int iData;
		Link* pNext;

	Link(int id):iData(id),pNext(NULL)
	{

	}

	void displayLink()
	{
		cout << iData << " ";
	}
};

class SortedList{
	private:
		Link* pFirst;

	public:
		SortedList():pFirst(NULL)
		{
			
		}

		void insert(int key)
		{
			Link* pNewLink = new Link(key);
			Link* pCurrent = pFirst;
			Link* pPrevious = NULL;
			while(pCurrent!=NULL && pCurrent->iData < key)
			{
				pPrevious = pCurrent;
				pCurrent = pCurrent->pNext;
			}
			if(pPrevious==NULL)
			{
				pFirst = pNewLink;
			}
			else
			{
				pPrevious->pNext = pNewLink;
			}

			pNewLink->pNext = pCurrent;
		}

		void displayList()
		{
			Link* pCurrent = pFirst;
			cout << "Link first--->last "<< endl;
			while(pCurrent!=NULL)
			{
				pCurrent->displayLink();
				pCurrent = pCurrent->pNext;
			}
			cout << endl;
		}

};

int main()
{
	SortedList theList;
	theList.insert(10);	
	theList.insert(90);	
	theList.insert(20);	
	theList.insert(70);	
	theList.insert(80);	
	theList.insert(50);	
	theList.insert(60);	
	theList.insert(99);	
	theList.insert(9);
	theList.displayList();
	return 0;
}
