#include <iostream>
using namespace std;

class Link{
	public:
		int iData;
		double dData;
		Link* pNext;

		Link(int id, double dd):iData(id),dData(dd),pNext(NULL)
		{
			
		}

		void displayLink()
		{
			cout << iData << " ";
		}
};

class LinkedList
{
	private:
		Link* pFirst;
	
	public:
		LinkedList():pFirst(NULL)
		{
			
		}

		void insertFirst(int id, double dd)
		{
			Link* pNewLink = new Link(id,dd);
			pNewLink->pNext = pFirst;
			pFirst = pNewLink;
		}

		void deleteFirst()
		{
			Link* pTemp = pFirst;
			pFirst = pFirst->pNext;
			delete pFirst;
		}
		
		void display()
		{
			cout << "The list first ---> last " << endl;
			Link* pCurrent = pFirst;
			while(pCurrent!=NULL)
			{
				pCurrent->displayLink();
				pCurrent = pCurrent->pNext;
			}
			cout << endl;
		}

		Link* find(int key)
		{
			Link* pCurrent = pFirst;
			while(pCurrent->iData != key)
			{
				if(pCurrent->pNext==NULL)
					return NULL;
				else
					pCurrent = pCurrent->pNext;
			}
			return pCurrent;
		}
		
		bool remove(int key)
		{
			Link* pCurrent = pFirst;
			Link* pPrevious = NULL;
			while(pCurrent->iData != key)
			{
				if(pCurrent->pNext==NULL)
					return false;
				else
				{
					pPrevious = pCurrent;
					pCurrent = pCurrent->pNext;
				}
			}
			if(pCurrent == pFirst)
				pFirst = pFirst->pNext;
			else
				pPrevious->pNext = pCurrent->pNext;
			delete pCurrent;
			return true;
		}
};

int main()
{
	LinkedList theList;
	theList.insertFirst(1,1.1);
	theList.insertFirst(2,2.2);
	theList.insertFirst(3,3.2);
	theList.insertFirst(4,4.2);
	theList.insertFirst(5,5.2);
	
	theList.display();

	theList.remove(3);
	theList.display();

	Link* linkFound = theList.find(2);
	if(linkFound!=NULL)
	{
		linkFound->displayLink();
		cout << endl;
	}
	else	
	{
		cout << "Not found" << endl;
	}

	return 0;
}
