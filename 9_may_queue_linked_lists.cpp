#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    struct node*next;
};
struct node*fr=0;
struct node*rear=0;
void enqueue(int x){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(fr==0&&rear==0) fr=rear=newnode;
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
void display(){
    struct node*temp;
    if(temp==0&&rear==0) cout<<"Queue is empty"<<endl;
    else{
        temp=fr;
        while(temp!=0){
            cout<<temp->data<<" "<<endl;
            temp=temp->next;
        }
    }
}
void dequeue(){
    struct node *temp;
    temp=fr;
    if(temp==0&&rear==0) cout<<"Queue is empty"<<endl;
    else{
        cout<<"the deleted element of the queue was "<<fr->data<<" "<<endl;
        fr=fr->next;
        free(temp);
    }
}
void peek(){
    struct node *temp;
    if(temp==0&&rear==0) cout<<"Queue is empty"<<endl;
    else cout<<"The front element was "<<fr->data<<endl;
}
int main(){
    enqueue(5);
    enqueue(0);
    enqueue(-3);
    display();
    dequeue();
    peek();
    return 0;
}
