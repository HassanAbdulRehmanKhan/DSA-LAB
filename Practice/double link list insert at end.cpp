#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
	node*prev;
};
node*head=NULL;
void insertatbeg(int value){
	node*newnode=new node;
	newnode->data=value;
	newnode->prev=NULL;
	newnode->next=head;
	if(head!=NULL){
		head->prev=newnode;
	}
	head=newnode;
}
void insertatend(int value){
	node*newnode=new node;
	newnode->data=value;
	newnode->next=NULL;
	if(head==NULL){
		newnode->prev=NULL;
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
void display(){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data;
		temp=temp->next;
	}
	
}
int main(){
	insertatbeg(10);
		insertatbeg(30);
	insertatend(10);
	insertatend(5);
	display();
}
