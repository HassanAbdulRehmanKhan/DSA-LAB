#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
	node*prev;
};
node*head =NULL;
void insertatanypoint(int value,int position){
	if(position<1){
		cout<<"invalid";
		return;
	}
	node*newnode=new node;
	newnode->data=value;
	if(position==1){
		newnode->prev=NULL;
		newnode->next=head;
		if(head!=NULL){
			head->prev=newnode;
		}
		head=newnode;
	return;
	}
	node*temp=head;
	for(int i =1;i<position-1&&temp!=NULL;i++){
		temp=temp->next;
	}
	
	if(temp==NULL){
		cout<<'invalid pos';
		return;
	}
	newnode->next=temp->next;
	newnode->prev=temp;
	if(temp->next!=NULL){
		temp->next->prev=newnode;
	}
	temp->next=newnode;
}

void display() {
    node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    insertatanypoint(50, 1);
    insertatanypoint(40, 2);
    insertatanypoint(20, 2);

    display();

    return 0;
}
