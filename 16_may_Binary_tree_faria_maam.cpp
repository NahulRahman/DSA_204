#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key,level;
    Node *left, *right, *parent;
};
Node *root;
void init(){
    root = NULL;
}

void insertRoot(int val){

    root=new Node;
    root->key=val;
    root->left=NULL  ;
    root->right=NULL;
    root->parent=NULL;

}

void insertOther(int val){

    Node *temp=root;
    Node *prev=NULL;///prev pointer is used to keep trac of previos poiter of temp
    while(temp!=NULL)
    {
        prev=temp;
        if(val<temp->key) temp=temp->left;
        else temp=temp->right;

    } ///while loop finish

    temp=new Node;
    temp->key=val;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=prev;

    if(val<prev->key) prev->left=temp;
    else prev->right=temp;

}

void insert(int val){
    if(root==NULL) insertRoot(val);
    else insertOther(val);

}

Node* findNode(int val){
    Node *temp=root;
    while(temp!=NULL)
    {
        if(temp->key==val) return temp;
        else if(val<temp->key) temp=temp->left;
        else temp=temp->right;

    }
    return temp;

}

Node* findSuccessor(Node *node){

}

void delete0Child(Node *node){

}

void delete1Child(Node *node){

}

void delete2Child(Node *node){

}

bool deleteNode(int val){

}

int main(){
    init();
    while(1){
        cout<<"1. Insert\n2. Search\n 3. Delete\n\n";
        int x;
        cin>>x;

        if(x==1){
            cout<<"Insert Value: ";
            int y;
            cin>>y;
            insert(y);
        }

        else if(x==2){
            cout<<"Enter the value you want to search ";
            int s;
            cin>>s;
            Node* t=findNode(s);
            if(t==NULL) cout<<"Not found"<<endl;
            else cout<<"Found"<<endl;
        }

        else if(x==3){
            cout<<"Delete Value: ";
            int y;
            cin>>y;
            bool b = deleteNode(y);
            if(b)   cout<<"Deleted"<<endl;
            else    cout<<y<<" not found"<<endl;
        }
    }
}
