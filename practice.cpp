#include <iostream>
#include <string>
using namespace std;


template <class T>
class NodeType { 
 public: 
    T info; 
    NodeType<T> * link; 
};
template <class T>
class Stack{
 public: 
   T * list;
   NodeType<T> * head; //stack’s top is the first node of the list

   Stack() { //constructor
	   this->head = NULL;
   } 

   ~Stack() { //destructor
		cout << endl << "Going to delete all elements of the list." << endl;
        NodeType<T>* current = head;
		while (head != NULL)
		{
			current = current->link;
			delete head;
			head = current;
		}
//while(!isEmpty){
		//pop();}
   }

   void push(T elem){  //pushes elem to be the new top of the stack

	    NodeType<T>* newNode = new NodeType<T>;
		newNode->info = elem;
		newNode->link = head;
		head = newNode;

		//This is to handle the case where the linked list is empty at the beginning of insertion
		if (head== NULL)
			head = newNode;
   }

   T pop(){
	   if(head == NULL){
		   cout<<"Cant pop from empty stack"<<endl;
		   abort();
	   }
	   T temp = head -> info;
	   NodeType<T>* todelete = head;
	   head = head ->link;
	   delete todelete;
	   return temp;

   } //deletes the head node and returns its info


   T top(){

	   if(head == NULL){
		   cout<<"Cant pop from empty stack"<<endl;
		   abort();
	   }
		return head->info;

   } //returns stack’s top element, i.e. head’s info

   bool isEmpty(){ 
   return(head == NULL);
   } //true if stack is empty, false otherwise
};
void main(){
    Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.pop();
	cout << stack.top() << endl;
	system("pause");
}


class LinkedList {
public:
	NodeType* head;
	int size;

	LinkedList(){
		this->size = 0;
		this->head = NULL;
	}

	~LinkedList(){
		cout << "Going to delete all " << size << " elements of the list." << endl;
		NodeType * current = head;
		while (head != NULL){
			current = current->link;
			delete head;
			head = current;
		}
	}

	void insertAtBeginning(int value){
		NodeType * newNode = new NodeType;
		newNode->info = value;
		newNode->link = head;
		head = newNode;
		size++;
	}

	void insertAtEnd(int value){
		NodeType * newNode = new NodeType;
		newNode->info = value;
		newNode->link = NULL;
		if (head == NULL)
			head = newNode;
		else{
			NodeType * last = head;
			while (last->link != NULL)
				last = last->link;
			last->link = newNode;
		}
		size++;
	}

	int getSize(){
		return size;
	}

	void print(){
		NodeType * cur = head;
		while (cur != NULL){
			cout << cur->info << " ";
			cur = cur->link;
		}
	}

	void clear(){

		NodeType * current = head;
		while (head != NULL){
			current = current->link;
			delete head;
			head = current;
		}
		size = 0;
	}

	

	bool search(int value){
		NodeType* curr = head;
		while (curr != NULL)
		{
			if (curr->info == value)
				return true;
			else
				curr = curr->link;
		}

		return false;
	}

	int foundAt(int value){
		NodeType* curr = head;
		int i = 0;
		while (curr != NULL)
		{
			i++;
			if (curr->info == value)
				return i - 1;
			else
				curr = curr->link;
		}

		return -1;
	}

	int getItemAt(int index){
		if (index<0 || index >= size){
			cout << "Index out of bound.\n";
			abort();
		}
		NodeType * current = head;
		for (int i = 0; i<index; i++)
			current = current->link;
		return current->info;
	}

	void deleteFirst(){
		if (size > 0)
		{
			NodeType * toBeDeleted = head;
			head = head->link;
			delete toBeDeleted;
			size--;
		}
		else{
			cout << "List is currently empty.\n";
		}

	}

	void deleteLast(){
		if (size > 0){

			//list has only one item 
			if (size == 1){
				delete head;
				head = NULL;
			}
			else{
				NodeType * beforeLast = head;
				while (beforeLast->link->link != NULL)
					beforeLast = beforeLast->link;
				delete beforeLast->link;
				beforeLast->link = NULL;
			}
			size--;
		}
		else
		{
			cout << "List is currently empty.\n";
		}
	}

	void deleteItemAt(int index){
		if (index < size){//else, may want to give a message or error 
			if (index == 0)
				deleteFirst();
			else{
				NodeType * prev = NULL, *toDelete = head;
				for (int i = 0; i<index; i++){
					prev = toDelete;
					toDelete = toDelete->link;
				}
				prev->link = toDelete->link; //NULL also OK for last item
				delete toDelete;
				size--;
			}
		}
	}

