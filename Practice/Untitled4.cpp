#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
node*head=NULL;
void insertAtBegining(int value){
	node*newNode = new node;
	newNode->data= value;
	newNode->next=head;
	head = newNode;
}
void insertAtEnd(int value){
	node*newNode = new node;
	newNode->data=value;
	newNode->next=NULL;
	if(head==NULL){
		head=newNode;
		return;
	}
	node*temp = head;
	while(temp->next!=NULL){
	temp=temp->next;
	}
	temp->next = newNode;
	
}
void deleteatend(){
	node*temp=head;
	while(temp->next->next!=NULL){
		temp = temp->next;
		
	}
	delete temp->next;
	temp->next= NULL;
}
void display(){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data;
		temp = temp->next;
	}
}
int main(){
		insertAtBegining(30);
insertAtBegining(20);
insertAtBegining(10);
insertAtEnd(5);
deleteatend();
display();
}
