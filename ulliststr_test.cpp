/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
	ULListStr list;
	cout << "Test" << endl;
	cout << "----------------" << endl;
	cout << "current size: " << list.size() << endl;
	list.push_back("2");
	cout << "current size: " << list.size() << endl;
	list.push_back("3");
	cout << "current size: " << list.size() << endl;
	cout << "current contents: ";
	for (unsigned int i = 0; i < list.size(); i++){
		cout << list.get(i) << ' ';
	}
	cout << endl;
	//adding 8 more 
	list.push_back("5");
	list.push_back("10");
	list.push_back("12");
	list.push_back("15");
	list.push_back("41");
	list.push_back("52");
	list.push_back("194");
	list.push_back("201");
	cout << "8 more: ";
	for (unsigned int i = 0; i < list.size(); i++){
		cout << list.get(i) << ' ';
	}
	cout << endl;
	//full list, need more space
	list.push_back("32");
	cout << "after pushing to a full list: ";
	for (unsigned int i = 0; i < list.size(); i++){
		cout << list.get(i) << ' ';
	}
	cout << endl;

	for (int i = 0; i < 5; i++){
		list.pop_front();
	}
	cout << "after pop_front 5 times: ";
	for (unsigned int i = 0; i < list.size(); i++){
		cout << list.get(i) << ' ';
	}
	cout << endl;
	cout << "[list cleared]" << endl;
	list.clear();
	list.pop_back();
	list.pop_front();
	cout << "pop_front and pop_back on empty: ";
	for (unsigned int i = 0; i < list.size(); i++){
		cout << list.get(i) << ' ';
	}
	cout << endl;
	list.push_front("4");
	cout << "push front once: ";
	for (unsigned int i = 0; i < list.size(); i++){
		cout << list.get(i) << ' ';
	}
	cout << endl;
	cout << endl;
	cout << "current size: " << list.size() << endl;
	list.push_front("10");
	list.push_front("654");
	list.push_front("12");
	list.push_front("54");
	list.push_front("53");
	list.push_front("41");
	list.push_front("14");
	list.push_front("30");
	list.push_front("124");
	cout << "updated contents: ";
	for (unsigned int i = 0; i < list.size(); i++){
		cout << list.get(i) << ' ';
	}
	cout << endl;
	cout << "after popping: ";
	for (int i = 0; i < 3; i++){
		list.pop_front();
	}
	list.pop_back();
	for (unsigned int i = 0; i < list.size(); i++){
		cout << list.get(i) << ' ';
	}
	cout << endl;
	cout << "final size: " << list.size() << endl;
	cout << "back method: ";
	cout << list.back() << endl;
	cout << "front method: ";
	cout << list.front() << endl;


	


	




  return 0;
}
