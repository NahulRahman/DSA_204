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
    void setValue(int n)
    {
        val = n;
    }
    void setValue1(Node *n)
    {
        next = n;
    }
    int getValue()
    {
        return val;
    }
    Node *getValue1()
    {
        return next;
    }
    friend class Queue;
};

class Queue{
private:
    Node *head;
    Node *tail;
    int SIZE;
public:
    Queue(int n){
        head = NULL;
        SIZE = 0;
        capacity = n;
        tail = NULL;
    }

    void push(int n)
    {
        if(isQueueFull())
        {
           cout<<"Capacity full.Value cannot be inserted\n";
        }
        else
        {
            Node *newitem;
            newitem = new Node;
            newitem->setValue(n);
            if(head==NULL)
            {
                head = newitem;
                tail = newitem;
            }
            else
            {
                tail->setValue1(newitem);
                tail = newitem;
            }
            SIZE++;
        }


    }
    bool isQueueFull()
    {
        if(SIZE==capacity)return 1;
        return 0;
    }
    bool isEmpty(){
        if(SIZE==0)return 1;
        return 0;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty.cannot be deleted.\n";
        }
        else
        {
           Node *temp = head;
           temp = new Node;
           head = head->getValue1();
           free(temp);
           SIZE--;
        }

    }

    int size_(){
        return SIZE;
    }
    void replace_(int a,int b)
    {
        if(isEmpty())
        {
            return;
        }
        else
        {
            Node *temp = head;
            while(temp!=NULL)
            {
                if(temp->getValue()==a)
                {
                    temp->setValue(b);
                }
                temp = temp->getValue1();
            }
        }
    }
    void displayQueue(){
        Node *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->getValue()<<" ";
            temp = temp->getValue1();
        }

    }
};


int main(){
    int choice = 6;
    int n;
    cout<<"Capacity of the Queue: ";
    cin>>n;
    Queue s(n);

    while(choice!=0)
    {
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        //cout<<"3 - View Top Item."<<endl;
        cout<<"4 - Size of Queue."<<endl;
        cout<<"5 - Display Items (Print QUEUE)."<<endl;
        cout<<"6 - Replace Value\n";

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 0:
                break;

            case 1:
            {
                int x;
                cout<<"Insert Value: ";
                cin>>x;
                s.push(x);
                cout<<"Current Queue: \n";
                s.displayQueue();
                break;
            }




            case 2:
            {
                s.pop();
                cout<<"Current Queue: ";
                s.displayQueue();
                break;
            }


            /*case 3:
            {
                int a;
                a = s.top();
                if(a==0)
                {
                    cout<<"No value to show\n";
                }
                else
                {
                    cout<<a<<"\n";
                }
                break;
            }*/

            case 4:
            {
                int y = s.size_();
                cout<<"Size of the current Queue: "<<y<<"\n";
                break;
            }

            case 5:
            {
                cout<<"Current Queue: ";
                s.displayQueue();
                break;
            }
            case 6:
            {
                cout<<"Item to Replace: ";
                int a;
                cin>>a;
                cout<<"Item to Replace with: ";
                int b;
                cin>>b;
                s.replace_(a,b);
                cout<<"After Replacement: ";
                s.displayQueue();
                break;
            }

            default:
            {
                cout<<"An Invalid choice."<<endl;
            }
        }cout<<endl<<endl;
    }return 0;
}
