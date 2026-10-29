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
	}head=newnode;
}
void deleteatbeg(){
	if(head==NULL){
		cout<<"empty";
		return  ;
	}
	node*temp=head;
	head=head->next;
	if(head!=NULL){
		head->prev=NULL;
	}
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
	insertatbeg(500);
		insertatbeg(20);
			insertatbeg(40);
			deleteatbeg();
			display();
}
