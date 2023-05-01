#include<bits/stdc++.h>
using namespace std;
int capacity;
class Node{
private:
    int val;
    Node *next;
public:
    Node(){
        next = NULL;
    }
    void setValue(int n){
        val = n;
    }
    void setValue1(Node *n){
        next = n;
    }
    int getValue(){
        return val;
    }
    Node *getValue1(){
        return next;
    }
};

class Stack{
private:
    Node *head;
    int SIZE;
public:
    Stack(int n){
        head = NULL;
        SIZE = 0;
        capacity = n;
    }
    void push(int n){
        if(isStackFull())  cout<<"Capacity full.Value cannot be inserted\n";
        else{
            Node *newitem;
            newitem = new Node;
            newitem->setValue(n);
            if(head==NULL) head = newitem;
            else{
                newitem->setValue1(head);
                head = newitem;
            }
            SIZE++;
        }
    }
    bool isStackFull(){
        if(SIZE==capacity)return 1;
        return 0;
    }
    bool isEmpty(){
        if(SIZE==0)return 1;
        return 0;
    }
    int top(){
        if(isEmpty()) return 0;
        else return head->getValue();
    }
    void pop(){
        if(isEmpty()) return;
        else{
            Node *temp;
            temp=new Node;
            temp=head;
            head=head->getValue1();
            free(temp);
            SIZE--;
        }
    }
    int size_(){
        return SIZE;
    }
    void displaystack(){
        Node *temp = head;
        while(temp!=NULL){
            cout<<temp->getValue()<<" ";
            temp = temp->getValue1();
        }
    }
};

int main(){
    int choice = 6;
    int n;
    cout<<"Capacity of the Stack: ";
    cin>>n;
    Stack s(n);
    while(choice!=0){
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - View Top Item."<<endl;
        cout<<"4 - Size of Stack."<<endl;
        cout<<"5 - Display Items (Print STACK)."<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 0:
                break;
            case 1:
            {
                int x;
                cin>>x;
                s.push(x);
                cout<<"Current Stack: \n";
                s.displaystack();
                break;
            }
            case 2:
            {
                s.pop();
                break;
            }
            case 3:
            {
                int a;
                a = s.top();
                if(a==0) cout<<"No value to show\n";
                else cout<<a<<"\n";
                break;
            }
            case 4:
            {
                int y = s.size_();
                cout<<"Size of the current stack: "<<y<<"\n";
                break;
            }
            case 5:
            {
                cout<<"Current Stack: ";
                s.displaystack();
                break;
            }
            default:
            {
                cout<<"An Invalid choice."<<endl;
            }
        }
        cout<<endl<<endl;
    }
    return 0;
}
