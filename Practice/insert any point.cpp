#include<iostream>
using namespace std;
struct node{
	int data ;
	node * next;
};
node*head = NULL;
void insertatbeg(int value){
	node*newnode= new node;
	newnode->data=value;
	newnode->next=head;
	head=newnode;
}
void insertatanypoint(int value,int position){
	if(position<1){
		cout<<"invalid";
		return;
	}
	if(position==1){
		insertatbeg(value);
		return;
	}
	
	node*newnode=new node;
	newnode->data=value;
	node*temp=head;
	for(int i=1;i<position-1&&temp!=NULL;i++){
		if(temp==NULL){
			cout<<"invalid";
			return;
		}
		
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
void delatanypoint(int position){
	node*temp=head;
	if(position<1){
		cout<<"invalid";
		return;
	}
	if(position==1){
		node*temp=head;
		head=temp->next;
		delete temp;
	}
	for(int i =1;i<position-1&&temp!=NULL;i++){
		temp=temp->next;
	}
	node*delnode=temp->next;
	temp->next=delnode->next;
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
	insertatbeg(10);
	insertatbeg(20);
	insertatbeg(30);
	insertatanypoint(50,2);
	delatanypoint(3);
	display();
}