	void insertItemAt(int value, int index){
		if (index <= size){//else, may want to give a message or error 
			if (index == 0)
				insertAtBeginning(value);
			else if (index == size)
				insertAtEnd(value);
			else {
				NodeType * newNode = new NodeType; newNode->info = value;
				NodeType * prev = head;
				for (int i = 0; i<index - 1; i++)
					prev = prev->link;
				newNode->link = prev->link;
				prev->link = newNode;
				size++;
			}
		}
	}


};




void main(){

	LinkedList list;
	list.insertAtBeginning(5);
	list.insertAtEnd(9);
	list.insertAtBeginning(3);
	cout << "the size is : " << list.getSize() << endl;
	list.print();
	cout << endl;

	list.insertAtEnd(11);
	cout << "the size is : " << list.getSize() << endl;
	list.print();
	cout << endl;

	int index = list.foundAt(9);
	cout << index << endl;

	LinkedList list2;

	list2.insertAtBeginning(3);
	cout << "the size is : " << list2.getSize() << endl;
	list2.print();
	cout << endl;


	system("pause");
};

void main(){
	LinkedList list;

	list.insertAtBeginning(1);
	list.insertAtEnd(2);
	list.insertAtBeginning(3);
	list.print();
	list.deleteFirst();
	list.print();
	list.deleteLast();
	list.print();
	list.clear();

	// Checkpoint 1 
	list.insertAtBeginning(5);
	list.insertAtEnd(7);
	list.insertAtEnd(8);
	list.insertAtBeginning(4);
	list.deleteItemAt(3);
	list.print();
	// Checkpoint 2 
	list.insertItemAt(6, 2);
	list.insertItemAt(3, 0);
	list.print();
	list.insertItemAt(9, list.getSize());
	list.insertItemAt(8, list.getSize() - 1);
	list.print();
} // End of Main.. Checkpoint 3

template <class T>
class TreeNode{
public:
	T data;
	TreeNode<T> * left;
	TreeNode<T> * right;

	TreeNode(T data){
		this->data = data;
		this->left = this->right = NULL;
	}

	TreeNode(){}
};

template <class T> 
class BinaryTree{
public:
	TreeNode<T> * root;
	void preOrder(){
		preOrder(root); //use helper function to start from root
	}
	void preOrder(TreeNode<T> * node){ //helper function
		if (node != NULL){
			cout << node->data << " "; //do the visit action
			preOrder(node->left);
			preOrder(node->right);
		}
	}

	void inOrder(){
		inOrder(root); //use helper function to start from root
	}
	void inOrder(TreeNode<T> * node){ //helper function
		if (node != NULL){
			inOrder(node->left);
			cout << node->data << " "; //do the visit action
			inOrder(node->right);
		}
	}

	void postOrder(){
		postOrder(root); //use helper function to start from root
	}
	void postOrder(TreeNode<T> * node){ //helper function
		if (node != NULL){
			postOrder(node->left);
			postOrder(node->right);
			cout << node->data << " "; //do the visit action
		}
	}

	void levelOrder(){
		levelOrder(root); //use helper function to start from root
	}
	void levelOrder(){
		Queue< TreeNode<T> * > q; //queue of pointers to tree nodes
		q.addQueue(root); //start from the root
		TreeNode<T> * node; //a pointer to the node to be visited
		while (!q.isEmpty()){ //repeat until the queue becomes empty
			node = q.deleteQueue(); //get the next node in queue
			cout << node->data << " "; //and do the visit action
			if (node->left != NULL) //queue children to be processed in turn
				q.addQueue(node->left);
			if (node->right != NULL)
				q.addQueue(node->right);
		}
	}

	TreeNode<T> * find(T & key){
		return find(key, root);
	}

	TreeNode<T> * find(T & key, TreeNode<T> * node){
		if (node == NULL)
			return NULL;
		if (key == node->data){
			//return node;
			cout << "value :" + node->data + " has been found at " + node << endl;
		}
		else{
			if (key == node < data)
				return find(key, node->left);
			else
				return find(key, node->right);
		}
	}
	/* or // USING WHILE LOOP
	NodeType <T> * cur = node;
	while (cur != NULL){
	if(cur -> data == key){
	return cur;
	//cout<< "value :" + node -> data + " has been found at " + node <<endl;
	else{
	if(cur -> data < key)
	return find(key, node->left);
	else
	return find(key, node -> right);
	}
	return NULL; */

};


void main(){


	TreeNode<int>*n1 = new TreeNode<int>(5);
	TreeNode<int>*n2 = new TreeNode<int>(7);
	TreeNode<int>*n3 = new TreeNode<int>(3);
	TreeNode<int>*n4 = new TreeNode<int>(9);
	TreeNode<int>*n5 = new TreeNode<int>(4);
	TreeNode<int>*n6 = new TreeNode<int>(6);
	TreeNode<int>*n7 = new TreeNode<int>(2);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n4->left = n7;

	BinaryTree<int> tree;
	tree.root = n1;
	tree.inOrder();


	system("pause");
}