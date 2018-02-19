#include<iostream>
#include<vector>
using namespace std;



class NodeType{ //taken from(Gaouthami, 2012)<http://www.dailyfreecode.com/code/two-matrix-178.aspx > 

public:


	int column, value;
	
	NodeType* next;
	NodeType* prevlink; 

	NodeType(int column1, int value1)
	{
		column=column1;
		value=value1;
		next= NULL;
		prevlink=NULL;
	}

};



class LinkedList{   // taken from (cplusplus.com, 2000-2015)<http://www.cplusplus.com/forum/general/74377/ >
public:

	
	NodeType * head;

	LinkedList(){

		this->head=NULL;

	}

	int size;

	void displayColumn(int size); 
	void insertItemAt(int column, int value2){ //(Gunawardena, A., 2009)<https://www.cs.cmu.edu/~ab/15-123S09/lectures/Lecture%2011%20%20-%20%20Array%20of%20Linked%20Lists.pdf >

		NodeType* newNode = new NodeType(column,value2);

			if (head == NULL){ 
				head = newNode;
	  }
			else{
			NodeType *temp = head;
			while (temp != NULL){
				if (temp->column == newNode->column){
					temp->value = newNode->value;
					
					break;
				}
				else if (newNode->column < temp->column){
					if (temp->prevlink != NULL){
						temp->prevlink->next=newNode;
						newNode->prevlink = temp->prevlink;
						temp->prevlink = newNode;
						newNode->next = temp;
					}
					else{
						newNode->next = temp;
						temp->prevlink = newNode;
						head = newNode;
						newNode->prevlink = NULL;
					}
					break;
				}
				else if (temp->next == NULL){
					temp->next = newNode;
					newNode->prevlink = temp;
					break;
				}
				temp = temp->next;
			}
		} 
	}
};

class SM{
	
	int n, m; 
	
	
	vector<LinkedList*>Link;

public:

	SM(int rows, int columns){
		this->n=rows;
		this->m=columns;

		for (int x=0; x<rows; x++){
			Link.push_back(new LinkedList());
	}
	}

	void readElement(){   //(it&c company, 2011)<http://www.itcsolutions.eu/2009/11/02/how-to-implement-sparse-matrix-data-structure-in-the-c-programming-language/>
	
		cout <<"\n now enter the non zero elements "<<"one by one\n  "<<endl;
		cout<<"\nEnter row number,column number,data\n";
        cout<<"Enter (0 0 0) to stop ::";
		int row_index, column_index, value;

		while (true){
			cin >> row_index >> column_index >> value;
			if (value != 0){
				Link.at(row_index)->insertItemAt(column_index,value);
 cout<<"\nEnter row number,column number,data\n";
 cout<<"Enter (0 0 0) to stop ::\n";		
			}
			else{
				cout<<" ";
				break;
			}
		}
	}

	
	void printMatrix(){

		for (int x = 0; x < n; x++){
			printvalues(x);
			cout << "\n\n";
		
		}
	}

	~SM(){
		cout << "" << endl;
		
		NodeType *temp;
		for (int x = 0; x < n; x++){
			temp = Link.at(x)->head;
			while (temp != NULL){
				if (temp->prevlink != NULL){
					free(temp->prevlink);
				}
					
				if (temp->next == NULL){
					free(temp);
					break;
				}
				temp = temp->next;
			}
		}

	}
		
		void addSM(SM &other){   //(Sanfoundry Global Education & Learning Series – 1000 C++ Programs., 2010)<http://www.sanfoundry.com/cpp-program-implement-sparse-matrix/>
		NodeType *tempB, *tempA;
		for (int x = 0; x < n; x++){

			tempB = Link.at(x)->head;
			tempA = other.Link.at(x)->head;
			while (tempB != NULL){

				while (tempA != NULL && tempA->column < tempB->column){
					Link.at(x)->insertItemAt(tempA->column, tempA->value);
					tempA = tempA->next;
				}
				if (tempA != NULL && tempA->column == tempB->column){
					tempB->value += tempA->value; 
					tempA = tempA->next;
				}
				if (tempA == NULL)break;


				tempB = tempB->next;
				
			}
			while (tempA != NULL){
				Link.at(x)->insertItemAt(tempA->column, tempA->value);
				tempA = tempA->next;
			}
		}
	}
private:
	void printvalues(int print){
		NodeType *temp = Link.at(print)->head;
		int presence, start = 0;
		while (temp != NULL){
			presence = temp->column;
			for (int a = start; a < presence; a++){
				cout << "0\t";
			}
			cout << temp->value << "\t";
			start = presence + 1;
			temp = temp->next;
		}
		for (int a = start; a < m; a++){
			cout << "0\t";
		}
	}


};


int main(){
	
	int choice = 0;	int row;
	int column;

 cout<<"******************************************";
 cout<<"\nThis program is to perform addition of \n";
 cout<<" two sparse matrices \n";
 cout<<"*******************************************\n";

	cout << "\nEnter the no. of rows :: ";
	cin >> row;
	cout << "Enter the no. of columns ::";
	cin >> column;

	SM *matrix_A = new SM(row,column);
	SM *matrix_B = new SM(row, column);

 cout<<"\n****************************************\n";
 cout<<"Enter the values for sparse matrix A ::\n";
 cout<<"****************************************\n";
 matrix_A->readElement();

 cout<<"****************************************\n";
 cout<<"Enter the values for sparse matrix B ::\n";
 cout<<"****************************************\n";
 matrix_B->readElement();

	
	cout << "Values entered for Matrix A::\n";
	matrix_A->printMatrix();

	cout << "Values entered for Matrix B::\n";
	matrix_B->printMatrix();

	
	matrix_A->addSM(*matrix_B);

	cout << "\nMatrix A+B: \n";
	matrix_A->printMatrix();
	system ("pause");
	return 0;


}
