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

class FirstLastList{

	private:
		Link* pFirst;
		Link* pLast;

	public:
	FirstLastList():pFirst(NULL),pLast(NULL)
	{
		
	}

	bool isEmpty()
	{
		return pFirst == NULL;
	}

	void insertFirst(int id)
	{
		Link* pNewLink = new Link(id);
		if(isEmpty())
		{
			pLast = pNewLink;
		}
		else
		{
			pNewLink->pNext = pFirst;
		}
		pFirst = pNewLink;
	}

	void insertLast(int id)
	{
		Link* pNewLink = new Link(id);
		if(isEmpty())
		{
			pFirst = pNewLink;
		}
		else
		{
			pLast->pNext = pNewLink;
		}
		pLast = pNewLink;
	}

	int removeFirst()
	{
		Link* pTemp = pFirst;
		if(pFirst->pNext==NULL)
			pLast = NULL;
		pFirst = pFirst->pNext;
		int res = pTemp->iData;
		delete pTemp;
		return res;
	}
	
	void displayList()
	{
		Link* pCurrent = pFirst;
		cout << "List first ---> last " << endl;
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
	FirstLastList theList;
	theList.insertFirst(10);
	theList.insertFirst(20);
	theList.insertFirst(30);
	theList.insertFirst(50);
	theList.insertFirst(80);

	theList.insertLast(99);
	theList.insertLast(77);
	
	theList.displayList();

	return 0;
}
