#include <iostream>

using namespace std;

class Node{
    int data; 
    Node* next;
public:
    Node(){};
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
    void Delete(int _data);
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
    
    mylist.Delete(300);
    mylist.Print();
    mylist.Delete(200);
    mylist.Print();
    mylist.Delete(100);
    mylist.Print();
    mylist.Delete(400);
    mylist.Print();
    
    return 0;
}
