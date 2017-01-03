#include <iostream>
#include <vector>
using namespace std;

class BS{

public:
	bool BinarySearch(int key,int from, int to)
	{
		
			int avg = (from+to)/2;
			//cout << endl << "Avg is : " << from << " -- " << avg << " -- " << to  << endl;
			if(from>to)
			{
				return false;
			}
			else if(key==avg && from)
			{
				return true;
			}
			else if(key > avg)
				from = avg+1;
			else
				to = avg-1;
			BinarySearch(key,from,to);
	}	
};

int main()
{
	int key;
	cout << "Enter a number" << endl;
	cin >> key;
	BS searcher;
	bool f = searcher.BinarySearch(key,1,100);
	if(f)
		cout << "Found!!!" << endl;
	else
		cout << "Not found :(" << endl;
	return 0;
}
