using namespace std;
#include <iostream>
#include "split.h"

/* void push_back(Node*& Head, int i){
	if (!Head){
		Head = new Node(i, nullptr);  //needs dealloc
		return;
	}
	else{
	    push_back(Head->next, i); //valgrind
	}
} */ 

void print_list(Node*& Head){
	if (!Head){
		return;
	}
	cout << Head->value;
	cout << "->";
	print_list(Head->next);

}



int main(int argc, char** argv){
	Node* in4 = new Node(5, nullptr);
	Node* in3 = new Node(4, in4);
	Node* in2 = new Node(3, in3);
	Node* in1 = new Node(2, in2);
	Node* in = new Node(1, in1);
	Node* evens = nullptr;
	Node* odds = nullptr;
	/* push_back(in, 1);   //valgrind
	push_back(in, 2);
	push_back(in, 3);
	push_back(in, 4);
	push_back(in, 5); */


	cout << "input: ";
	print_list(in);
	cout << "nullptr";
	split(*&in, *&odds, *&evens);
	cout << endl;
	cout << "odds: ";
	print_list(odds);
		cout << "nullptr";
	cout << endl;
	cout << "evens: ";
	print_list(evens);
		cout << "nullptr";
	
	while(odds->next){
		Node* tmpnode = odds;
		odds = odds->next;
		delete tmpnode;
	}
	delete odds;

	while(evens->next){
		Node* tmpnode = evens;
		evens = evens->next;
		delete tmpnode;
	}
	delete evens;
	
	
	
	



	
	return 0;
}

