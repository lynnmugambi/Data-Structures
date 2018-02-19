#include <iostream>
#include <string>
using namespace std;


template <class T>
class NodeType {
public:
	T info;
	NodeType<T>* link;
};


template <class T>
class SM {
	int n, m;
	NodeType<T>* rPtr;
	NodeType<T>* head;
	int colIndex, rowIndex;

public:
	SM(int rows, int columns){
		this->head = NULL;
		this->n = rows;
		this->m = columns;
	}

	~SM(){
		~SM(head);
	}
	~SM(NodeType <T>* node){
		cout << "Going to delete all elements of the matrix." << endl;
		NodeType<T> * current;
		NodeType<T> * nextRow;

		if (node == head){
			current = current->link;
		}
		while (node != NULL){
			current = node;
			if (current->rPtr != NULL){
				nextRow = current->rPtr;
			}
			NodeType<T> * tobedeleted = current;
			current = tobedeleted->link;
			delete tobedeleted;
			node = current;
		}
		~SM(nextRow);
		delete head;
	}

	void readElments(){}
	void printMatrix(){}
	SM *addSM(SM & other){}
};

int main(){

	int rows, columns;

	cout << "\nEnter the no. of rows :: ";
	cin >> rows;
	cout << "Enter the no. of columns ::";
	cin >> columns;

	SM *matrix_A = new SM(rows, columns);

	system("pause");
	return 0;

}