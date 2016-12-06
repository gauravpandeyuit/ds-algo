#include <iostream>
#include <vector>
using namespace std;

class ArrSel{
	private:
		vector<double> arrSel;
		int count;

	public:
		ArrSel(int maxSize):count(0)
		{
			arrSel.resize(maxSize);
		}

		void insert(double dd)
		{
			arrSel[count++]=dd;
		}

		void display()
		{
			cout << "Our array is : " << endl;
			for(int i=0;i<count;i++)
			{
				cout << arrSel[i] << " ";
			}
			cout << endl;
		}

		void selectionSort()
		{
			cout << "Now sorting our array with selection sort algorigthm  " << endl;
			for(int i=0;i<count;i++)
			{
				int min = i;
				for(int j=i+1;j<count;j++)
				{
					if(arrSel[j]<arrSel[min])
						min = j;
				}
				if(min!=i)
				{
					double temp = arrSel[i];
					arrSel[i] = arrSel[min];
					arrSel[min]=temp;
				}
			}
		}
};

int main()
{
	ArrSel arr(6);
	arr.insert(23);
	arr.insert(29);
	arr.insert(93);
	arr.insert(13);
	arr.insert(83);
	arr.insert(73);
		
	arr.display();

	arr.selectionSort();
	arr.display();

	return 0;
}
