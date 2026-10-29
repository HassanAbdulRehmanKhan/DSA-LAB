#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
	node*prev;
};
node*head=NULL;
void insertatend(int value){
	node*newnode=new node;
	newnode->data=value;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL){
		head=newnode;
		return;
	}
	node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
}

void deleteatend(){
	if(head==NULL){
		cout<<"empty";
		return;
	}
	if(head->next==NULL){
		delete head;
		head=NULL;
		return;
		
	}
	node*temp=head;
	while(temp->next!=NULL){
	temp=temp->next;
	}
temp->prev->next=NULL;
delete temp;
	
}
void display(){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data;
		temp=temp->next;	
	}
}
int main(){
	insertatend(10);
	insertatend(20);
	insertatend(30);
	deleteatend();
	display();
}
