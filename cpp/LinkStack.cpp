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

class LinkedList
{
	private:
		Link* pFirst;
	public:
		LinkedList():pFirst(NULL)
		{
			
		}

		~LinkedList()
		{
			Link* pCurrent = pFirst;
			while(pCurrent!=NULL)
			{
				Link* pTemp = pCurrent;
				pCurrent = pCurrent->pNext;
				delete pTemp;
			}
		}
		
		bool isEmpty()
		{
			return pFirst == NULL;
		}		

		void insertFirst(int id)
		{	
			Link* pNewLink = new Link(id);
			pNewLink->pNext = pFirst;
			pFirst = pNewLink;
		}

		int deleteFirst()
		{
			Link* pTemp = pFirst;
			pFirst = pFirst->pNext;
			int ret = pTemp->iData;
			delete pTemp;
			return ret;
		}

		void displayList()
		{
			Link* pCurrent = pFirst;
			while(pCurrent!=NULL)
			{
				pCurrent->displayLink();
				pCurrent = pCurrent->pNext;
			}
			cout << endl;
		}
};

class LinkStack{
	
	public:
		LinkedList* pList;
	
		LinkStack()
		{
			pList = new LinkedList();
		}

		~LinkStack()
		{
			delete pList;
		}
	
		void push(int id)
		{
			pList->insertFirst(id);
		}

		int pop()
		{
			return pList->deleteFirst();
		}

		bool isEmpty()
		{
			return pList->isEmpty();
		}

		void displayStack()
		{
			cout << "Stack top ----> bottom : " << endl;
			pList->displayList();
		}
};

int main()
{
	
	LinkStack theStack;
	theStack.push(40);
	theStack.push(20);
	theStack.push(50);
	theStack.push(70);

	theStack.displayStack();

	cout << "pop - " << theStack.pop() << endl;
	cout << "pop - " << theStack.pop() << endl;

	theStack.displayStack();
	return 0;
}
