#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
node*head = NULL;
void insertbeg(int value){
	node*newNode = new node;
	newNode->data=value;
	newNode->next=head;
	head=newNode;
}
void deleteatbeg(){
	if(head==NULL){
		cout<<"invalid";
		return;
	}
	node*temp=head;
	head=head->next;
	delete temp;
}void display(){
	node*temp=head;
	while(temp!=NULL){
		cout<<temp->data;
		temp=temp->next;
	}
}
int main(){

	insertbeg(10);
	insertbeg(20);
	insertbeg(30);
	deleteatbeg();
display();
}
