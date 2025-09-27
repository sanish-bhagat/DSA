#include <iostream>
#include <map>
using namespace std;

//TC is O(n logn)
//SC is O(logn)

class Node
{
public:
    int data;
    Node* next;
    Node* child;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node() {
        int value = this-> data;

        if(this-> next != NULL) {
            //memory is free
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for " << value << endl;
    }
};

void insertAtHead(Node* &head, int data) {

    //create a new node
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail,int data) {

    //create a new node
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << " List is empty" << endl;
        return;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* merge(Node* down, Node* right) {
	if(down == NULL)
		return right;

	if(right == NULL)
		return down;

	Node* ans = new Node(-1);
	Node* temp = ans;

	while(down != NULL && right != NULL) {
		if(down -> data < right -> data) {
			temp -> child = down;
			temp = down;
			down = down -> child;
		}
		else {
			temp -> child = right;
			temp = right;
			right = right -> child;
		}
	}

	while(down != NULL) {
		temp -> child = down;
		temp = down;
		down = down -> child;
	}

	while(right != NULL) {
		temp -> child = right;
		temp = right;
		right = right -> child;
	}
	ans = ans -> child;

	return ans;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head -> next == NULL)
		return head;

	Node* down = head;

	Node* right = flattenLinkedList(head -> next);
	down -> next = NULL;

	return merge(down, right);
}
    
int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtTail(tail,13);
    insertAtTail(tail,14);
    insertAtTail(tail,15);

    print(head);

}