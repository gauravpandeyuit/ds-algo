#include <iostream>
using namespace std;

void doTowers(int,char,char,char);

int main()
{
	int nDisks;
	cout << "Enter the number of disks :" << endl;
	cin >> nDisks;
	
	doTowers(nDisks,'A','B','C');

	return 0;
}

void doTowers(int topN, char src, char inter, char dest)
{
//	cout << "Enter (" << topN << " disks): s=" << src << " i=" << inter << " d=" << dest << endl;
	if(topN == 1)
		cout << "Base case: Disk 1 from " << src << " to " << dest << endl;
	else
	{
		doTowers(topN-1,src, dest,inter);//transfer n-1 disks from src to inter
		//transfer nth disk from src to dest
		cout << "Disk " << topN << " from " << src << " to " << dest << endl;
		doTowers(topN-1,inter,src,dest);//transfer n-1 disks from inter to dest
	}
}
