#include <iostream>
#include <stack>

using namespace std;

class Node{
    int data; 
    Node* next;
public:
    Node(){};
    Node(int _data): data(_data), next(NULL){};
    void SetData(int aData) {data = aData;}
    void SetNext(Node* aNext){ next = aNext;}
    int GetData(){ return data;}
    Node* GetNext() {return next;}
};


class List{
    Node *head;
public:
    List() {head = NULL;}
    void Print();
    void Append(int _data);
    void Append(Node* _n);
    void Delete(int _data);
    void PrintReversely();
    void Delete(Node* _n);
};

void List::Print(){
    Node *tmp = head;
    if(tmp == NULL){
	cout<<" Empty List "<<endl;
	return;
    }
    
    while(tmp != NULL){
	cout<<tmp->GetData();
	cout<<" --> ";
	tmp = tmp->GetNext();	
    }
    cout<<" NULL "<<endl;
    
}

void List::Append(int _data){
    // create a new node
    Node* newNode = new Node();
    newNode->SetData(_data);
    newNode->SetNext(NULL);
    
    // create a copy of list head pointer
    Node* tmp = head; 
    
    if(tmp != NULL){
	// the list already has some nodes
	// keep on parse the tmp pointer to the end of the list
	while(tmp->GetNext() !=NULL){
	    tmp = tmp->GetNext();
	}

	// append the new node
	tmp->SetNext(newNode);
	
    }else{
	// new node will be the first node in the list
	head = newNode;
    }
}

void List::Append(Node* _n){
    if(!_n )
	return;
    Node *tmp = head; // a copy of list head ptr
    if(tmp != NULL){
	while(tmp->GetNext() != NULL){
	    tmp = tmp->GetNext();
	}
	
	//append the new Node to end of the list
	tmp->SetNext(_n);
    }else{
	// the list has no node yet
	head = _n;
    }
    
}

void List::Delete(int _data){ 
    // empty list
    if(head == NULL)
	return;
   
    Node* ToBeDeleted = NULL;
    if(head->GetData() == _data){
	ToBeDeleted = head;
    	head = head->GetNext();
    }else{
	// create a copy of list head pointer
	Node* ptr = head;
	while(ptr->GetNext() != NULL){
	    if(ptr->GetNext()->GetData() == _data ){
		// ptr --> [ptr.next] --> ...
		Node* tmp = ptr->GetNext()->GetNext();
		ToBeDeleted = ptr->GetNext();
		ptr->SetNext(tmp);
		break;
	    }else{
		ptr = ptr->GetNext();
	    }
	}	 
    }
    if(ToBeDeleted != NULL){
	delete ToBeDeleted;
	ToBeDeleted = NULL;
    }
}

// Question 5
void List::PrintReversely(){
    stack<Node*> nodes;
    Node* ptr = head;
    if(ptr==NULL){
	cout<<" Empty List"<<endl;
	return;
    }

    while(ptr!=NULL){
	nodes.push(ptr);
	ptr= ptr->GetNext();
    }
    cout<<"NULL ";
    while(!nodes.empty()){
	Node* tmp = nodes.top();
	cout<<" <-- ";
	cout<<tmp->GetData();
	nodes.pop();
    }
    cout<<endl;
}

void List::Delete(Node* _n){
    if(!head || !_n)
	return;
    //if _n is not the end node
    if(_n->GetNext() != NULL){
	Node* pNext = _n->GetNext();
	_n->SetData(pNext->GetData());
	_n->SetNext(pNext->GetNext());
	delete pNext; // free the memory pointed by pNext
	pNext = NULL; // pointed dangling ptr to NULL
    }
}

int main(){
    List mylist;
    mylist.Append(100);
    mylist.Print();
    mylist.Append(200);
    mylist.Print();
    
    mylist.Append(300);
    mylist.Print();
    mylist.Append(400);
    mylist.Print();
    mylist.PrintReversely();

    mylist.Delete(300);
    mylist.Print();
    mylist.Delete(200);
    mylist.Print();
    mylist.Delete(100);
    mylist.Print();
    mylist.Delete(400);
    mylist.Print();
    

    List yrlist;
    Node * n1 = new Node(1);
    Node * n2 = new Node(2);
    Node * n3 = new Node(3);
    yrlist.Append(n1);
    yrlist.Append(n2);
    yrlist.Append(n3);
    yrlist.Print();

    yrlist.Delete(n2);
    yrlist.Print();
    return 0;
}
