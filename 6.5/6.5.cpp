#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

typedef string Info;
struct Elem
{
	Elem* link;
	Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
Info dequeue(Elem*& first, Elem*& last);
void readTXT(Elem*& first, Elem*& last, Elem*& first1, Elem*& last1);
void print(Elem* L);

int main()
{
	Elem* first = NULL,
		* last = NULL;
	Elem* first1 = NULL,
		* last1 = NULL;


	readTXT(first, last, first1, last1);

	cout << endl << "enqueue 0:" << endl;
	print(first);
	cout << endl << "enqueue 1:" << endl;
	print(first1);
	
	cout <<endl << "first 1 : " << first->link << " last : "<< last->link;
	cout << endl << "first 1 : " << first1->link << " last : " << last1->link;
	return 0;
}

void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->link = NULL; // 3
	if (last != NULL)
		last->link = tmp; // 4
	last = tmp; // 5
	if (first == NULL)
		first = tmp; // 6
}

Info dequeue(Elem * &first, Elem * &last)
{
	Elem* tmp = first->link; // 1
	Info value = first->info; // 2
	delete first; // 3
	first = tmp; // 4
	if (first == NULL)
		last = NULL; // 5
	return value; // 6
}

void readTXT(Elem*& first, Elem*& last, Elem*& first1, Elem*& last1)
{
	ifstream f("symbols.txt"); 
	string symbol, ss; 
	int tmp = 0;
	
	while (getline(f, symbol))
	{
		tmp = stoi(symbol);
		istringstream iss(symbol);
		if (tmp % 2 == 0) {
			while (iss >> ss) {
				enqueue(first, last, ss);
			}
		}
		else
		{
			while (iss >> ss) {
				enqueue(first1, last1, ss);
			}
		}
	}
}

void print(Elem* L)
{
	while (L != NULL)
	{
		cout << L->info << " ";
		L = L->link;
	}
	cout << endl;
}
