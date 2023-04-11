#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Node
{
    int element;
    Node *next;
};
class list_
{
    Node *head;
    Node *tail;
public:
    list_()
    {
        head = NULL;
        tail = NULL;
    }
    void insert_last(int val)
    {
        Node *new_item;
        new_item = new Node;
        new_item->element = val;
        new_item->next = NULL;
        if(head==NULL)
        {
            head = new_item;
            tail = new_item;
        }
        else
        {
            tail->next = new_item;
            tail = new_item;
        }

    }
    void insert_first(int val)
    {
        Node *new_item;
        new_item = new Node;
        new_item->element = val;
        new_item->next = NULL;
        if(head==NULL)
        {
            head = new_item;
            tail = new_item;
        }
        else
        {
            new_item->next = head;
            head = new_item;
        }

    }
    void print()
        {
            Node *current = head;
            while(current->next!=NULL)
            {
                cout<<current->element<<"\n";
                current = current->next;
            }
            cout<<current->element<<"\n";
        }
};
int main()
{
    list_ l;
    l.insert_first(10);
    l.insert_first(20);
    l.insert_first(30);
    l.print();

}
