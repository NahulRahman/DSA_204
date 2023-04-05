#include<iostream>
#include<stdio.h>
using namespace std;
struct node{
    int data;
    node *next;
};
class list_{
    node *head;
    node *tail;
public:
    list_(){
        head=NULL;
        tail=NULL;
    }
    void insert_last(int val){
        node *newitem;
        newitem=new node; //no size needed to be given as node it self id memory
        newitem->data=val;//pointer thia kono point access korra jonno ->use kora lage. eke dot pointer bole, pointer fiels access korar jonno aita use hoi
        newitem->next=NULL;
        if(head==NULL){
            head=newitem;
            tail=newitem;
        }else{
            tail->next=newitem;
            tail=newitem;//updating tail, new item
        }
    }
    void print(){
        node *current=head;
        while(current->next!=NULL){
            cout<< current->data<<endl;
            current=current->next;
        }cout<<tail->data<<endl;
    }
};
int main(){
    list_ l;
    l.insert_last(10);
    l.insert_last(20);
    l.insert_last(30);
    l.print();
}

