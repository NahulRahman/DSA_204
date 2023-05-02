#include <bits/stdc++.h>
using namespace std;
class q
{
    int *a;
    int size, front,rear,capacity;
    public:
    q(int cap)
    {
        capacity=cap;
        a=new int (capacity);
        size=front=0;
        rear=-1;
    }
    bool isempty()
    {
        return !(size);
    }
    bool isfull()
    {
        return (size==capacity);
    }
    void enq(int x)
    {
        if(isfull())
        {
            cout<<"the queue is full.\n";
            return;
        }
        rear++;
        a[rear]=x;
        size++;
        cout << x << " enqueued successfully.\n";
    }
    void deq()
    {
        if(isempty())
        {
            cout<<"the queue is empty.\n";
        }
        else
        {
        front++;
        size--;
        cout <<"dequeued successfully.\n";
        }
    }
    void display()
    {
        if(isempty())
        {
            cout << "the queue is empty\n";
            return;
        }
        for(int i=front;i<=rear;i++)cout<< a[i] << ' ';
    }

};
int main()
{
    q a(50);
    int choice;
    while (choice != 0)
    {
        cout << "0 - Exit." << endl;
        cout << "1 - Push Item." << endl;
        cout << "2 - Pop Item." << endl;
        cout << "3 - Display Items." << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            return 0;
            break;

        case 1:
            cout << "Enter the value to insert: ";
            int x;
            cin >> x;
            a.enq(x);
            break;

        case 2:
            a.deq();
            break;

        case 3:
            cout << "The current Queue: ";
            a.display();
            break;

        default:
            cout << "An Invalid choice." << endl;
        }
        cout << endl
             << endl;
    }
    return 0;
}
