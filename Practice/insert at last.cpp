#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
node*head=NULL;
void insertatbeg(int value){
	node*newnode=new node;
	newnode->data=value;
	newnode->next=head;
	head=newnode;
}
void insertatend(int value){
	node*newnode=new node;
	newnode->data=value;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
		return;
	}
	node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
}
void deleteatend(){
	node*temp =head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	delete temp->next;
	temp->next=NULL;
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
	insertatbeg(20);
	insertatbeg(30);
	insertatend(40);
	deleteatend();
	display();
	
}
