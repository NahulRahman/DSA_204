#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
};

class Stack{
public:
    Node *head;
    int SIZE;

    SIZE = 0;

    void push(int n){

    }

    void pop(){

    }

    void displaystack(){

    }
};


int main(){
    int choice=1;
    Stack stk;
    while(choice!=0)
    {

        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - Display Items."<<endl;


        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 0:
                break;

            case 1:
                int x;
                cout<<"Enter value: ";
                cin>>x;

                break;

            case 2:

                if(stk.isEmpty()==1) cout <<"Stack is Empty"<<"\n";
                else{


                }

                break;

            case 3:

                if(stk.isEmpty()==1) cout <<"Stack is Empty"<<"\n";
                else{


                }

                break;

            default:
                cout<<"An Invalid choice."<<endl;
        }

        cout<<endl<<endl;
    }


    return 0;
}
