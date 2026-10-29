#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};

int main(){
	node*head = NULL;
	node* newNode=new node;
	newNode->data=10;
	newNode->next=NULL;
	head=newNode;
	cout<<head->data;
}
