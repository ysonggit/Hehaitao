#include "list_node.h"

using namespace std;

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
    // if the node to be deleted is the only head node
    else if (head == _n){
	//cout<<"will delete "<<_n->GetData()<<endl;
	delete _n;
	_n = NULL;
	head = NULL;
	
    }else{
	// delete the tail node
	Node* tmp = head;
	while(tmp->GetNext() != _n){
	    tmp = tmp->GetNext();
	}
	tmp->SetNext(NULL);
	delete _n;
	_n = NULL;
    }
}

Node* List::KthNodeToTail(int k){
    if(head == NULL || k<=0 ){
	cerr<<"Empty list!"<<endl;
	return NULL;
    }
   	
    // pointer 1 goes first for k-1 steps
    Node* ptr_1 = head; 
    for(int i =0 ; i<k-1; i++){
	// since so far the list size is unknown
	// need check the list tail each step
	if(ptr_1 ->GetNext() != NULL)
	    ptr_1 = ptr_1->GetNext();
	else
	    return NULL;
	
    } // now ptr_1 points to the kth node in the list
    // create pointer 2 now, let it be the list head
    Node* ptr_2 = head;
    while(ptr_1->GetNext() != NULL){
	// two pointers go forward together
	// until ptr_1 reaches the tail node
	// ptr_2 then points the kth node to the tail
	ptr_1 = ptr_1 -> GetNext();
	ptr_2 = ptr_2 -> GetNext();
    }
    return ptr_2;
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
    Node * n4 = new Node(4);
    Node * n5 = new Node(5);
    Node * n6 = new Node(6);
    yrlist.Append(n1);
    yrlist.Append(n2);
    yrlist.Append(n3);
    yrlist.Append(n4);
    yrlist.Append(n5);
    yrlist.Append(n6);
    yrlist.Print();
    
    cout<<"the last node to the list is:\n";
    cout<<yrlist.KthNodeToTail(1)->GetData()<<endl;
    cout<<"the 3rd node to the tail is:\n";
    cout<<yrlist.KthNodeToTail(3)->GetData()<<endl;
    yrlist.Delete(n1);
    yrlist.Print();
    // for this method, since n1 is not really deleted but replaced
    yrlist.Delete(n1);
    yrlist.Print();
   
   
    return 0;
}
