#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
node*head = NULL;
void insertAtBegining(int value){
	node*newNode = new node;
	newNode->data=value;
	newNode->next=head;
	head=newNode;
}
void insertAtAnyPoint(int value,int position){
	
	if (position<1){
		cout<<"Invalid position!";
		return;
	}
	if(position==1){
		insertAtBegining(value);
		return;
	}
	node*newNode = new node;
	newNode->data=value;
	node*temp=head;
	for(int i =1;i<position-1&&temp!=NULL;i++){
		if(temp==NULL){
			cout<<"INVALID POSITION!";
			delete newNode;
			return;
		}
	
	}	newNode->next =temp->next;
		temp->next=newNode;
}
void deleteAtanypoint(int position){
	node*temp=head;
	if(position<1){
		cout<<"invalid ";
		return;
	}
	if(position==1){
		node*temp=head;
		head=temp->next;
		delete temp;
		
	}
	for(int i=1;i<position-1&&temp!=NULL;i++){
		temp=temp->next;
	}
	node*delnode=temp->next;
	temp->next= delnode->next;
	delete delnode;
	
	
}
void display(){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data;
		temp=temp->next;
		
	}
}
int main(){
	insertAtBegining(30);
insertAtBegining(20);
insertAtBegining(10);

insertAtAnyPoint(50,3);
deleteAtanypoint(3);
display();
}
