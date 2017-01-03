#include <iostream>
#include <vector>
using namespace std;

class BSArray{

private:
	vector<int> arr;
	int count;

public:
	BSArray(int maxSize):count(0)
	{
		arr.resize(maxSize);
	}

	void insert(int elem)
	{
		int i=0;
		for(i=0;i<count;i++)
		{
			if(arr[i]>elem)
				break;		
		}
		for(int j=count;j>i;j--)
		{
			arr[j] = arr[j-1];
		}
		arr[i]=elem;
		count++;
	}

	void display()
	{
		for(int i=0;i<count;i++)
		{
			cout << arr[i] << endl;
		}
	}

	bool find(int key)
	{
		return BinarySearch(key,0,count-1);
	}

	bool BinarySearch(int key,int from,int to)
	{
		int avg = (from+to)/2;
	
		cout << "Debug log: " << from << " -- "<< avg << " -- " << to << endl;
	
		if(arr[avg]==key)
			return true;
		else if(from>to)
			return false;
		else if(key > arr[avg])
			from = avg+1;
		else
			to = avg-1;
		
		return BinarySearch(key,from,to);
	}

};

int main()
{
	BSArray theArr(100);

	theArr.insert(10);
	theArr.insert(1);
	theArr.insert(11);
	theArr.insert(24);
	theArr.insert(67);
	theArr.insert(13);
	theArr.insert(99);
	theArr.insert(89);
	theArr.insert(79);

	theArr.display();

	cout << "Enter a search key" << endl;
	int key;
	cin >> key;

	bool f = theArr.find(key);
	if(f)
		cout << "Found!!!" << endl;
	else 
		cout << "Not found :(" << endl;
	
	return 0;
}


