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
		
		void insertLast(int id)
		{
			Link* pNewLink = new Link(id);
			if(isEmpty())
				pFirst = pNewLink;
			else
				pLast->pNext = pNewLink;
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
			while(pCurrent!=NULL)
			{
				pCurrent->displayLink();
				pCurrent = pCurrent->pNext;
			}
			cout << endl;
		}
};

class LinkQueue
{

	private:
		FirstLastList list;

	public:
		
		bool isEmpty()
		{
			return list.isEmpty();
		}
		
		void insert(int id)
		{
			list.insertLast(id);
		}
	
		int remove()
		{
			return list.removeFirst();
		}
		
		void displayQueue()
		{
			cout << "Our queue is :" << endl;
			list.displayList();
			cout << endl;
		}

};



int main()
{
	LinkQueue theQueue;
	theQueue.insert(10);
	theQueue.insert(12);
	theQueue.insert(14);
	theQueue.insert(15);
	theQueue.insert(17);

	theQueue.displayQueue();

	theQueue.remove();	
	theQueue.remove();	

	theQueue.displayQueue();
	

	theQueue.insert(100);
	theQueue.insert(99);

	theQueue.displayQueue();
	return 0;
}
