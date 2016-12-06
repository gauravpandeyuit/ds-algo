#include <iostream>
#include <vector>
using namespace std;

class ArrIns{
	private:
		vector<double> arrIns;
		int count;
	public:
		ArrIns(int maxSize):count(0)
		{
			arrIns.resize(maxSize);
		}

		void insert(double dd)
		{
			arrIns[count++]=dd;
		}
		
		void display()
		{
			cout << "Our array is: " << endl;
			for(int i=0;i<count;i++)
			{
				cout << arrIns[i] << " ";
			}
			cout << endl;
		}

		void insertionSort()
		{
			cout << "Now sorting our array using insertion sort algo " << endl;
			for(int i=1;i<count;i++)
			{
				double curr = arrIns[i];
				int j=i;
				while(arrIns[j-1]>curr && j>0) 
				{
					arrIns[j]=arrIns[j-1];
					j--;
				}
				arrIns[j]=curr;
			}
		}

};

int main()
{
	ArrIns arr(6);

	arr.insert(12);		
	arr.insert(99);		
	arr.insert(76);		
	arr.insert(88);		
	arr.insert(24);		
	arr.insert(17);		

	arr.display();

	arr.insertionSort();
	arr.display();
	
	return 0;
}
