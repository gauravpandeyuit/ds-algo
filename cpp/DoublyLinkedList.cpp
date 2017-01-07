#include <iostream>

using namespace std;

class Link{

public:
	double dData;
	Link* pNext;
	Link* pPrevious;

Link(double dd):dData(dd),pNext(NULL),pPrevious(NULL)
{}

void displayLink()
{
	cout << dData << " ";
}

};

class DoublyLinkedList{

private:
	Link* pFirst;
	Link* pLast;

public:
	DoublyLinkedList():pFirst(NULL),pLast(NULL)
	{

	}

	~DoublyLinkedList()
	{
		Link* pCurrent = pFirst;
		while(pCurrent!=NULL)
		{
			Link* pTemp = pCurrent;
			pCurrent=pCurrent->pNext;

			delete pTemp;
		}
	}

	bool isEmpty()
	{
		return pFirst == NULL;
	}

	void insertFirst(double dd)
	{
		cout << "inserting " << dd << " at first position " << endl;
		Link* pNewLink = new Link(dd);
		if(isEmpty())
		{
			pLast = pNewLink;
		}
		else
		{
			pFirst->pPrevious = pNewLink;
		}
		pNewLink->pNext = pFirst;
		pFirst = pNewLink;
	}

	void insertLast(double dd)
	{
		cout << "inserting " << dd << " at LAST position " << endl;
		Link* pNewLink = new Link(dd);
		if(isEmpty())
		{
			pFirst = pNewLink;
		}
		else
		{
			pLast->pNext = pNewLink;
		}
		pNewLink->pPrevious = pLast;
		pLast = pNewLink;
	}

	void removeFirst()
	{
		Link* pTemp = pFirst;
		if(pFirst->pNext == NULL)
		{
			pLast = NULL;
		}
		else
		{
			pFirst->pNext->pPrevious = NULL;
		}
		pFirst = pFirst->pNext;
		cout << "Removing " << pTemp->dData << " from first position" << endl;
		delete pTemp;
	}

	void removeLast()
	{
		Link* pTemp = pLast;
		if(pLast->pPrevious==NULL)
		{
			pFirst=NULL;
		}
		else
		{
			pLast->pPrevious->pNext = NULL;
		}
		pLast = pLast->pPrevious;
		cout << "Removing " << pTemp->dData << " from LAST position " << endl;
		delete pTemp;	
	}


	void displayForward()
	{
		cout << "Link first --> last  " << endl;
		Link* pCurrent = pFirst;
		while(pCurrent!=NULL)
		{
			pCurrent->displayLink();
			pCurrent=pCurrent->pNext;
		}
		cout << endl;
	}

	void displayBackward()
	{
		cout << "Link last --> first  " << endl;
		Link* pCurrent = pLast;
		while(pCurrent!=NULL)
		{
			pCurrent->displayLink();
			pCurrent=pCurrent->pPrevious;
		}
		cout << endl;
	}

};

int main()
{
	DoublyLinkedList dlist;
	dlist.insertFirst(10);
	dlist.insertFirst(20);
	dlist.insertFirst(30);

	dlist.displayForward();
	dlist.displayBackward();

	dlist.removeLast();

	dlist.displayForward();
	dlist.displayBackward();

	dlist.insertLast(40);
	dlist.insertLast(50);
	dlist.insertLast(60);

	dlist.displayForward();
	dlist.displayBackward();
	
	dlist.removeFirst();

	dlist.displayForward();
	dlist.displayBackward();
}



