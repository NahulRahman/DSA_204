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
    if(rear==0){
        fr=rear=newnode;
        rear->next=fr;
    }else{
        rear->next=newnode;
        rear=newnode;
        rear->next=fr;
    }
}
void display(){
    struct node*temp;
    if(fr==0&&rear==0) cout<<"Queue is empty"<<endl;
    else{
        cout<<"The elements of queue are : ";
        while(temp->next!=fr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<temp->data<<" "<<endl;
    }
}
void dequeue(){
    struct node *temp;
    temp=fr;
    if(fr==0&&rear==0) cout<<"Queue is empty"<<endl;
    else if(fr==rear){
        fr=rear=0;
        free(temp);
    }else{
        fr=fr->next;
        rear->next=fr;
        free(temp);
    }
}
void peek(){
    struct node *temp;
    if(temp==0&&rear==0) cout<<"Queue is empty"<<endl;
    else cout<<"The front element was "<<fr->data<<endl;
}
int main(){
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    display();
    dequeue();
    peek();
    return 0;
}

