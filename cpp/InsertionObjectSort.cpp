#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person{
	private:
		string firstName;
		string lastName;
		int age;

	public:
		Person(string fName,string lName, int age):firstName(fName),lastName(lName),age(age)
		{
		
		}
		
		void displayPerson()
		{
			cout << "First name : " << firstName;
			cout << ", Last name : " << lastName;
			cout << ", Age : " << age << endl;
		}
		
		int getAge()
		{
			return age;
		}
};

class ArrayInOb
{
	private:
		vector<Person*> v;
		int count;
	public:
		ArrayInOb(int maxSize):count(0)
		{
			v.resize(maxSize);
		}

		void insert(string firstName, string lastName, int age)
		{
			v[count++] = new Person(firstName,lastName,age);
		}
	
		void display()
		{
			for(int i=0;i<count;i++)
			{
				v[i]->displayPerson();
			}
		}

		void insertionSort()
		{
			for(int i=1;i<count;i++)
			{
				Person* curr = v[i];
				int j = i;
				while(j > 0 && v[j-1]->getAge() > curr->getAge())
				{
					v[j] = v[j-1];
					j--;
				}
				v[j]=curr;
			}
		}
};

int main()
{
	ArrayInOb theArray(5);
	theArray.insert("Gaurav","Pandey",33);
	theArray.insert("Atal","Bihari",88);
	theArray.insert("Rahul","G",13);
	theArray.insert("Singh","Sahab",99);
	theArray.insert("Tara","Singh",21);

	theArray.display();

	cout << "Sorting the object array through insertion sort algo : " << endl;
	
	theArray.insertionSort();
	theArray.display();
	
	return 0;
}






