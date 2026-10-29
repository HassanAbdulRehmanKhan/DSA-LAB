#include<iostream>
using namespace std;
struct node{
	int data;
	node*prev;
	node*next;
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
void display(){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data;
		temp = temp->next;
	}

		
	}
		int main(){
			insertatbeg(10);
		insertatbeg(30);
		display();}
